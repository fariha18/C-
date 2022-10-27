//p6.cpp - F. Rahman
#include <iostream>
using namespace std;


int getSortedIndex(const int a[], const int SIZE, int n){
  for (int i=0; i< SIZE; ++i){
    if (n > a[i]){
      return i;
    }
  }
  return SIZE;
}


int insertAt(int a[],int  &size,const int &CAPACITY, int n){
  if (size < CAPACITY){
  int index = getSortedIndex (a, size, n);
    for (int i=size; i>index; --i){
      a[i]=a[i-1];
    }
       a[index] = n;
       ++size;
  }
        return 0;
  }

int getSortedIndex(int a[],int &size,int CAPACITY,int n,int index){
  for (int i=size;i>index;i--) {
    a[i]=a[i-1];
  }
  a[index]=n;
  size++;
  return -1;
}

void print(const int a[], int size){
  for (int i=0;i<size;i++) {
  cout<<a[i]<<" ";
   }
   cout << endl;
 }


int main(){

  const int CAPACITY = 100;
  int a[CAPACITY]= {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int size= 10;

  print (a,size);
  getSortedIndex(a,size,CAPACITY,15,1);
  print (a,size);
  getSortedIndex(a,size,CAPACITY,150,11);
  print (a,size);
  getSortedIndex(a,size,CAPACITY,55,6);
  print (a,size);

  return 0;
}
