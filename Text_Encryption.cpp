#include <iostream>

void cipher(char *begin, unsigned short code) {
  while (*begin != '\0') {
    if (*begin >= 'A' && *begin <= 'Z') {
      if ((*begin + code) > 'Z') {
        *begin = (*begin + code) - 26;
      } else {
        *begin = *begin + code;
      }
    } else if (*begin >= 'a' && *begin <= 'z') {
      if ((*begin + code) > 'z') {
        *begin = (*begin + code) - 26;
      } else {
        *begin = *begin + code;
      }

    } else {
      *begin;
    }
    ++begin;
  }
}

void cipher_off(char *begin, unsigned short code) {
  while (*begin != '\0') {
    if (*begin >= 'A' && *begin <= 'Z') {
      if ((*begin - code) < 'A') {
        *begin = (*begin - code) + 26;
      } else {
        *begin = *begin - code;
      }

    } else if (*begin >= 'a' && *begin <= 'z') {
      if ((*begin - code) < 'a') {
        *begin = (*begin - code) + 26;
      } else {
        *begin = *begin - code;
      }

    } else {
      *begin;
    }
    ++begin;
  }
}

int main() {

  char text[255]{};
  std::cout << "Please enter Text for coding her = \n";
  std::cin >> text;
  char *begin = text;
  unsigned short key;
  const unsigned short min_key = 1;
  const unsigned short max_key = 25;
  do {
    std::cout << "Please input key for coding = \n";
    std::cin >> key;
    if (key >= min_key && key <= max_key) {
      break;
    }
    std::cout << "not";
  } while (true);
  cipher(begin, key);
  std::cout << text << "\n";
  key = {};
  do {
    std::cout << "Please input key for unblock coding = \n";
    std::cin >> key;
    if (key >= min_key && key <= max_key) {
      break;
    }
    std::cout << "not";
  } while (true);
  cipher_off(begin, key);
  std::cout << text;
  return 0;
}
