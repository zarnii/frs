#pragma once
#include <string>

namespace frs
{
    class Parameter
    {
    private:
        std::string _paramName;
        std::string _paramArg;
    public:
        Parameter(std::string paramName, std::string paramArg);
        std::string& GetParamName();
        std::string& GetParamArg();
    };
}