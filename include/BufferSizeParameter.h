#pragma once
#include "Parameter.h"
#include <cstddef>

namespace frs
{
    class BufferSizeParameter: public Parameter
    {
    private:
        size_t _size;
    public:
        BufferSizeParameter(size_t size);
        
        size_t GetArgument();
    };
}