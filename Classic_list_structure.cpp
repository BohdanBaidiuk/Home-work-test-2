#include <iostream>

struct List {
  int number;
  List *Next;
};

void push(List *&NextList, const int value) {
  List *MyList = new List;
  MyList->number = value;
  MyList->Next = NextList;
  NextList = MyList;
}

void pop(List *&NextList) {
  if(NextList==nullptr){
    return;
  }
  List *MyList = NextList;
  NextList = NextList->Next;
  delete MyList;
}

List top(List *&list) {
  if(list==nullptr){
    return 0;
  }
  int temp = list->number;
  return temp;
}

int main() {
  List *list_ = 0;
  size_t size;
  std::cout << "Please input size of Stack = ";
  std::cin >> size;
  if (size > 0) {
    std::cout << "Input number of Stack \n";
    for (int i = 0; i < size; ++i) {
      int num;
      std::cin >> num;
      push(list_, num);
    }
    for (int i = 0; i < size; ++i) {
      std::cout << std::endl;
      top(list_);
      pop(list_);
    }
  } else {
    std::cout << "Size should be more 0";
  }
  return 0;
}
