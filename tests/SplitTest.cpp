#include "gtest/gtest.h"
#include "../PortScanner/PortScanner.hpp"

// Tests that the PortScanner::split() method splits port ranges.
TEST(SplitTest, ItSplitsInputProperly) {
  const std::string input = "80-82";
  PortScanner* portScanner = new PortScanner();
  std::vector<int> vec = {80,81,82};
  EXPECT_EQ(portScanner->parse_ports_list(input), vec);
}