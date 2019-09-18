#include <iostream>
#include <limits>

int main() {

  unsigned number;
  unsigned bit;
  constexpr unsigned long MAX = std::numeric_limits<unsigned long>::max();
  constexpr unsigned long MIN = std::numeric_limits<unsigned long>::min();
  std::cout << "Inpute number to find out how many bits in the number\n"
    "but number should beat on the range from "
    << MIN << " to " << MAX<<"\n";
  std::cin >> bit;
  if (bit > MIN && bit < MAX) {
    number = bit;
    unsigned count = 0;
    while (bit != 0) {
      count += bit & 1;
      bit >>= 1;
    }
      std::cout << "In number = " << number << " is a bit = " << count;
  }
  else{
    std::cout << "number should beat in the range from"<<MIN<<" to "<<MAX;
  }
  return 0;
}
