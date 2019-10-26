#include <iostream>

enum CHOISE { UNSIGNED_TYPE = 1, DOUBLE_TYPE = 2, CHAR_TYPE };

enum { LESS = 1, MORE };

void Bubble_sort(unsigned *begin, unsigned *end, std::function<bool(int, int)> cmp) {
  if (nullptr == begin || nullptr == end || begin == end || begin == 0) {
    return;
  }
  for (auto it = begin; it != end; ++it) {
    for (auto it_next = (it + 1); it_next != end; ++it_next) {
      if (cmp(*it, *it_next)) {
        std::swap(*it, *it_next);
      }
    }
  }
}

void Bubble_sort(double *begin, double *end, std::function<bool(int, int)> cmp) {
  if (nullptr == begin || nullptr == end || begin == end || begin == 0) {
    return;
  }
  for (auto it = begin; it != end; ++it) {
    for (auto it_next = (it + 1); it_next != end; ++it_next) {
      if (cmp(*it, *it_next)) {
       std::swap(*it, *it_next);
      }
    }
  }
}

void Bubble_sort(char *begin, char *end, std::function<bool(int, int)> cmp) {
  if (nullptr == begin || nullptr == end || begin == end || begin == 0) {
    return;
  }
  for (auto it = begin; it != end; ++it) {
    for (auto it_next = (it + 1); it_next != end; ++it_next) {
      if (cmp(*it, *it_next)) {
       std::swap(*it, *it_next);
      }
    }
  }
}

void Fill_Array(unsigned *begin, unsigned *end) {
  if (nullptr == begin || nullptr == end || begin == end) {
    return;
  }
  size_t count = 0;
  while (begin != end) {
    std::cout << ++count << " = ";
    std::cin >> *begin++;
  }
}

void Fill_Array(double *begin, double *end) {
  if (nullptr == begin || nullptr == end || begin == end) {
    return;
  }
  size_t count = 0;
  while (begin != end) {
    std::cout << ++count << " = ";
    std::cin >> *begin++;
  }
}

void Fill_Array(char *begin, char *end) {
  if (nullptr == begin || nullptr == end || begin == end) {
    return;
  }
  size_t count = 0;
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
  int choise, skew;
  std::cout << "Please select the type of data to sort = \n"
            << "1 - Unsigned type \n"
            << "2 - Double type \n"
            << "3 - Char type \n";
  std::cin >> choise;
  std::cout << "Select sorting from large or from smaller \n"
            << "1 - from smaller \n"
            << "2 - from large \n";
  auto less = [](auto lh, auto rh) { return lh < rh; };
  auto more = [](auto lh, auto rh) { return lh > rh; };
  std::cin >> skew;
  if (skew == LESS) {
    break;
  } else if (skew == MORE) {
    break;
  } else {
    return 0;
  }
  switch (CHOISE(choise)) {
  case UNSIGNED_TYPE:
    Fill_Array(arr_Un, arr_Un + size);
    Bubble_sort(arr_Un, arr_Un + size, skew == LESS ? less : more);
    Print_Array(arr_Un, arr_Un + size);
    break;

  case DOUBLE_TYPE:
    Fill_Array(arr_D, arr_D + size);
    Bubble_sort(arr_D, arr_D + size, skew == LESS ? less : more);
    Print_Array(arr_D, arr_D + size);
    break;
  case CHAR_TYPE:
    Fill_Array(arr_Ch, arr_Ch + size);
    Bubble_sort(arr_Ch, arr_Ch + size, skew == LESS ? less : more);
    Print_Array(arr_Ch, arr_Ch + size);

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
