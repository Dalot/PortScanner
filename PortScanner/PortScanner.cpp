#include "PortScanner.hpp"
#include "../Input/Input.hpp"
#include "../Input/InputSources/ArgumentInput.hpp"
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include <vector>

PortScanner::PortScanner(Input *t_input = nullptr)
{
    this->set_input(t_input);
}

PortScanner::~PortScanner()
{
    delete this->m_input;
}

void PortScanner::set_input(Input *t_input)
{
    this->m_input = t_input;
}

bool PortScanner::port_is_open(const std::string &address, int port)
{
    return (sf::TcpSocket().connect(address, port) == sf::Socket::Done);
}

std::vector<int> PortScanner::parse_ports_list()
{
    std::vector<int> ports = this->m_input->parse_ports_list();
    std::string address = this->m_input->get_address();
    std::cout << "Scanning " << address << "...\n";
    for (int port : ports)
    {
        std::cout << "Port " << port << " : ";
        if (this->port_is_open(address, port))
            std::cout << "OPEN\n";
        else
            std::cout << "CLOSED\n";
    }
    std::cout << std::flush;
}
