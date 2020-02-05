#include <iostream>

void cipher(char *begin, unsigned short code) {
  while (*begin != '\0') {
    if (*begin >= 'A' && *begin <= 'z') {
      *begin = *begin + code;
    }
    ++begin;
  }
}

void cipher_off(char *begin, unsigned short code) {
  while (*begin != '\0') {
    *begin = *begin - code;
    ++begin;
  }
}

int main() {

  char text[255]{};
  std::cout << "Please enter Text for coding her = \n";
  std::cin >> text;
  unsigned short key;
  const unsigned short MIN_KEY = 1;
  const unsigned short MAX_KEY = 111;
  do {
    std::cout << "Please input key for coding = \n";
    std::cin >> key;
    if (key >= MIN_KEY && key <= MAX_KEY) {
      break;
    }
    std::cout << "not";
  } while (true);
  cipher(text, key);
  std::cout << text << "\n";
  key = 0;
  do {
    std::cout << "Please input key for unblock coding = \n";
    std::cin >> key;
    if (key >= MIN_KEY && key <= MAX_KEY) {
      break;
    }
    std::cout << "not";
  } while (true);
  cipher_off(text, key);
  std::cout << text;
  return 0;
}
