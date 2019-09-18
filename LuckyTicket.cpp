#include <iostream>

int main()
{
  const unsigned int MAX = 999999;
  const unsigned int MIN = 100000;
  std::cout << "To check your ticket Input 6 - number from "<< MIN <<" to "<< MAX <<"\n\n";
  unsigned int number;
  const unsigned short CYCLE = 3;
  std::cin >> number;
  unsigned num = number;
  if (number >= MIN && number <= MAX) {
    unsigned comparing_numA = 0;
    unsigned comparing_numB = 0;
    for (int i = 0; i < CYCLE; i++) {
      comparing_numA += number % 10;
      number /= 10;
    }
    for (int i = 0; i < CYCLE; i++) {
      comparing_numB += number % 10;
      number /= 10;
    }
    comparing_numA == comparing_numB ? std::cout <<"You input = "
    << num << " Your ticket is lucky\n" : std::cout << "You input = " 
    << num << " It's not your lucky day\n";
  }
  else {
    std::cout << "Number not a range from " << MIN << " to " << MAX;
  }
	return 0;
}
