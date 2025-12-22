#pragma once

#include "SocketRecvConf.h"

namespace frs
{
    class SocketRecv
    {
    private:
        SocketRecvConf _config;
    public:
        SocketRecv(SocketRecvConf&& config);
        void StartListen();
        void StartRecv();
    };
}