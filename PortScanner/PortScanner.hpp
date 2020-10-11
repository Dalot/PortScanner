#pragma once

#include <SFML/Network.hpp>
#include <iostream>

class PortScanner
{
public:
  PortScanner(Input *t_input);
  ~PortScanner();
  bool port_is_open(const std::string &address, int port);
  std::vector<int> parse_ports_list();

private:
  Input *m_input;
  void set_input(Input *t_input);
  std::vector<std::string> split(const std::string &string, char delimiter = ' ', bool allow_empty = false);
  static int string_to_int(const std::string &string);
};
