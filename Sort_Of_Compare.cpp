#include <chrono>
#include <ctime>
#include <iostream>

void FillRandomArray(int *begin, int *end) {
  if (nullptr == begin || nullptr == end || begin == end) {
    return;
  }
  while (begin != end) {
    *begin++ = rand() % 1000 + 1;
  }
}

void PrintArray(int *begin, int *end) {
  if (nullptr == begin || nullptr == end || begin == end) {
    return;
  }
  while (begin != end) {
    std::cout << *begin++ << std::endl;
  }
}

void Bubble_Sort(int *begin, int *end, std::function<bool(int, int)> cmp) {
  if (nullptr == begin || nullptr == end || begin == end || begin == 0) {
    return;
  }
  if (nullptr == begin || nullptr == end || begin == end) {
    return;
  }
  for (auto it = begin; it != end; ++it) {
    for (auto it_next = (it + 1); it_next != end; ++it_next) {
      if (cmp(*it, *it_next)) {
        auto tmp = *it;
        *it = *it_next;
        *it_next = tmp;
      }
    }
  }
}

void Quick_Sort(int *arr, int left, int right) {
  int l = left;
  int r = right - 1;
  int size = right - left;
  if (size > 1) {
    int pivot = arr[rand() % size + l];
    while (l < r) {
      while (arr[r] > pivot && r > l) {
        r--;
      }
      while (arr[l] < pivot && l <= r) {
        l++;
      }
      if (l < r) {
        auto tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++;
      }
    }
    Quick_Sort(arr, left, l);
    Quick_Sort(arr, r, right);
  }
}

enum { LESS = 1, MORE };

int main() {

  srand(<unsigned int>(time(0)));
  int size;
  std::cout << "This program is for comparing a bubble sort and a Quick sort "
               "using a comparator \n "
            << "please enter the size of the items to sort \n ";
  std::cin >> size;
  if (size <= 0) {
    std::cout << "Invalid size";
    return 1;
  }
  int *array = new int[size];

  std::chrono::time_point<std::chrono::system_clock> start_Bubble_sort,
      end_Bubble_sotr;
  std::chrono::time_point<std::chrono::system_clock> start_Quick_sort,
      end_Quick_sotr;
  std::chrono::seconds;
  FillRandomArray(array, array + size);
  std::cout << "Please input Less = 1 or More = 2 \n";
  unsigned short choise;
  std::cin >> choise;

  if (choise == LESS) {
    start_Bubble_sort = std::chrono::system_clock::now();
    Bubble_Sort(array, array + size, [](int lh, int rh) { return lh < rh; });
    end_Bubble_sotr = std::chrono::system_clock::now();
  } else if (choise == MORE) {
    start_Bubble_sort = std::chrono::system_clock::now();
    Bubble_Sort(array, array + size, [](int lh, int rh) { return lh > rh; });
    end_Bubble_sotr = std::chrono::system_clock::now();
  } else {
    std::cout << "Sort is not imposible";
    return 0;
  }
  PrintArray(array, array + size);
  std::chrono::duration<double> elapsed_seconds_Bubble =
      end_Bubble_sotr - start_Bubble_sort;

  std::cout << "-----------------------\n";

  FillRandomArray(array, array + size);
  start_Quick_sort = std::chrono::system_clock::now();
  Quick_Sort(array, 0, size - 1);
  end_Quick_sotr = std::chrono::system_clock::now();
  PrintArray(array, array + size);
  std::chrono::duration<double> elapsed_seconds_Quick =
      end_Quick_sotr - start_Quick_sort;
  std::cout << "\n\n"
            << "Bubble sort time = " << elapsed_seconds_Bubble.count() << "\n";
  std::cout << "\n\n"
            << "Quick sort time = " << elapsed_seconds_Quick.count() << "\n";
  delete[] array;
  return 0;
}
