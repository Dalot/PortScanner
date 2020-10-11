#pragma once

#include <iostream>
#include <vector>

class InputSource
{
public:
  virtual ~InputSource()
  {
  }
  virtual std::vector<int> generate_port_list(std::vector<std::string> &t_input);
  virtual std::string get_input();
};