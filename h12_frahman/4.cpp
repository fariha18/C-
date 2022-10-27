using namespace std;
#include <iostream>
#include <string>


class Money {
public:
 Money(): Money (0,0) {}
 Money(int d):Money (d,0) {}
 Money (int d, int c): dollars (d), cents (c) {
   if (c>+ 100){
     dollars = d+c/100;
     cents = c%100;
   }
 }

 int getDollars() const {return dollars;}
 int getCents() const {return cents;}
 void  setDollars(int d) {dollars = d;}
 void  setDollars(int c) {
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
private:
  double dollars;
  double cents;

};
int main (){
  Money a(100);
  Money b(100, 7);
  Money c(100, 240);
  a.print();
  b.print();
  c.print();

  return 0;
}
