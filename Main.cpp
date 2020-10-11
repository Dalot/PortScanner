#include <iostream>
#include "PortScanner/PortScanner.hpp"
#include "Input/Input.hpp"

int main()
{

    Input *input = new Input();

    PortScanner *portscanner = new PortScanner(input);

    std::vector<int> ports = portscanner->parse_ports_list();

    return 0;
}