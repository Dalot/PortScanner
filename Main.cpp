#include <iostream>
#include "PortScanner/PortScanner.hpp"

int main()
{
    PortScanner *portscanner = new PortScanner();
    std::string address;
    std::string port_list;
    std::vector<int> ports;
    std::cout << "Address: " << std::flush;
    std::getline(std::cin, address);
    std::cout << "Port: " << std::flush;
    std::getline(std::cin, port_list);

    ports = portscanner->parse_ports_list(port_list);
    std::cout << "Scanning " << address << "...\n";
    for (int port : ports)
    {
        std::cout << "Port " << port << " : ";
        if (portscanner->port_is_open(address, port))
            std::cout << "OPEN\n";
        else
            std::cout << "CLOSED\n";
    }
    std::cout << std::flush;
    return 0;
}