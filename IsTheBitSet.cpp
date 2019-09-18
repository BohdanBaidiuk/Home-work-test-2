#include <iostream>
#include <limits>

int main() {

  unsigned long long number;
  const unsigned long NUMMAX = std::numeric_limits<unsigned long>::max();
  const unsigned long NUMMIN = 1;
  unsigned long bitOne = NUMMIN;
  std::cout <<"Program Is the bit set"<<
  "Enter the number from"<< NUMMIN <<" to "<< NUMMAX<<"\n";
  std::cin >> number;
  if (number >= NUMMIN && number <= NUMMAX) {
    const short BITMAX = 32;
    const short BITMIN = 1;
    std::cout << "Enter the bit from" << BITMIN << " to " << BITMAX << "\n";
    unsigned short bit;
    std::cin >> bit;
    if (bit >= BITMIN && bit <= BITMAX) {
      bitOne <<= (bit - 1);
	    (number & bitOne) == bitOne ? std::cout <<"yes\n" : std::cout <<"no\n";
    }
    else {
      std::cout << "Bit should be from "<< BITMIN <<" to "<< BITMAX;
    }
  }
  else {
    std::cout << "Wery long number or negative number or number = 0";
  }
  return 0;
}
