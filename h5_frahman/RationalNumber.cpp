// p1.cpp - F. Rahman

#include "RationalNumber.h"

RatNum::RatNum(): RatNum(0, 1) { }
RatNum::RatNum(int n): RatNum(n, 1) { }
RatNum::RatNum(int n, int d): num(n), den(d) { assert(d != 0); }

void RatNum::setnum(int n)
{
num = n;
}
void RatNum::setden(int d)
{
den = d;
}
int RatNum::getnum() const
{
return num;
}
int RatNum::getden() const
{
return den;
}

RatNum RatNum::operator+(const RatNum& fr) const{
  RatNum frac;
  int a = num;
  int b = den;
  int c = fr.num;
  int d = fr.den;
  int sumnum = (a * d + b * c);
  int sumden = (b * d);
  frac.setnum(sumnum);
  frac.setden(sumden);
  simplify(frac);
  return frac;
  }


  RatNum RatNum::operator-(const RatNum& fr) const{
    RatNum frac;
    int a = num;
    int b = den;
    int c = fr.num;
    int d = fr.den;
    int subnum = (a * d - b * c);
    int subden = (b * d);
    frac.setnum(subnum);
    frac.setden(subden);
    simplify(frac);
    return frac;
    }

  RatNum RatNum::operator*(const RatNum& fr) const{
    RatNum frac;
    int a = num;
    int b = den;
    int c = fr.num;
    int d = fr.den;
    int mulnum = (a * c);
    int mulden = (b * d);
    frac.setnum(mulnum);
    frac.setden(mulden);
    simplify(frac);
    return frac;
    }

  RatNum RatNum::operator/(const RatNum& fr) const{
    RatNum frac;
    int a = num;
    int b = den;
    int c = fr.num;
    int d = fr.den;
    int divnum = (a * d);
    int divden = (c * b);
    frac.setnum(divnum);
    frac.setden(divden);
    simplify(frac);
    return frac;
    }



  void RatNum::simplify( RatNum& fr)const{
    int z,x,y;
    if(fr.num < fr.den)
    z = fr.den;
    else if(fr.num > fr.den)
    z = fr.num;
    else
    z = fr.num;

    int i = 2;

    while (z > 1){
      if(z % i==0){
        z = z / i;
        if (fr.num % i== 0 && fr.den % i == 0){
          fr.num = fr.num/i;
          fr.den = fr.den/i;
        }
      }
      else
          i++;
        }
      }
