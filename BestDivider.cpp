#include <iostream>
#include <limits>

int main(int argc, char const* argv[]) {
  unsigned int number;
  constexpr unsigned int MAX = std::numeric_limits<unsigned int>::max();
  constexpr unsigned int MIN = std::numeric_limits<unsigned int>::min();
  std::cout << "Input number from "
    <<MIN<<" to "<<MAX<<
    " to findt best divider = \n";
  do {
    std::cin >> number;
    if (number > MIN && number < MAX) {
      break;
    }
    else {
      std::cout << "Range should be from" << MIN << " to " << MAX<<"\n";
    }
  } while (true);

  unsigned int sum;
  unsigned int max_num_big_10 = 0;
  unsigned int max_num_low_10 = 0;
  unsigned int tmp;
  unsigned int tmp_two;
  for (unsigned int i = number; i > 0; --i) {
    if (number % i == 0) {
      tmp = i;
      sum = 0;
      if (tmp >= 10) {
        while (tmp > 0) {
          sum += tmp % 10;
          tmp /= 10;
        }
        if (sum > max_num_big_10) {
          max_num_big_10 = sum;
          tmp_two = i;
        }
      } else {
        if (tmp > max_num_low_10) {
          max_num_low_10 = tmp;
        }
      }
    }
  }
  if (max_num_big_10 > max_num_low_10) {
    std::cout<<"Best diliver == " << tmp_two <<" because sum == "<< max_num_big_10;
  }
  else if (max_num_big_10 < max_num_low_10) {
    std::cout << "Best diliver == " << max_num_low_10;
  }
  else if (max_num_big_10 == max_num_low_10) {
    std::cout << "Best diliver == " << tmp_two << " == " << max_num_low_10;
  }
  return 0;
}
