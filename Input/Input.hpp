#include "InputSource.hpp"

class Input
{

  private:
    InputSource *m_strategy;

  public:
    Input(InputSource *t_strategy = nullptr);
    ~Input();

    void set_strategy(InputSource *t_strategy);

    void transform_input() const;
};