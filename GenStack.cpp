//implementation file GenStack.cpp

#include "GenStack.h"

using namespace std;
//default constructor
template <class T>
GenStack<T>::GenStack() {
  myArr = new T[128];
  mSize = 128;
  top = -1;
}

//overloaded constructor
template <class T>
GenStack<T>::GenStack(int maxSize) {
  myArr = new T[maxSize];
  mSize = maxSize;
  top = -1;
}

template <class T>
GenStack<T>::~GenStack(){
  delete myArr;
}

template <class T>
void GenStack<T>::push(T data) {

  //check if stack is full before proceeding
  if(isFull()) {
    //If stack is full, double the size of the array
    doubleSize();
  }

  myArr[++top] = data;
}

template <class T>
T GenStack<T>::pop() {
  // Check if empty before proceeding
  if(isEmpty()) {
    cout << "ERROR: stack is empty" << endl;
    return '\0';
  }
  return myArr[top--];
}


template <class T>
T GenStack<T>::peek() {
  if(isEmpty()) {
    cout << "ERROR: stack is empty" << endl;
  }
  return myArr[top];
}

template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}

template <class T>
bool GenStack<T>::isFull() {
  return (top == (mSize-1));
}

template <class T>
int GenStack<T>::getSize() {
  return (top+1);
}

template <class T>
void GenStack<T>::doubleSize() {
  T *tempArr = myArr;
  myArr = new T[mSize * 2];
  for(int i = 0; i < mSize; ++i) {
    myArr[i] = tempArr[i];
  }
  mSize *= 2;
  delete tempArr;
}

template <class T>
void GenStack<T>::printStack() {
  cout << "Stack: ";
  for(int i = 0; i < sizeof(myArr); ++i) {
    cout << myArr[i];
  }
  cout << endl;
}
