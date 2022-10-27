// p4.cpp - F. Rahman
#include <iostream>
using namespace std;

int countDigit(long n)
{
    int count = 0;
    while (n > 0) {
        n = n / 10;
        ++count;
    }
    return count;
}

int main(){

    long long n;

    cout << "Enter a value for n: ";
    cin >> n;

    int total = countDigit(n);
    cout<< "# of digits: "<< total;
    return 0;

  }
