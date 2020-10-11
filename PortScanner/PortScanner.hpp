#pragma once

#include <SFML/Network.hpp>
#include <iostream>

class PortScanner
{
  public:
    PortScanner(const Input *t_input);
    ~PortScanner();
    bool port_is_open(const std::string &address, int port);
    std::vector<int> parse_ports_list(ArgumentInput &list);

  private:
    Input *m_input;
    void set_input(const Inpute *t_input);
    std::vector<std::string> split(const std::string &string, char delimiter = ' ', bool allow_empty = false);
    static int string_to_int(const std::string &string);
    template <typename T>
    void swap(T &a, T &b);
    template <typename T>
    std::vector<T> range(T min, T max);
};
