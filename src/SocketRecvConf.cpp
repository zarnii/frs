#include "SocketRecvConf.h"

namespace frs
{
    SocketRecvConf::SocketRecvConf(std::shared_ptr<Endpoint> endpoint, 
        size_t bufferSize, size_t accpetSize)
        : _endpoint(endpoint), 
        _bufferSize(bufferSize), 
        _acceptSize(accpetSize) {}
    
    SocketRecvConf::SocketRecvConf()
        : _endpoint(nullptr),
        _bufferSize(0), 
        _acceptSize(0) { }

    const std::shared_ptr<Endpoint> SocketRecvConf::GetEndpoint()
    {
        return _endpoint;
    }

    size_t SocketRecvConf::GetBuffersize()
    {
        return _bufferSize;
    }

    size_t SocketRecvConf::GetAcceptsize()
    {
        return _acceptSize;
    }

    void SocketRecvConf::SetEndpoint(Endpoint& endpoint)
    {
        if (_endpoint == nullptr)
        {
            _endpoint = std::make_shared<Endpoint>(endpoint);
        }
        else
        {
            *_endpoint = endpoint;
        }
    }

    void SocketRecvConf::SetBufferSize(size_t bufferSize)
    {
        _bufferSize = bufferSize;
    }

    void SocketRecvConf::SetAcceptSize(size_t acceptSize)
    {
        _acceptSize = acceptSize;
    }
}