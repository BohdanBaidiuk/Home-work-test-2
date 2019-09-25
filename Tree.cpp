#include <iostream>

int main() {
  const unsigned short MAX = 100;
  const unsigned short MIN = 3;
  std::cout << "Program for drawing Tree \n"
               "please enter number from "
            << MIN << " to " << MAX << "\n";
  unsigned short count;
  std::cin >> count;
  if (count >= MIN && count <= MAX) {
    unsigned short inHalf = count / 2;
    unsigned short start = inHalf;
    unsigned short end = inHalf;
    while (start >= 0) {
      for (unsigned short i = 0; i < start; ++i) {
        std::cout << ' ';
      }
      for (unsigned short i = start; i <= end; ++i) {
        std::cout << '*';
      }
      for (unsigned short i = end; i < count; ++i) {
        std::cout << ' ';
      }
      --start;
      ++end;
      std::cout << '\n';
    }
  } else {
    std::cout << "Range from " << MIN << " to " << MAX;
  }
  return 0;
}
