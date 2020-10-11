#include "InputSource.hpp"

class Input
{

  private:
    InputSource *m_input_source;

  public:
    Input(InputSource *t_input_source = nullptr)
    {
        this->set_input_source(t_input_source);
    }
    ~Input()
    {
        delete this->m_input_source;
    }

    void set_input_source(InputSource *t_input_source)
    {
        delete this->m_input_source;
        this->m_input_source = t_input_source;
    }

    void parse_ports_list() const
    {
        std::vector<int> ports;
        for (const std::string &token : split(list, ','))
        {
            std::string result = this->m_input_source->get_input(std::vector<std::string>{"a", "e", "c", "b", "d"});
        }
        return ports;
    }
};