#include "../InputSource.hpp"
#include <iostream>
#include "../InputSource.hpp"

class ArgumentInput : public InputSource
{
private:
  std::string *m_input;

public:
  ArgumentInput(std::string *t_argument_port_list);
  ~ArgumentInput();
  std::string ArgumentInput::get_input();
  virtual std::vector<int> generate_port_list(std::vector<std::string> &t_input);
  virtual std::string ArgumentInput::get_input();
};

ArgumentInput::ArgumentInput(std::string *t_argument_port_list)
{
  this->m_input = t_argument_port_list;
}

ArgumentInput::~ArgumentInput()
{
  delete this->m_input;
}

std::vector<int> ArgumentInput::generate_port_list(std::vector<std::string> &t_input)
{
}

std::string ArgumentInput::get_input()
{
  return *this->m_input;
}
