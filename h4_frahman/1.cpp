// p1.cpp - F. Rahman

#include <iostream>
using namespace std;

class RatNum{
int numerator;
int denominator;

public:

//default constructor
RatNum()
  {
    numerator = 0;
    denominator = 1;
  }



//single parameterised constructor
RatNum(int num)
  {
    numerator = num;
    denominator = 1; //denominator value 1
  }

//dual parameterised constructor
RatNum(int num, int den)
  {
    numerator = num;
    denominator = den;
  }

//set num
void setNum(int num)
  {
    numerator = num;
  }

//get num
int getNum()
  {
    return numerator;
  }

//set denom
void setDen(int den)
  {
    denominator = den;
  }

//get denom
int getDen()
  {
    return denominator;
  }

//find GCD recursive
static int gcd(int a, int b){
  if(a > b)
  return gcd(a - b, b);
  else if(a < b)
  return gcd(a, b - a);
  else
  return a;
}

//find LCM
static int lcm(int a, int b){
int ab = a * b;
int gcd = RatNum::gcd(a, b);
  return ab / gcd;
}

//reducing this fraction
void reduce(){
int gcd = RatNum::gcd(numerator, denominator);

numerator /= gcd;
denominator /= gcd;
}
  };


int main(){
   cout << endl;

//test constructor, accessor and mutator
cout << "Default Constructor: ";
RatNum r1;
cout << r1.getNum() << "/" << r1.getDen() << endl;
cout << "Single Parameter Constructor: ";
RatNum r2(2);
cout << r2.getNum() << "/" << r2.getDen() << endl;
cout << "Dual Parameter Constructor: ";
RatNum r3(1, 3);
cout << r3.getNum() << "/" << r3.getDen() << endl;
cout << "Accessors / Mutators: ";
r3.setNum(3);
r3.setDen(12);
cout << r3.getNum() << "/" << r3.getDen() << endl;

//test gcd
cout << "\nGCD of the last fraction: "
     << RatNum::gcd(r3.getNum(), r3.getDen()) << endl
<< "GCD of 40 and 24: " << RatNum::gcd(40, 24) << endl;

//test lcm
cout << "\nLCM of the last fraction: "
     << RatNum::lcm(r3.getNum(), r3.getDen()) << endl
<< "LCM of 3 and 5: " << RatNum::lcm(3, 5) << endl;

//test reduce
cout << "\nReducing last fraction: ";
r3.reduce();
cout << r3.getNum() << "/" << r3.getDen() << endl;

   cout << end;
   return 0;
 }
