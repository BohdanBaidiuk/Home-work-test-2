#include <iostream>

enum CHOISE { UNSIGNED_TYPE = 1, DOUBLE_TYPE = 2, CHAR_TYPE };

enum { LESS = 1, MORE };

typedef bool (*Compare)(unsigned, unsigned);
void Bubble_sort(unsigned *begin, unsigned *end, Compare cmp) {
  if (nullptr == begin || nullptr == end || begin == end || begin == 0) {
    return;
  }
  for (--end; begin < end; ++begin) {
    for (unsigned *end_copy = end; end_copy > begin; end_copy--) {
      if (cmp(*end_copy, *begin)) {
        unsigned tmp = *end_copy;
        *end_copy = *begin;
        *begin = tmp;
      }
    }
  }
}

typedef bool (*CompareD)(double, double);
void Bubble_sort(double *begin, double *end, CompareD cmp) {
  if (nullptr == begin || nullptr == end || begin == end || begin == 0) {
    return;
  }
  for (--end; begin < end; ++begin) {
    for (double *end_copy = end; end_copy > begin; end_copy--) {
      if (cmp(*end_copy, *begin)) {
        double tmp = *end_copy;
        *end_copy = *begin;
        *begin = tmp;
      }
    }
  }
}

typedef bool (*CompareCh)(char, char);
void Bubble_sort(char *begin, char *end, CompareCh cmp) {
  if (nullptr == begin || nullptr == end || begin == end || begin == 0) {
    return;
  }
  for (--end; begin < end; ++begin) {
    for (char *end_copy = end; end_copy > begin; end_copy--) {
      if (cmp(*end_copy, *begin)) {
        char tmp = *end_copy;
        *end_copy = *begin;
        *begin = tmp;
      }
    }
  }
}

void Fill_Array(unsigned *begin, unsigned *end) {
  if (nullptr == begin || nullptr == end || begin == end) {
    return;
  }
  unsigned count = 0;
  while (begin != end) {
    std::cout << ++count << " = ";
    std::cin >> *begin++;
  }
}

void Fill_Array(double *begin, double *end) {
  if (nullptr == begin || nullptr == end || begin == end) {
    return;
  }
  unsigned count = 0;
  while (begin != end) {
    std::cout << ++count << " = ";
    std::cin >> *begin++;
  }
}

void Fill_Array(char *begin, char *end) {
  if (nullptr == begin || nullptr == end || begin == end) {
    return;
  }
  unsigned count = 0;
  while (begin != end) {
    std::cout << ++count << " = ";
    std::cin >> *begin++;
  }
}

void Print_Array(unsigned *begin, unsigned *end) {
  if (nullptr == begin || nullptr == end || begin == end) {
    return;
  }
  while (begin != end) {
    std::cout << *begin++ << " ";
  }
}

void Print_Array(double *begin, double *end) {
  if (nullptr == begin || nullptr == end || begin == end) {
    return;
  }
  while (begin != end) {
    std::cout << *begin++ << " ";
  }
}

void Print_Array(char *begin, char *end) {
  if (nullptr == begin || nullptr == end || begin == end) {
    return;
  }
  while (begin != end) {
    std::cout << *begin++ << " ";
  }
}

int main() {
  size_t size;
  std::cout << "This program for docking different types \n"
            << "Please enter the size of our array = \n";
  std::cin >> size;
  unsigned *arr_Un = new unsigned[size];
  double *arr_D = new double[size];
  char *arr_Ch = new char[size];
  unsigned *begin_Un = arr_Un;
  unsigned *end_Un = arr_Un + size;
  double *begin_D = arr_D;
  double *end_D = arr_D + size;
  char *begin_Ch = arr_Ch;
  char *end_Ch = arr_Ch + size;
  auto less = [](auto lh, auto rh) { return lh < rh; };
  auto more = [](auto lh, auto rh) { return lh > rh; };
  int choise, skew;
  std::cout << "Please select the type of data to sort = \n"
            << "1 - Unsigned type \n"
            << "2 - Double type \n"
            << "3 - Char type \n";
  std::cin >> choise;
  std::cout << "Select sorting from large or from smaller \n"
            << "1 - from smaller \n"
            << "2 - from large \n";
  do {
    std::cin >> skew;
    if (skew == LESS) {
      break;
    } else if (skew == MORE) {
      break;
    }
    std::cout << "Tray agein \n";
  } while (true);
  switch (CHOISE(choise)) {
  case UNSIGNED_TYPE:
    Fill_Array(begin_Un, end_Un);
    if (skew == LESS) {
      Bubble_sort(begin_Un, end_Un, less);
    } else if (skew == MORE) {
      Bubble_sort(begin_Un, end_Un, more);
    }
    Print_Array(begin_Un, end_Un);
    break;

  case DOUBLE_TYPE:
    Fill_Array(begin_D, end_D);
    if (skew == LESS) {
      Bubble_sort(begin_D, end_D, less);
    } else if (skew == MORE) {
      Bubble_sort(begin_D, end_D, more);
    }
    Print_Array(begin_D, end_D);
    break;
  case CHAR_TYPE:
    Fill_Array(begin_Ch, end_Ch);
    if (skew == LESS) {
      Bubble_sort(begin_Ch, end_Ch, less);
    } else if (skew == MORE) {
      Bubble_sort(begin_Ch, end_Ch, more);
    }
    Print_Array(begin_Ch, end_Ch);

    break;
  default:
    std::cout << "Wrong vibe, try again";
    break;
  }
  delete[] arr_Un;
  delete[] arr_D;
  delete[] arr_Ch;
  return 0;
}
