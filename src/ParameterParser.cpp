#include <cstring>
#include <stdexcept>
#include "ParameterParser.h"
#include <format>

namespace frs
{
    SocketMode ParameterParser::ParseSocketMode(const char* socketMode)
    {
        if (socketMode == nullptr || strlen(socketMode) == 0)
        {
            throw std::invalid_argument("socket mode is empty");    
        }

        if (!strcmp(socketMode, SOCKET_MODE_RECV_LITERAL))
        {
            return SocketMode::Recv;
        }

        if (!strcmp(socketMode, SOCKET_MODE_SEND_LITERAL))
        {
            return SocketMode::Send;
        }

        throw std::invalid_argument("socket mode is invalid");
    }

    SocketMode ParameterParser::ParseSocketMode(std::string& socketMode)
    {
        return ParseSocketMode(socketMode.c_str());
    }

    SocketRecvConf ParameterParser::CreateRecvConfByParams(size_t paramCount, char* programParams[])
    {
        /*
            1. Парсим строку параметров и создаем вектор для Parameter.
            2. Бежим по вектору и проверяем наличие всех обязательных параметров.
            3. Бежим по вектору и создаем поля для объекта SocketRecvConf.

            to-do:
                ~ Изменить метод CheckProgramParamsHasReqRecvParams так, что бы он
                  смотрел на первый символ и сравнивал его с '-'. Если первый символ - '-'
                  занчит это какой-то флаг. Затем сравнивал его со всеми флагами.
                  Если флаг незнакомый - выдавать ошибку.
                ~ Изменить метод ParseProgramRecvParams так, что бы он смотрел был ли
                  с параметром передан его аргумент. К примеру мог быть передан передан
                  параметр "-bs" без аргумента.
                  Норм строка:   "-b 127.0.0.1:5656 -bs 512"
                  Ненорм строка: "-b 127.0.0.1:5656 -bs"
        */
        if (!CheckProgramParamsHasReqRecvParams(paramCount, programParams))
        {
            throw std::invalid_argument(std::format("The program was not passed all required argumets"
                "Required argumets for \"recv\" mode: \"{}\"", B_FLAG_LITERAL));
        }

        std::vector<Parameter> params = ParseProgramRecvParams(paramCount, programParams);
        SocketRecvConf recvConf;
        
        for (Parameter& param : params)
        {
            std::string& paramName = param.GetParamName();

            if (paramName == B_FLAG_LITERAL)
            {
                Endpoint endpoint = CreateEndpointFromString(param.GetParamArg());
                recvConf.SetEndpoint(endpoint);
            }

            if (paramName == BS_FLAG_LITERAL)
            {
                size_t paramArg = static_cast<size_t>(std::stoul(param.GetParamArg()));
                recvConf.SetBufferSize(paramArg);
            }
            if (paramName == AS_FLAG_LITERAL)
            {
                size_t paramArg = static_cast<size_t>(std::stoul(param.GetParamArg()));
                recvConf.SetAcceptSize(paramArg);
            }
        }

        return recvConf;
    }

    bool ParameterParser::CheckProgramParamsHasReqRecvParams(size_t paramCount, char* programParam[])
    {
        bool bFlagIsPassed = false;

        for (size_t i = 0; i < paramCount; i++)
        {
            if (strcmp(programParam[i], B_FLAG_LITERAL) == 0)
            {
                if (bFlagIsPassed)
                {
                    throw std::invalid_argument(
                        std::format("\"{}\" was passed to program twice.", B_FLAG_LITERAL));
                }
                
                bFlagIsPassed = true;
            }
        }

        return bFlagIsPassed;
    }

    std::vector<Parameter> ParameterParser::ParseProgramRecvParams(
        size_t paramCount, 
        char* programParams[])
    {
        std::vector<Parameter> parsedParam;

        for (size_t i = 0; i < paramCount; i+=2)
        {
            char* param = programParams[i];

            if (strcmp(param, B_FLAG_LITERAL) != 0 &&
                strcmp(param, BS_FLAG_LITERAL) != 0 &&
                strcmp(param, AS_FLAG_LITERAL) != 0)
            {
                throw std::invalid_argument(
                    std::format("Invalid program arguments." 
                        "Unknow argument for recv mode: \"{}\"", param)
                );
            }

            parsedParam.push_back(
                Parameter(
                    std::string(param),
                    std::string(programParams[i+1]) // make check to array out of bounds.
                )
            );
        }

        return parsedParam;
    }

    Endpoint ParameterParser::CreateEndpointFromString(std::string endpoint)
    {
        // 127.0.0.1:5656
        size_t colonPos = endpoint.find(':');
        std::string ipStr = endpoint.substr(0, colonPos);
        std::string portStr = endpoint.substr(colonPos + 1, endpoint.length() - colonPos + 1);
        ushort port = static_cast<ushort>(std::stoul(portStr));

        return Endpoint(ipStr, port);
    }
}
