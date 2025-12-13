#include <iostream>
#include <array>
#include "ParameterParser.h"

int main(int argc, char* argv[])
{
    /*
    if (argc < 2)
    {
        std::cout << "Program did not accept any arguments" << std::endl;

        return 0;
    }
    */

    char** programParam = (static_cast<char**>(argv)) + 2;
    frs::ParameterParser parser;
    frs::SocketRecvConf config = parser.CreateRecvConfByParams(argc - 2, programParam);

    return 0;
}