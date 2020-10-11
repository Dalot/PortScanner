#include "../InputSource.hpp"
#include <iostream>

class ArgumentInput : InputSource
{
  private:
    std::string m_input;

  public:
    ArgumentInput();
    ~ArgumentInput();
};

ArgumentInput::ArgumentInput()
{
}

ArgumentInput::~ArgumentInput()
{
}
