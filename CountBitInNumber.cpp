#include <iostream>
#include <limits>

int main() {
  unsigned num_for_bit;
  constexpr unsigned long MAX = std::numeric_limits<unsigned long>::max();
  constexpr unsigned long MIN = std::numeric_limits<unsigned long>::min();
  std::cout << "Inpute number to find out how many bits in the number\n"
               "but number should beat on the range from "
            << MIN << " to " << MAX << "\n";
  std::cin >> num_for_bit;
  if (num_for_bit > MIN && num_for_bit < MAX) {
    unsigned number = num_for_bit;
    unsigned count = 0;
    while (num_for_bit != 0) {
      count += num_for_bit & 1;
      num_for_bit >>= 1;
    }
    std::cout << "In number = " << number << " is a bit = " << count;
  } else {
    std::cout << "number should beat in the range from" << MIN << " to " << MAX;
  }
  return 0;
}
