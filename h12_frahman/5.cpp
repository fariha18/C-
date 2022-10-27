using namespace std;
#include <iostream>
#include <cassert>


class Money {
public:
 Money(): Money (0,0) {}
 Money(int d):Money (d,0) {}
 Money (int d, int c): dollars (d), cents (c) {
   if (c>= 100){
     dollars = d+c/100;
     cents = c%100;
   }
 }

 int getDollars() const {return dollars;}
 int getCents() const {return cents;}
 void  setDollars(int d) { dollars = d; }
 void  setCents (int c) {
   if (c >= 100) {
     dollars = dollars+c/100;
     cents = c%100;
   }
   else {
     cents = c;
   }
 }
 void print (){
   if (cents < 10){
     cout << "$" << dollars << "." << "0" << cents << endl;

   }
   else{
     cout << "$" << dollars << "." << cents << endl;
   }
 }

 Money operator-() const {
   return Money (-dollars, -cents);
 }
 int& operator[](int index){
   assert (index >= 0 && index <= 1);
   if (index == 0){
     return dollars;
   } else {
   return cents;
 }
 }

friend bool operator== (const Money &lhs, const Money &rhs);
friend Money operator+ (const Money &lhs, const Money &rhs);

private:
  int dollars;
  int cents;
};

 bool operator==(const Money &lhs, const Money &rhs){
   return lhs.dollars  == rhs.dollars && lhs.cents == rhs.cents;
 }
 Money operator+ (const Money &lhs, const Money &rhs ){
   return lhs.dollars  == rhs.dollars && lhs.cents == rhs.cents;
 }

ostream& operator<< (ostream& out, const Money &m){
out << "$" << m.dollars << "." << m.cents;
return out;
}
int main (){
  Money m1(3, 50);
  Money m2(2, 60);



 cout << "m1 == m2: " << (m1 == m2) << endl;
 cout << "m1 + m2: " << (m1 + m2) << endl;
 cout << "10 + m1 + m2: " << (10 + m1 + m2) << endl;

  return 0;
}
