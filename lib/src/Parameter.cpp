#include "Parameter.h"

namespace frs
{
    Parameter::Parameter(std::string paramName, std::string paramArg)
        : _paramName(paramName), _paramArg(paramArg) { }
    
    std::string& Parameter::GetParamName()
    {
        return _paramName;
    }

    std::string& Parameter::GetParamArg()
    {
        return _paramArg;
    }
}