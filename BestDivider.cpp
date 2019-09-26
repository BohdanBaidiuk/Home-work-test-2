#include <iostream>
#include <limits>

int main(int argc, char const *argv[]) {
  unsigned int number;
  constexpr unsigned int MAX = std::numeric_limits<unsigned int>::max();
  constexpr unsigned int MIN = std::numeric_limits<unsigned int>::min();
  std::cout << "Input number from " << MIN << " to " << MAX
            << " to findt best divider = \n";
  do {
    std::cin >> number;
    if (number > MIN && number < MAX) {
      break;
    } else {
      std::cout << "Range should be from" << MIN << " to " << MAX << "\n";
    }
  } while (true);

  unsigned int max_num_big_10 = 0;
  unsigned int max_num_low_10 = 0;
  unsigned int num_first = 0;
  unsigned int num_second = 0;
  for (unsigned int i = number; i > 0; --i) {
    if (number % i == 0) {
      unsigned int sum {};
      num_first = i;
      if (num_first >= 10) {
        while (num_first > 0) {
          sum += num_first % 10;
          num_first /= 10;
        }
        if (sum > max_num_big_10) {
          max_num_big_10 = sum;
          num_second = i;
        }
      } else {
        if (num_first > max_num_low_10) {
          max_num_low_10 = num_first;
        }
      }
    }
  }
  if (max_num_big_10 > max_num_low_10) {
    std::cout << "Best diliver == " << num_second
              << " because sum == " << max_num_big_10;
  } else if (max_num_big_10 < max_num_low_10) {
    std::cout << "Best diliver == " << max_num_low_10;
  } else if (max_num_big_10 == max_num_low_10) {
    std::cout << "Best diliver == " << num_second << " == " << max_num_low_10;
  }
  return 0;
}
