#include <iostream>
#include <limits>

int main() {

  constexpr unsigned int MAX = std::numeric_limits<unsigned short>::max();
  constexpr unsigned int MIN = std::numeric_limits<unsigned short>::min();
  std::cout << "If you want to build a new number\n"
    << "please enter three numbers A, B, C \n"
    <<"numbers should be from"
    << MIN<<" to "<<MAX<<"\n";
  unsigned int num_A;
  std::cout << "Input number A\n";
  std::cin >> num_A;
  if (num_A >= MIN && num_A <= MAX) {
    std::cout << "Input number B\n";
    unsigned int num_B;
    std::cin >> num_B;
    if (num_B >= MIN && num_B <= MAX) {
      std::cout << "Input number C\n";
      unsigned int num_C;
      std::cin >> num_C;
      if (num_C >= MIN && num_C <= MAX) {
        auto new_num = num_A * 10000 + num_B * 1000 + num_C * 100;
        std::cout << "This number " << new_num << " is " << new_num % 3 == 0 ? " " : "not " << "divided by 3 \n";
      }else {
        std::cout << "Number C not range ";
      }
    }else {
      std::cout << "Number B not range ";
    }
  }else {
    std::cout << "Number A not range ";
  }
  return 0;
}
