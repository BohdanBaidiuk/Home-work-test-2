#include <iostream>

enum REDACTOR {
  PRINT = 1,
  SELECT = 2,
  COPY = 3,
  PASTE = 4,
  CUT = 5,
  SHOW = 6,
  MOVE = 7,
  CLEAN = 8,
  OUT = 9
};
enum { LEFT = 1, RIGHT };

void Funck_Print(char *arg_end) {
  if (nullptr == arg_end) {
    return;
  }
  std::cout << "Print text \n";
  std::cin >> arg_end;
}

void Funck_Print_After_Move(char *begin, char *end, size_t &arg_index,
                            char *begin_tmp, size_t length_tmp) {
  if (nullptr == begin || *begin == '\0' || nullptr == end || *end != '\0' ||
      begin == end) {
    return;
  }
  if (nullptr == begin_tmp || *begin_tmp == '\0' || begin_tmp == begin ||
      begin_tmp == end) {
    return;
  }
  char *middle = begin + (arg_index);
  char *after_end = end + (length_tmp - 1);
  while (end != middle) {
    *after_end-- = *--end;
  }
  while (*begin_tmp != '\0') {
    *middle++ = *begin_tmp++;
    ++arg_index;
  }
}
void Funck_Paste(char *arg_end, char *begin_tmp) {
  if (nullptr == arg_end || nullptr == begin_tmp || *begin_tmp == '\0' ||
      arg_end == begin_tmp) {
    return;
  }
  while (*begin_tmp != '\0') {
    *arg_end++ = *begin_tmp++;
  }
}

void Funck_Select(char *begin, char *&ptr_A, char *&ptr_B, size_t length) {
  if (nullptr == begin || *begin == '\0') {
    return;
  }
  if (nullptr == ptr_A || nullptr == ptr_B) {
    return;
  }
  unsigned num_a;
  std::cout << "Inpute two num : "
            << "the first number is the beginning of the character, "
            << "the second number is the number of characters. \n";
  std::cout << "First number = ";
  std::cin >> num_a;
  if (num_a < (length - 1)) {
    unsigned num_b;
    std::cout << "Second number = ";
    std::cin >> num_b;
    if (num_b != 0 && num_b < (length - num_a)) {
      ptr_A = begin + num_a;
      ptr_B = ptr_A + (num_b - 1);
    } else {
      std::cout << "The second number is not correct \n";
    }
  } else {
    std::cout << "The first number is too large compared to the length \n";
  }
}

void Funck_Copy(char *begin, char *ptrA, char *ptrB) {
  if (nullptr == begin || nullptr == ptrA || nullptr == ptrB) {
    return;
  }
  while (ptrA <= ptrB) {
    *begin++ = *ptrA++;
  }
}

void Funck_Cut(char *begin, char *ptrA, char *ptrB, size_t &arg_index) {
  if (nullptr == begin || *begin == '\0') {
    return;
  }
  if (nullptr == ptrA || nullptr == ptrB) {
    return;
  }
  while (*begin != '\0') {
    if (begin >= ptrA) {
      *begin++ = *(++ptrB);
    } else {
      *begin++;
      --arg_index;
    }
  }
}

void Funck_Move(char *end, size_t &arg_index, size_t length) {
  if (nullptr == end) {
    return;
  }
  unsigned move_cursor;
  unsigned cursor;
  do {
    std::cout << "Please choise Left =1, or Right =2 \n";
    std::cin >> move_cursor;
    std::cout << "Inpunt number of arguments \n";
    if (move_cursor == LEFT) {
      do {
        std::cin >> cursor;
        if (cursor <= arg_index) {
          end = end - (cursor - 1);
          arg_index = arg_index - cursor;
          break;
        }
        std::cout << "Invalid arguments";
      } while (true);
      break;
    }
    if (move_cursor == RIGHT) {
      do {
        std::cin >> cursor;
        if (cursor < (arg_index - length)) {
          end = end + cursor;
          arg_index = arg_index + cursor;
          break;
        }
        std::cout << "Invalid arguments";
      } while (true);
      break;
    }
  } while (true);
}

void Funck_Length(char *arg_mass, size_t &arg_length) {
  if (nullptr == arg_mass || *arg_mass == '\0') {
    return;
  }
  arg_length = 0;
  while (arg_mass[++arg_length] != '\0') {
    ;
  }
}

void Clean_Mass(char *arg_mass) {
  if (nullptr == arg_mass || *arg_mass == '\0') {
    return;
  }
  while (*arg_mass != '\0') {
    *arg_mass++ = '\0';
  }
}

int main() {
  const size_t SIZE = 2054;
  char arr[SIZE]{};
  char arr_copy[SIZE]{};
  std::cout << "This is a text кувфсещк to get started please print text = ";
  std::cin >> arr;
  size_t length = 0, length_copy = 0;
  Funck_Length(arr, length);
  size_t index = length;
  char *begin = arr;
  char *begin_copy = arr_copy;
  char *end = arr + length;
  char *ptrA = &arr[0];
  char *ptrB = &arr[1];
  bool bool_select = false, bool_copy = false, out = true;
  unsigned choise;
  std::cout << "Please make a choise\n"
            << "print = 1,\t"
            << "select = 2,\t"
            << "copy = 3,\t"
            << "paste = 4,\n"
            << "cut = 5,\t"
            << "show = 6,\t"
            << "move = 7,\t"
            << "clean = 8,\t"
            << "out = 9\n";
  while (out) {
    std::cout << "choise you\n";
    std::cin >> choise;
    switch (REDACTOR(choise)) {
    case PRINT:
      if (index == length) {
        Funck_Print(end);
        Funck_Length(arr, length);
        index = length;
        end = arr + length;
      } else {
        std::cout << "Print text \n";
        std::cin >> arr_copy;
        Funck_Length(arr_copy, length_copy);
        Funck_Print_After_Move(begin, end, index, begin_copy, length_copy);
        Funck_Length(arr, length);
        Clean_Mass(begin_copy);
        begin = arr;
        end = arr + length;
      }
      break;
    case SELECT:
      Funck_Select(begin, ptrA, ptrB, length);
      bool_select = true;
      break;
    case COPY:
      if (bool_select) {
        Funck_Copy(begin_copy, ptrA, ptrB);
        Funck_Length(begin_copy, length_copy);
        bool_select = false;
        bool_copy = true;
      } else {
        std::cout << "First you need to select \n";
      }
      break;
    case PASTE:
      if (bool_copy) {
        if (index == length) {
          Funck_Paste(end, begin_copy);
          Funck_Length(arr, length);
          index = length;
          Clean_Mass(begin_copy);
        } else {
          Funck_Print_After_Move(begin, end, index, begin_copy, length_copy);
        }
        bool_copy = false;
      } else {
        std::cout << "First you need to copy \n";
      }
      break;
    case CUT:
      if (bool_select) {
        Funck_Cut(begin, ptrA, ptrB, index);
        Funck_Length(arr, length);
        bool_select = false;
      } else {
        std::cout << "First you need to select \n";
      }
      break;
    case SHOW:
      std::cout << "Text = " << arr << "\n";
      break;
    case MOVE:
      Funck_Move(end, index, length);
      break;
    case CLEAN:
      Clean_Mass(arr);
      length = {};
      index = length;
      break;
    case OUT:
      out = false;
      break;
    default:
      break;
    }
    std::cout << " Index = " << index << "\n";
  }
  return 0;
}
