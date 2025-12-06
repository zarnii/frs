#include "ParameterParser.h"
#include <cstring>
#include <stdexcept>

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
}
