#include <iostream>
#include <array>
#include "ParameterParser.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Program did not accept any arguments" << std::endl;

        return 0;
    }


    frs::ParameterParser parser;
    frs::SocketMode mode = parser.ParseSocketMode(argv[1]);

    if (mode == frs::SocketMode::Recv)
    {
        
    }

    if (mode == frs::SocketMode::Send)
    {

    }

    return 0;
}