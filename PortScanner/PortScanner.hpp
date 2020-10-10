#pragma once 

#include <iostream>
#include <SFML/Network.hpp>


class PortScanner
{
    public:
        PortScanner();
        ~PortScanner();
        bool port_is_open(const std::string& address, int port);
        std::vector<int> parse_ports_list(const std::string& list);

    private:
        std::vector<std::string> split(const std::string& string, char delimiter = ' ', bool allow_empty = false);
        static int string_to_int(const std::string& string);
        template <typename T>
        void swap(T& a, T& b);
        template <typename T>
        std::vector<T> range(T min, T max);
};


