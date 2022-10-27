#include <iostream>
using namespace std;


int getSortedIndex(constant int a[], constant size, int n){
  for (int i=0; i<SIZE; ++i){
    if (n> a[i]){
      return i;
    }
  }
  return size;
}


int insertAt(int a[],int  &size,const int &CAPACITY, int n){
  if (size< CAPACITY){ // is there space in the array
    int index= getSortedIndex (a, size, n);
    for (int i=size; i>index; --i){
      a[i]=a[i-1];
    }
    a[index} =n;
    ++size;
  }
}

int getSortedIndex(constant int a[], constant size, int n){
  for (int i=0; i<SIZE; ++i){
    if (n> a[i]){
      return i;
    }
  }
  return size;
}

void print(const int a[], const int &SIZE){
  for(int i=0; i<SIZE; ++i){ cout << a[i] << " ";}
  cout << endl;
}





int main(){

const int CAPACITY =100;
int a[CAPACITY]= {10,20,30,40,50};
int size= 5;

print (a, size);
insertAt(a, size,CAPACITY,5);
insertAt(a, size,CAPACITY,100);
insertAt(a, size,CAPACITY,25);

  return 0;
}
