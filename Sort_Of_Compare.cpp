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
    std::cout << *begin++ << " ";
  }
}

typedef bool (*Compare)(int, int);

void Bubble_Sort(int *begin, int *end, Compare cmp) {
  if (nullptr == begin || nullptr == end || begin == end || begin == 0) {
    return;
  }
  if (nullptr == begin || nullptr == end || begin == end) {
    return;
  }
  for (--end; begin < end; ++begin) {
    for (auto *end_copy = end; end_copy > begin; end_copy--) {
      if (cmp(*end_copy, *begin)) {
        int tmp = *end_copy;
        *end_copy = *begin;
        *begin = tmp;
      }
    }
  }
}

void Quick_Sort(int *numbers, int left, int right) {
  int pivot;
  int l_hold = left;
  int r_hold = right;
  pivot = numbers[left];
  while (left < right) {
    while ((numbers[right] >= pivot) && (left < right))
      right--;
    if (left != right) {
      numbers[left] = numbers[right];
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++;
    if (left != right) {
      numbers[right] = numbers[left];
      right--;
    }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)
    Quick_Sort(numbers, left, pivot - 1);
  if (right > pivot)
    Quick_Sort(numbers, pivot + 1, right);
}

enum { LESS = 1,
       MORE
     };

int main() {

  srand(static_cast<unsigned int>(time(0)));
  int size;
  std::cout << "This program is for comparing a bubble sort and a Quick sort using a comparator \n "
            <<"please enter the size of the items to sort \n "
  std::cin >> size;
  if (size <= 0) {
    std::cout << "Invalid size";
    return 1;
  }
  int *bubble_arr = new int[size];
  int *begin = bubble_arr;
  int *end = bubble_arr + size;

  int *quick_arr = new int[size];
  int *begin_quick = quick_arr;
  int *end_quick = quick_arr + size;

  auto less = [](int lh, int rh) { return lh < rh; };
  auto more = [](int lh, int rh) { return lh > rh; };
  std::chrono::time_point<std::chrono::system_clock> start_Bubble_sort,
      end_Bubble_sotr;
  std::chrono::time_point<std::chrono::system_clock> start_Quick_sort,
      end_Quick_sotr;
  std::chrono::seconds;

  FillRandomArray(begin, end);

  std::cout << "Please input Less = 1 or More = 2 \n";
  unsigned short choise;
  std::cin >> choise;

  if (choise == LESS) {
    start_Bubble_sort = std::chrono::system_clock::now();
    Bubble_Sort(begin, end, less);
    end_Bubble_sotr = std::chrono::system_clock::now();
  } else if (choise == MORE) {
    start_Bubble_sort = std::chrono::system_clock::now();
    Bubble_Sort(begin, end, more);
    end_Bubble_sotr = std::chrono::system_clock::now();
  } else {
    std::cout << "Sort is not imposible";
    return 1;
  }
  PrintArray(begin, end);
  std::chrono::duration<double> elapsed_seconds_Bubble =
      end_Bubble_sotr - start_Bubble_sort;

  std::cout << "-----------------------\n";

  FillRandomArray(begin_quick, end_quick);
  start_Quick_sort = std::chrono::system_clock::now();
  Quick_Sort(quick_arr, 0, size - 1);
  end_Quick_sotr = std::chrono::system_clock::now();
  PrintArray(begin_quick, end_quick);
  std::chrono::duration<double> elapsed_seconds_Quick =
      end_Quick_sotr - start_Quick_sort;

  std::cout << "\n\n"
            << "Bubble sort time = " << elapsed_seconds_Bubble.count() << "\n";

  std::cout << "\n\n"
            << "Quick sort time = " << elapsed_seconds_Quick.count() << "\n";
  delete [] bubble_arr;
  delete [] quick_arr;
  return 0;
}
