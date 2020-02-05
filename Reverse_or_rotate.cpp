#include <iostream>

void rotate(char *first, char *n_first, char *last) {
  if (nullptr == first || nullptr == n_first || nullptr == last ||
      first == last) {
    return;
  }
  auto next = n_first;
  while (first != next) {
    std::swap(*first++, *next++);
    if (next == last) {
      next = n_first;
    } else if (first == n_first) {
      n_first = next;
    }
  }
}
void revers(char *begin, char *end) {
  if (nullptr == begin || nullptr == end || begin == end) {
    return;
  }
  while (begin < end) {
    int tmp = *begin;
    *begin++ = *end;
    *end-- = tmp;
  }
}

int main() {
  char arr[100]{};
  std::cout
      << "This program for reverse or rotate numbers please input numbers = ";
  std::cin >> arr;
  size_t size;
  std::cout
      << "Now let's divide our numbers into blocks, enter the block size = ";
  std::cin >> size;
  if (arr == '\0') {
    return 0;
  }
  if (size == 0) {
    return 0;
  }
  size_t length = strlen(arr);
  if (size > length) {
    std::cout << arr;
    return 0;
  }
  char *begin = arr;
  char *begin_plus = arr + 1;
  char *middle = arr + size;
  char *middle_revers = arr + (size - 1);
  char *end = arr + length;
  int count_pluse = 0, sum = 0, a = 0;
  size_t remain = length % size;
  const unsigned NUM_TWO = 2;
  for (int i = length - remain; i < length; ++i) {
    arr[i] = '\0';
  }
  length -= remain;
  for (int i = 0; i <= length; ++i) {
    if (count_pluse == size && sum % NUM_TWO == 0) {
      revers(begin + a, middle_revers + a);
      a += size;
      count_pluse = sum = 0;
    } else if (count_pluse == size && sum % NUM_TWO != 0) {
      rotate(begin + a, begin_plus + a, middle + a);
      a += size;
      count_pluse = sum = 0;
    }
    ++count_pluse;
    sum += arr[i] - '0';
  }
  std::cout << arr;
  return 0;
}
