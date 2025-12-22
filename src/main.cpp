#include "ParameterParser.h"
#include <iostream>

int main(int argc, char* argv[])
{
    frs::ParameterParser parser;
    frs::SocketMode sockMode = parser.ParseSocketMode("recv");

    std::cout << sockMode << std::endl;

    return 0;
}