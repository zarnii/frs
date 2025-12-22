#pragma once

namespace frs
{
    #define SOCKET_MODE_RECV_LITERAL "recv"
    #define SOCKET_MODE_SEND_LITERAL "send"

    enum SocketMode
    {
        Recv,
        Send
    };
}