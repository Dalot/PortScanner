#include <iostream>
#include <SFML/Network.hpp>
#include <string>

bool port_is_open(const std::string& address, int port)
{
    sf::TcpSocket socket;
    bool open = (socket.connect(sf::IpAddress(address), port) == sf::Socket::Done);
    socket.disconnect();
    return open;
}

int main(int argc, char const *argv[])
{
    std::cout << "Port 80 : ";
    if (port_is_open("localhost", 80))
        std::cout << "OPEN" << std::endl;
    else
        std::cout << "CLOSED" << std::endl;
    return 0;
}

