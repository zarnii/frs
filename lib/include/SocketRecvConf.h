#pragma once
#include <memory>
#include "Endpoint.h"

namespace frs
{
    class SocketRecvConf
    {
    private:
        std::shared_ptr<Endpoint> _endpoint;
        size_t _bufferSize;
        size_t _acceptSize;
    public:
        SocketRecvConf(std::shared_ptr<Endpoint> endpoint, 
            size_t bufferSize, 
            size_t accpetSize);
        SocketRecvConf();

        const std::shared_ptr<Endpoint> GetEndpoint();
        size_t GetBuffersize();
        size_t GetAcceptsize();

        void SetEndpoint(Endpoint& endpoint);
        void SetBufferSize(size_t bufferSize);
        void SetAcceptSize(size_t acceptSize);
    };
}