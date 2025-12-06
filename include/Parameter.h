#pragma once

namespace frs
{
    template <typename TArgument>
    class Parameter
    {
    public:
        virtual TArgument& GetArgument() = 0;
        virtual ~Parameter() = default;
    };
}