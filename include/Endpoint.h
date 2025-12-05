#include <stdexcept>
#include <string>
#include <sstream>

namespace frs
{
    class Endpoint
    {
    private:
        const u_char MinIpStringLength;
        const u_char MaxIpStringLength;
        const u_char MaxOctetSize;
        std::string _ip;
        u_short _port;

    public:
        Endpoint(std::string& ip, ushort port);
        
        bool operator==(Endpoint& other);
    private:
        bool CheckIpStringIsCorrect(std::string& ip);

        bool CheckIpStringLengthIsCorrect(std::string& ip);

        bool CheckOctetsIsCorrect(std::string& ip);
    };
}