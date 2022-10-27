// p2.cpp - F. Rahman
#include <iostream>
using namespace std;

int fibonacci(int n , long *a){
  if (n < 2)
      return n;
  else if(a[n] == -1){

       a[n] = fibonacci(n-1,a) + fibonacci(n-2,a);
     }
      return a[n];
}

int main (){
  long *a = new long[50];
  a[0] = 0;
  a[1] = 1;

  for (int i = 2; i < 50; i++) {
  a[i] = -1;
  }

  cout << "fib(0): " << fibonacci(0,a) << endl;
  cout << "fib(6): " << fibonacci(6,a) << endl;
  cout << "fib(8): " << fibonacci(8,a) << endl;
  cout << "fib(15): "<< fibonacci(15,a) << endl;
  cout << "fib(20): "<< fibonacci(20,a) << endl;
  cout << "fib(37): "<< fibonacci(37,a) << endl;
  cout << "fib(45): "<< fibonacci(45,a) << endl;
  cout << "fib(48): "<< fibonacci(48,a) << endl;

  delete [] a;
  return 0;
  }
