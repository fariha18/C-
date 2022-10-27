// p2.cpp - F. Rahman
#include <iostream>
using namespace std;

class RatNum
{
public:
RatNum();
RatNum(int numer, int denom);
void setNumerator(int);
int getNumerator() const;
void setDenominator(int);
int getDenominator() const;

RatNum operator+(const RatNum& fr) const;
RatNum operator-(const RatNum& fr) const;
RatNum operator*(const RatNum& fr) const;
RatNum operator/(const RatNum& fr) const;
bool operator!=(const RatNum& fr) const;
bool operator==(const RatNum& fr) const;
bool operator<=(const RatNum& fr) const;
bool operator>=(const RatNum& fr) const;
bool operator<(const RatNum& fr) const;
bool operator>(const RatNum& fr) const;

int operator[](int index);
RatNum operator-()const;
void simplify(RatNum& fr)const;

friend std::ostream& operator<<(std::ostream& dout, const RatNum&);
friend std::istream& operator>>(std::istream& din, RatNum&);

private:
int numer;
int denom;
  };

RatNum::RatNum()
{
numer = 0;
denom = 1;
}
RatNum::RatNum(int num, int den)
{
   numer = num;
   denom = den;
}


void RatNum::setNumerator(int n)
{
numer = n;
}
void RatNum::setDenominator(int n)
{
denom = n;
}
int RatNum::getNumerator() const
{
return numer;
}
int RatNum::getDenominator() const
{
return denom;
}

RatNum RatNum::operator+(const RatNum& fr) const{
  RatNum frac;
  int a = numer;
  int b = denom;
  int c = fr.numer;
  int d = fr.denom;
  int sumnumer = (a * d + b * c);
  int denom = (b * d);
  frac.setNumerator(sumnumer);
  frac.setDenominator(denom);
  simplify(frac);
  return frac;
  }

RatNum RatNum::operator-() const{
  int a, b;
  if(numer>0 && denom>0)
  {
    a = -numer;
    b = denom;
  }
   else if(numer<0 && denom>0)
   {
       a = -numer;
       b = denom;
   }
   else if(numer<0 && denom<0)
   {
       a = numer;
       b = -denom;
   }

   RatNum frac(a,b);

          return frac;
}

RatNum RatNum::operator-(const RatNum& fr) const{
  RatNum frac;
  int a = numer;
  int b = denom;
  int c = fr.numer;
  int d = fr.denom;
  int subnumer = (a * d - b * c);
  int denom = (b * d);
  frac.setNumerator(subnumer);
  frac.setDenominator(denom);
  simplify(frac);
  return frac;
  }

RatNum RatNum::operator*(const RatNum& fr) const{
  RatNum frac;
  int a = numer;
  int b = denom;
  int c = fr.numer;
  int d = fr.denom;
  int mulnumer = (a * c);
  int muldenom = (b * d);
  frac.setNumerator(mulnumer);
  frac.setDenominator(muldenom);
  simplify(frac);
  return frac;
  }

RatNum RatNum::operator/(const RatNum& fr) const{
  RatNum frac;
  int a = numer;
  int b = denom;
  int c = fr.numer;
  int d = fr.denom;
  int divnumer = (a * d);
  int divdenom = (c * b);
  frac.setNumerator(divnumer);
  frac.setDenominator(divdenom);
  simplify(frac);
  return frac;
  }

bool RatNum::operator<=(const RatNum& fr) const{
  int a = numer;
  int b = denom;
  int c = fr.numer;
  int d = fr.denom;
  double n1 = a * d;
  double d1 = b * d;
  double n2 = c * b;
  double d2 = d * b;


if ((n1 / d1) <= (n2 / d2))
  return true;
  else
  return false;
  }

bool RatNum::operator>=(const RatNum& fr) const{
  int a = numer;
  int b = denom;
  int c = fr.numer;
  int d = fr.denom;
  double n1 = a * d;
  double d1 = b * d;
  double n2 = c * b;
  double d2 = d * b;


  if ((n1 / d1) >= (n2 / d2))
  return true;
  else
  return false;
  }

