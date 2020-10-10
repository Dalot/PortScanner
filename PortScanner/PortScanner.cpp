#include <iostream>
#include <SFML/Network.hpp>
#include "PortScanner.hpp"
#include <sstream>
#include <string>
#include <vector>

PortScanner::PortScanner() { }

bool PortScanner::port_is_open(const std::string& address, int port)
{
    return (sf::TcpSocket().connect(address, port) == sf::Socket::Done);
}

std::vector<std::string> PortScanner::split(const std::string& string, char delimiter, bool allow_empty)
{
    std::vector<std::string> tokens;
    std::stringstream sstream(string);
    std::string token;
    while (std::getline(sstream, token, delimiter)) {
        if (allow_empty || token.size() > 0)
            tokens.push_back(token);
    }
    return tokens;
}

int PortScanner::string_to_int(const std::string& string)
{
    std::stringstream sstream(string);
    int i;
    sstream >> i;
    return i;
}

template <typename T>
void PortScanner::swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

template <typename T>
std::vector<T> PortScanner::range(T min, T max)
{
    if (min > max)
        swap(min, max);
    if (min == max)
        return std::vector<T>(1, min);
    std::vector<T> values;
    for (; min <= max; ++min)
        values.push_back(min);
    return values;
}

std::vector<int> PortScanner::parse_ports_list(const std::string& list)
{
    std::vector<int> ports;
    for (const std::string& token : split(list, ',')) {
        std::vector<std::string> strrange = split(token, '-');
        switch (strrange.size()) {
        case 0: ports.push_back(string_to_int(token));       break;
        case 1: ports.push_back(string_to_int(strrange[0])); break;
        case 2:
        {
            int min = string_to_int(strrange[0]),
                max = string_to_int(strrange[1]);
            for (int port : range(min, max))
                ports.push_back(port);
            break;
        }
        default:
            break;
        }
    }
    return ports;
}
