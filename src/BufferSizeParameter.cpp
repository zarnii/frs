#include "BufferSizeParameter.h"

namespace frs
{
    BufferSizeParameter::BufferSizeParameter(size_t size)
        : _size(size) {}
    
    size_t BufferSizeParameter::GetArgument()
    {
        return _size;
    }
}