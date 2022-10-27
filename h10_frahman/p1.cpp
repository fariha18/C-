//p1.cpp F.Rahman
#include <iostream>
#include <cassert>
using namespace std;

class SomeObj{
public:
  SomeObj(): SomeObj(0) { };
  SomeObj(int i): id(i) { id = i; };
  int getId() { return id; }
  void output(){ cout << id << endl;}

private:
  int id;
};

template <typename T>
class MyArray{
public:
  MyArray();
  MyArray(int m);
  T& operator[](int index);
  int getSize() const;
  int getCapacity() const;


  MyArray(const MyArray &m);
  MyArray<T>& operator=(const MyArray& m);
  ~MyArray();

  void grow();
  void push_back(T e);
  void erase(int index[], int element);
  int  getIndex(int array[], T value);

private:
  T   *data;
  int capacity;
  int size;
};

template <typename T>
MyArray<T>::MyArray(): MyArray(1) {
}

template <typename T>
MyArray<T>::MyArray(int c) {
  assert(c > 0);
  size = 10;
  capacity = c;
  data = new T[capacity];
}

template <typename T>
MyArray<T>::~MyArray(){
  delete [] data;
}

template <typename T>
MyArray<T>::MyArray(const MyArray& m):
capacity(m.capacity),
size(m.size), data(new T(m.data)) {
  for(int i = 0; i<size; i++){
    data[i] = m[i];
  }
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray& m){
  if(this != &m){
    if(capacity != m.capacity){
      delete [] data;
      capacity = m.capacity;
      data = new int[m.capacity]();
    }
    size = m.size;
    for(int i=0; i<size; i++){
      data[i] = m[i];
    }
  }
  return *this;
}

template <typename T>
T& MyArray<T>::operator[](int index){
  assert (index >= 0 && index < size);
  return data[index];
}

template <typename T>
int MyArray<T>::getSize() const {
  return size;
}

template <typename T>
int MyArray<T>::getCapacity() const{
  return capacity;
}

template <typename T>
void MyArray<T>::grow(){
  int newsize = size * 2;
  T* newarray = new T[newsize];
  for(int i = 0; i < size; i++)
    newarray[i] = data[i];
  delete[] data;
  data = newarray;
  size = newsize;
}

template <typename T>
void MyArray<T>::push_back(T e){
  if (size < e){
   cout << "Calling grow for element" << e << endl;
   grow();
}
  data[size++] = e;
}

template <typename T>
int MyArray<T>::getIndex(int array[], T value) {
    for (int i = 0; i < size; i++){
        if (array[i] == value){
            return i;
            }
          }
    return -1;
}

template <typename T>
void MyArray<T>::erase(int index[], int element){
    if(index[element] <= element){
      push_back();
    }
    data[index] = element;
    index--;
}

template <typename T>
void printHeap(MyArray<T>object){
  for(int i= 0; i<object.getSize(); i++){
    cout << *(object[i]) << " ";
  }
  cout << endl;
}

int main(){
  cout << endl;

  MyArray<SomeObj*>object(10);
  for(int i = 0; i < 10; i++)
      object[i] = new SomeObj((i+1));
  for(int i = 0; i < object.getSize(); i++)
      object[i] -> output();

   cout << endl;
   return 0;

}
