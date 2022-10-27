// p1.cpp - F. Rahman
#include <iostream>
using namespace std;
void print(int *a, int size){
  for (int i = 0; i < size; i++)
    cout << *(a + i) << " " << endl ;
 }
void printMemory(int *a, int newSize){
  for (int i = 0; i < newSize; i++)
    cout << (a + i) << " "<< endl;
}

void populate(int *a, int size){
  for (int i = 0; i < size; i++)
    *(a + i) = i;
}

int* grow(int *p, int size, int newSize){
  newSize = 2*size+1;
  int *newArray = new int[newSize]();
  copy(p, p + min(size, newSize), newArray);

  delete[] p;
  return newArray;
}


int main(){
  cout << endl;

  int size, newSize;
  cout << "Enter a size: ";
  cin >> size;
  cout << endl;

  int *p = new int[size]();
  cout << "Original: " << endl;
  populate(p, size);
  print(p, size);
  printMemory(p, size);
  cout << endl;

  cout << "Enter a new size: ";
  cin >> newSize;
  cout << endl;

  p = grow(p, size, newSize);
  cout << "After grow: " << endl;
  print(p, newSize);
  printMemory(p, newSize);

  cout << endl;
  return 0;
}
