#pragma once
#include <string>
#include <vector>
#include "SocketMode.h"
#include "SocketRecvConf.h"
#include "Parameter.h"

namespace frs
{
    #define B_FLAG_LITERAL "-b"
    #define BS_FLAG_LITERAL "-bs"
    #define AS_FLAG_LITERAL "-as"

    #define B_FLAG_LITERAL_LEN 2
    #define BS_FLAG_LITERAL_LEN 3
    #define AS_FLAG_LITERAL_LEN 3

    class ParameterParser
    {
    public:
        SocketMode ParseSocketMode(const char* socketMode);
        SocketMode ParseSocketMode(std::string& socketMode);
        SocketRecvConf CreateRecvConfByParams(size_t paramCount, char* programParams[]);
    private:
        std::vector<Parameter> ParseProgramRecvParams(size_t paramCount, char* programParams[]);
        bool CheckProgramParamsHasReqRecvParams(size_t paramCount, char* programParam[]);
        Endpoint CreateEndpointFromString(std::string endpoint);
    };
}