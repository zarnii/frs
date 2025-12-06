#pragma once
#include <string>
#include <vector>
#include "SocketMode.h"
#include "Parameter.h"

namespace frs
{
    class ParameterParser
    {
    public:
        SocketMode ParseSocketMode(const char* socketMode);
        SocketMode ParseSocketMode(std::string& socketMode);
    };
}