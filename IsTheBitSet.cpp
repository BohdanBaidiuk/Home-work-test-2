#include <iostream>
#include <limits>

int main() {

  unsigned long long number;
  const unsigned long NUM_MAX = std::numeric_limits<unsigned long>::max();
  const unsigned long NUM_MIN = 1;
  std::cout << "Program Is the bit set"
            << "Enter the number from" << NUM_MIN << " to " << NUM_MAX << "\n";
  std::cin >> number;
  if (number >= NUM_MIN && number <= NUM_MAX) {
    const short BIT_MAX = 32;
    const short BIT_MIN = 1;
    std::cout << "Enter the bit from " << BIT_MIN << " to " << BIT_MAX << "\n";
    unsigned short bit;
    std::cin >> bit;
    if (bit >= BIT_MIN && bit <= BIT_MAX) {
      unsigned long bit_One = NUM_MIN;
      bit_One <<= (bit - 1);
      std::cout << ((number & bit_One) == bit_One) ? "yes\n" : "no\n";
    } else {
      std::cout << "Bit should be from " << BIT_MIN << " to " << BIT_MAX;
    }
  } else {
    std::cout << "Wery long number or negative number or number = 0";
  }
  return 0;
}
