#include "InputSource.hpp"

class Input
{

private:
  InputSource *m_input_source;
  std::string m_address;

  std::vector<std::string> split(const std::string &string, char delimiter = ' ', bool allow_empty = false);
  static int string_to_int(const std::string &string);
  template <typename T>
  void swap(T &a, T &b);
  template <typename T>
  std::vector<T> range(T min, T max);
  void set_input_source(std::string *t_input);
  void set_address(const std::string t_address);
  void ask_for_input();

public:
  Input();
  ~Input();

  void set_strategy(InputSource *t_strategy);
  const std::string get_address();

  std::vector<int> parse_ports_list() const;
};