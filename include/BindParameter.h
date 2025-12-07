#pragma once
#include "Parameter.h"
#include "Endpoint.h"

namespace frs
{
    class BindParameter: public Parameter
    {
    private:
        Endpoint _argument;
        std::string _parameterText;

    public:
        BindParameter(const Endpoint& endpoint, const std::string parameterText);

        Endpoint GetArgument();
    };
}