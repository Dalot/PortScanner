#include "InputSource.hpp"
#include "Input.hpp"
#include "InputSources/ArgumentInput.hpp"
#include <sstream>

Input::Input()
{
    this->ask_for_input();
}
Input::~Input()
{
    delete this->m_input_source;
}

void Input::ask_for_input()
{
    std::string address;
    std::string port_list;
    std::vector<int> ports;
    std::cout << "Address: " << std::flush;
    std::getline(std::cin, address);
    std::cout << "Port: " << std::flush;
    std::getline(std::cin, port_list);

    const std::string new_address = address;

    this->set_address(address);
    this->set_input_source(&port_list);
}

const std::string Input::get_address()
{
    return this->m_address;
}

void Input::set_input_source(std::string *t_input)
{
    delete this->m_input_source;

    // TODO: Find type of input somehere

    this->m_input_source = new ArgumentInput(t_input);
}

void Input::set_address(const std::string t_address)
{
    this->m_address = t_address;
}

std::vector<std::string> Input::split(const std::string &string, char delimiter, bool allow_empty)
{
    std::vector<std::string> tokens;
    std::stringstream sstream(string);
    std::string token;
    while (std::getline(sstream, token, delimiter))
    {
        if (allow_empty || token.size() > 0)
            tokens.push_back(token);
    }
    return tokens;
}

std::vector<int> Input::parse_ports_list() const
{
    std::vector<int> ports;
    const std::string input = this->m_input_source->get_input();
    std::vector<std::string> tokens = split(input, ',');
    for (const std::string &token : tokens)
    {
        std::string result = this->m_input_source->get_input();
    }
    return ports;
}

int Input::string_to_int(const std::string &string)
{
    std::stringstream sstream(string);
    int i;
    sstream >> i;
    return i;
}

template <typename T>
void Input::swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

template <typename T>
std::vector<T> Input::range(T min, T max)
{
    if (min > max)
        swap(min, max);
    if (min == max)
        return std::vector<T>(1, min);
    std::vector<T> values;
    for (; min <= max; ++min)
        values.push_back(min);
    return values;
}
