// p1.cpp - F. Rahman

#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

#include <cassert>

class RatNum {
public:
    RatNum();
    RatNum(int n);
    RatNum(int n, int d);

    void setnum(int n);
    int getnum() const;
    void setden(int d);
    int getden() const;

    RatNum operator+(const RatNum& frac) const;
    RatNum operator-(const RatNum& frac) const;
    RatNum operator*(const RatNum& frac) const;
    RatNum operator/(const RatNum& frac) const;

    RatNum operator-()const;
    void simplify(RatNum& frac)const;
private:
    int num;
    int den;
};
#endif
