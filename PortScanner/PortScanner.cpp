#include "PortScanner.hpp"
#include "../Input/Input.hpp"
#include "../Input/InputSources/ArgumentInput.hpp"
#include <SFML/Network.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

PortScanner::PortScanner(const Input *t_input = nullptr)
{
    this->set_input(t_input);
}

void PortScanner::set_input(const Input *t_input)
{
    delete this->m_input;
    this->m_input = t_input;
}

bool PortScanner::port_is_open(const std::string &address, int port)
{
    return (sf::TcpSocket().connect(address, port) == sf::Socket::Done);
}

std::vector<std::string> PortScanner::split(const std::string &string, char delimiter, bool allow_empty)
{
    std::vector<std::string> tokens;
    std::stringstream sstream(string);
    std::string token;
    while (std::getline(sstream, token, delimiter))
    {
        if (allow_empty || token.size() > 0)
            tokens.push_back(token);
    }
    return tokens;
}

int PortScanner::string_to_int(const std::string &string)
{
    std::stringstream sstream(string);
    int i;
    sstream >> i;
    return i;
}

template <typename T>
void PortScanner::swap(T &a, T &b)
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

std::vector<int> PortScanner::parse_ports_list(InputSource &list)
{
    m_input->parse_ports_list(&list);
}
