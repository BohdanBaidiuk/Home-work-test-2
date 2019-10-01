#include <iostream>

enum { DELTA = 32 };

void Find_Diget(char *begin) {
  if (nullptr == begin && *begin == '\0') {
    return;
  }
  bool is_digit_present = false;
  while (*begin != '\0') {
    if (*begin >= '0' && *begin <= '9') {
      is_digit_present = true;
      break;
    }
    ++begin;
  }
  if (is_digit_present) {
    std::cout << "Is Digit = ";
    while (*begin != '\0') {
      auto ch = *begin;
      if (ch >= '0' && ch <= '9') {
        std::cout << ch;
      }
      ++begin;
    }
  } else {
    std::cout << "No digits in string \n";
  }
}

void To_Upper(char *begin) {
  if (nullptr == begin && *begin == '\0') {
    return;
  }
  while (*begin != '\0') {
    if (*begin >= 'a' && *begin <= 'z') {
      auto temp = *begin - DELTA;
      std::cout << (char)temp;
    } else {
      std::cout << *begin;
    }
    ++begin;
  }
}

void To_lower(char *begin) {
  if (nullptr == begin && *begin == '\0') {
    return;
  }
  while (*begin != '\0') {
    if (*begin >= 'A' && *begin <= 'Z') {
      auto temp = *begin + DELTA;
      std::cout << (char)temp;
    } else {
      std::cout << *begin;
    }
    ++begin;
  }
}

void Revers_String(char *begin, char *end) {
  if (begin == nullptr && end != nullptr && begin != end) {
    return;
  }
  while (begin < end) {
    char tmp = *begin;
    *begin = *end;
    *end = tmp;
    ++begin;
    --end;
  }
}

enum ChoiseFunc { FIND = 1,
                 UPPER = 2,
                 LOWER = 3,
                 REVERS = 4
                };

int main() {
  std::cout << "In this program you can = \n"
               "-Find number in string \n"
            << "-Upper case conversion \n"
            << "-Lower case conversion \n"
            << "-Revers for string \n";
  const unsigned SIZE = 255;
  char symbol[SIZE];
  std::cout << "Enter STRING = ";
  std::cin >> symbol;
  size_t length = 0;
  while (symbol[++length] != '\0') {
    ;
  }
  char *begin = symbol;
  char *end = &symbol[length - 1];
  if (length <= SIZE) {
    std::cout << "Select a function by the following commands : \n";
    std::cout << "---1 = Find number\n"
              << "---2 = Upper case \n"
              << "---3 = Lower case \n"
              << "---4 = Revers \n\n";
    unsigned short choice;
    std::cin >> choice;
    switch (ChoiseFunc(choice)) {
    case FIND:
      Find_Diget(symbol);
      break;
    case UPPER:
      To_Upper(symbol);
      break;
    case LOWER:
      To_lower(symbol);
      break;
    case REVERS:
      Revers_String(symbol, end);
      std::cout << symbol;
      break;
    default:
      std::cout << "UNDEFINED CHOICE";
      break;
    }
  } else {
    std::cout << "String  very long for program!!!";
  }
  return 0;
}
