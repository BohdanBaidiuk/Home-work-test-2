#include <iostream>
#include <limits>

int main() {

  long long num;
  constexpr long MAX = std::numeric_limits<long>::max();
  constexpr long MIN = std::numeric_limits<long>::min();
  std::cout << "Program for reverse numbers\n";
  std::cout << "Enter number from "<< MIN <<" to "<< MAX <<"\n";
  std::cin >> num;
  if (num >= MIN && num <= MAX) {
    long rev = 0;
    while (num != 0){
    long count;
    count = num % 10;
    rev = rev * 10 + count;
    num = num / 10;
    }
    std::cout << "Reverse = " << rev << "\n";
  }
  else {
    std::cout << "number should beat minimal = " << MIN << " and maximal = " << MAX << "\n";
  }
  return 0;
}
