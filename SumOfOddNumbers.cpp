#include <iostream>

int main() {

  const unsigned short MINSIZE = 1;
  const unsigned short MAXSIZE = 50;
  std::cout << "Enter the number of input elements from "
            << MINSIZE << " to " << MAXSIZE << "\n";
  unsigned short size;
  std::cin >> size;
  if (size >= MINSIZE && size <= MAXSIZE) {
    long sum = 0;
    const short MINRANGE = -60;
    const short MAXRENGE = 90;
    std::cout << "Enter numbers from " << MINRANGE << " to " << MAXRENGE
              << "\n";
    while (size > 0) {
      long long number;
      std::cin >> number;
      if (number >= MINRANGE && number <= MAXRENGE) {
        if (number % 2 != 0) {
          sum += number;
        }
        --size;
      }
    }
    std::cout << "Sum of odd numbers = " << sum;
  } else {
    std::cout << "Range should beat from " << MINSIZE << " to " << MAXSIZE
              << "\n";
  }
  return 0;
}
