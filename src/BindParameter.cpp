#include "BindParameter.h"

namespace frs
{
    BindParameter::BindParameter(const Endpoint& endpoint, const std::string parameterText)
        : _argument(endpoint) 
    {
        if (parameterText.length() < 0)
        {
            throw std::invalid_argument("length of parameter's text is 0");
        }

        _parameterText = parameterText;
    }

    Endpoint BindParameter::GetArgument()
    {
        return _argument;
    }

}