// p9.cpp - F. Rahman
#include <iostream>
using namespace std;

int getIndex(int a[],int size,int n){
  for (int i = 0; i < size; i++) {
    if(a[i] == n){
     return i;
    }
  }
  return-1;
}

void output(int a[],int size){
  for (int i = 0; i < size; i++) {
  cout << a[i] << " ";
  }
  cout << endl;
}

int main()
{
  const int CAPACITY = 100;
  int a[CAPACITY] = {1,5,14,23,45,52,58,81,82,91};
  int size = 10;

    output(a,10);
    cout << "Number 23 is located at the index " << getIndex(a,size,23) << endl;
    cout << "Number 58 is located at the index " << getIndex(a,size,58) << endl;
    cout << "Number 11 is located at the index " << getIndex(a,size,11) << endl;



    return 0;
}
