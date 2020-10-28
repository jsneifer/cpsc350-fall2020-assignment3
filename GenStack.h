// header file GenStack.h
#include <iostream>
using namespace std;

template <class T>
class GenStack {
  public:
    GenStack<T>(); //default construcor
    GenStack<T>(int maxSize); //overloaded
    ~GenStack<T>(); //destructor

    void push(T data);
    T pop();
    T peek();

    bool isFull();
    bool isEmpty();
    int getSize();
    void doubleSize(); // Doubles the Size of myArr
    void printStack();

    int top;
    int mSize;

  private:
    T *myArr;
};
