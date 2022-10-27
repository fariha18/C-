// p7.cpp - F. Rahman
#include <iostream>
#include <time.h>
using namespace std;

void printArray (int a[], int size){
  for (int i= 0; i < size ; i++){
  cout << a[i] << " ";
  }
    }

void randomArray (int a[], int size){

  srand(time(NULL));

  for (int i= 0; i < size ; i++){
  a[i]=rand()%size;

  for (int j = 0; j <  i; j++) {
  if (a[i] == a[j]) {

      --i;
      break;

    }
      }
        }
          }

int main(){
  const int CAPACITY = 10;
  int a[CAPACITY]= {0,1,2,3,4,5,6,7,8,9};

  randomArray (a,10);
  printArray(a,10);

  return 0;
        }