bool RatNum::operator<(const RatNum& fr) const{
  int a = numer;
  int b = denom;
  int c = fr.numer;
  int d = fr.denom;
  double n1 = a * d;
  double d1 = b * d;
  double n2 = c * b;
  double d2 = d * b;


  if ((n1 / d1) < (n2 / d2))
  return true;
  else
  return false;
  }

bool RatNum::operator>(const RatNum& fr) const{
  int a = numer;
  int b = denom;
  int c = fr.numer;
  int d = fr.denom;
  double n1 = a * d;
  double d1 = b * d;
  double n2 = c * b;
  double d2 = d * b;
  if ((n1 / d1) > (n2 / d2))
  return true;
  else
  return false;
  }

ostream& operator<<(ostream& dout, const RatNum& c){
dout << c.numer << "/" << c.denom;
return dout;
}


istream& operator>>(istream& din, RatNum& c){
char ch;
din >> c.numer;
din >> c.denom;
return din;
}

bool RatNum::operator!=(const RatNum& fr) const{
  int a = numer;
  int b = denom;
  int c = fr.numer;
  int d = fr.denom;
  double n1 = a * d;
  double d1 = b * d;
  double n2 = c * b;
  double d2 = d * b;

  if ((n1 != n2) || (d1 != d2))
  return true;
  else
  return false;
  }

bool RatNum::operator==(const RatNum& fr) const{
  int a = numer;
  int b = denom;
  int c = fr.numer;
  int d = fr.denom;
  double n1 = a * d;
  double d1 = b * d;
  double n2 = c * b;
  double d2 = d * b;


  if ((n1 == n2) && (d1 == d2))
  return true;
  else
  return false;
}

int RatNum::operator[](int index){
  if (index == 1) {
    return numer;
  }
  else if (index == 2) {
    return denom;
  }
}

void RatNum::simplify( RatNum& fr)const{
  int z,x,y;
  if(fr.numer < fr.denom)
  z = fr.denom;
  else if(fr.numer > fr.denom)
  z = fr.numer;
  else
  z =fr.numer;

  int i = 2;

  while (z > 1){
    if(z % i==0){
      z = z / i;
      if (fr.numer % i== 0 && fr.denom % i == 0){
        fr.numer = fr.numer/i;
        fr.denom = fr.denom/i;
      }
    }
    else
        i++;
      }
    }

int main(){
cout << endl;
RatNum r1(1,2), r2(1,6), r3(2,5);
//test operator overloads
cout << "\nInput/Output Stream Operators :" << endl;
RatNum r4;
cout << "Enter a rational number: ";
cin >> r4;
cout << r4 << endl;
cout << "Negation Operation:" << endl;
cout << -r4 << endl;

//test arithmetic overlods
cout << "\nArithmetic Operators: " << endl;
RatNum r5 = r1 + r2;
cout << r1 << " + " << r2 << " = " << r5 << endl;
RatNum r6 = r1 - r2;
cout << r1 << " - " << r2 << " = " << r6 << endl;
RatNum r7 = r1 * r2;
cout << r1 << " * " << r2 << " = " << r7 <<endl;
RatNum r8 = r1 / r2;
cout << r1 << " / " << r2 << " = " << r8 << endl;

//test arithmetic operation chaining
cout << "\nArithmetic Chaining: " << endl;
RatNum r9 = r5 + r6 - r7 * r8;
cout << r5 << " + " << r6 << " - " << r7 << " * " << r8 << " = " << r9 << endl;

//test relational operator overload
cout << "\nRelational Operators: " << endl;
cout << r5 << " == " << r6 << "? " << (r5 == r6) << endl;
cout << r5 << " != " << r6 << "? " << (r5 != r6) << endl;
cout << r5 << " > " << r6 << "? " << (r5 > r6) << endl;
cout << r5 << " < " << r6 << "? " << (r5 < r6) << endl;

//test subscript overload
cout << "\nSubscript Operator: " << endl;
cout << r5 << " num = " << r5[1] << " den = " << r5[2] << endl;
cout << endl;
return 0;
}
