#include <iostream>

struct Stack {
  int number;
  Stack *Next;
};

void push(Stack *&NextStack, const int value) {
  Stack *MyStack = new Stack;
  MyStack->number = value;
  MyStack->Next = NextStack;
  NextStack = MyStack;
}

void pop(Stack *&NextStack) {
  Stack *MyStack = NextStack;
  NextStack = NextStack->Next;
  delete MyStack;
}

void top(Stack *&stack) {
  int temp = stack->number;
  std::cout << temp;
}

int main() {
  Stack *stack_ = 0;
  size_t size;
  std::cout << "Please input size of Stack = ";
  std::cin >> size;
  if (size > 0) {
    std::cout << "Input number of Stack \n";
    for (int i = 0; i < size; ++i) {
      int num;
      std::cin >> num;
      push(stack_, num);
    }
    for (int i = 0; i < size; ++i) {
      std::cout << std::endl;
      top(stack_);
      pop(stack_);
    }
  } else {
    std::cout << "Size should be more 0";
  }
  return 0;
}
