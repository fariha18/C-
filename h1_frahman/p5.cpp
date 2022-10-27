//p5.cpp - F. Rahman
#include <iostream>
using namespace std;

int sum(long n){

  int summation = 0;
  int digit;


  while (n > 0)
  {
    digit = n % 10;
    summation += digit;
    n /= 10;
  }
    return summation;
  }

int main(){

    long n;

    cout << "Enter a value for n: ";
    cin >> n;

    int total =sum(n);
    cout << "Sum of digits: " << total;
    return 0;

  }
