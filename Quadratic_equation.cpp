#include <iostream> 
#include <cmath> 
#include <limits>

int main(int argc, char const *argv[]) {
  long long  a, b, c;
  constexpr int MAX = std::numeric_limits<short>::max();
  constexpr int MIN = std::numeric_limits<short>::min();
  std::cout << "Please enter number = a,b,c- in the range = from " << MIN << " to " << MAX << " To solve the square equation\n";
  std::cin >> a;
  if (a != 0 && a >= MIN && a <= MAX) {
    std::cin >> b;
    if (b >= MIN && b <= MAX) {
      std::cin >> c;
      if (c >= MIN && c <= MAX) {
        const unsigned NUM_FOUR = 4;
        const unsigned NUM_TWO = 2;
        auto COUNT_2_A = NUM_TWO * a;
        auto  d = std::pow(b, 2) - NUM_FOUR * a * c;
        if (d > 0) {
          std::cout << "Since the discriminant is greater than zero, the quadratic equation has two real roots:\n";
          auto  desk = std::sqrt(d);
          auto  x1 = (-b - desk) / (COUNT_2_A);
          auto  x2 = (-b + desk) / (COUNT_2_A);
          std::cout << "x1 = " << x1 << "\n" << "x2 = " << x2 << "\n";
        }
        else if (d == 0) {
          std::cout << "Since the discriminant is zero, the quadratic equation has one real root:\n";
          auto x = (-b) / COUNT_2_A;
          std::cout << "x = " << x << "\n";
        }
        else if (d < 0) {
          std::cout << "Since the discriminant is less than zero, the equation has no real solutions.\n";
        }
      }
      else {
        std::cout << "Number = c  must beat from " << MIN << " to " << MAX << "\n";
      }
    }
    else {
     std::cout << "Number = b  must beat from " << MIN << " to " << MAX<<"\n";
    }
  }
  else {
    std::cout << "Number = a must beat not 0,and must beat from " << MIN << " to " << MAX;
  }
  return 0;
}
