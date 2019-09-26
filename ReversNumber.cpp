#include <iostream>
#include <limits>

int main() {

  long long num;
  constexpr unsigned int MAX = std::numeric_limits<unsigned int>::max();
  constexpr unsigned int MIN = std::numeric_limits<unsigned int>::min();
  std::cout << "Program for reverse numbers\n";
  std::cout << "Enter number from " << MIN << " to " << MAX << "\n";
  std::cin >> num;
  if (num >= MIN && num <= MAX) {
    unsigned int rev = 0;
    while (num != 0) {
      auto count = num % 10;
      rev = rev * 10 + count;
      num = num / 10;
    }
    std::cout << "Reverse = " << rev << "\n";
  } else {
    std::cout << "number should beat minimal = " << MIN
              << " and maximal = " << MAX << "\n";
  }
  return 0;
}
