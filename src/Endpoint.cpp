#include "Endpoint.h"


namespace frs
{
    Endpoint::Endpoint(std::string ip, ushort port)
        : MinIpStringLength(7), 
        MaxIpStringLength(15),
        MaxOctetSize(255),
        _port(port)
    {
        if (!CheckIpStringIsCorrect(ip))
        {
            throw std::invalid_argument("ip string is invalid");
        }

        _ip = ip;
    }

    bool Endpoint::operator==(Endpoint& other)
    {
        return _ip == other._ip && _port == other._port;
    }

    bool Endpoint::CheckIpStringIsCorrect(std::string& ip)
    {
        if (!CheckIpStringLengthIsCorrect(ip))
        {
            return false;
        }
            
        if (!CheckOctetsIsCorrect(ip))
        {
            return false;
        }

        return true;
    }

    bool Endpoint::CheckIpStringLengthIsCorrect(std::string& ip)
    {
        size_t iplen = ip.length();

        if (iplen < MinIpStringLength &&
            iplen > MaxIpStringLength)
        {
            return false;
        }

        return true;
    }

    bool Endpoint::CheckOctetsIsCorrect(std::string& ip)
    {
        uint octet = 0;
        char dot = ' ';
        std::stringstream ss(ip);

        for (size_t i = 0; i < 4; i++)
        {
            ss >> octet;
            if (ss.fail())
            {
                return false;
            }

            if (octet > MaxOctetSize)
            {
                return false;
            }

            // if octet was not last
            if (i < 3)
            {
                ss >> dot;

                if (ss.fail())
                {
                    return false;
                }
            
                if (dot != '.')
                {
                    return false;
                }
            }
        }

        if (!ss.eof())
        {
            return false;
        }

        return true;
    }
}