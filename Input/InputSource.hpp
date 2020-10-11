#pragma once

#include <iostream>
#include <vector>

class InputSource
{
  public:
    virtual ~InputSource()
    {
    }
    virtual std::vector<int> get_input(const std::vector<std::string> &t_input)
};