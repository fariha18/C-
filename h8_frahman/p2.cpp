// p2.cpp - F. Rahman
#include <iostream>
#include <string>
using namespace std;

class Food{
public:
Food(): Food (" ") { }
Food(string n): name(new string (n)) { }
~Food(){ delete name; }

Food(const Food &f){
  cout << "Copy Constructor" << endl;
  name = new string(*(f.name));
}
Food& operator=(const Food &f ) {
cout << "Assignment Overload" << endl;
if (this!= &f){
  *name = *(f.name);
}
return *this;
   }
void output() const { cout << *name << endl;}

protected:
  string *name;
};


class Cake : public Food {
public:
  Cake(): Cake (" " , " ", " ") { }
  Cake(string n, string t1, string t2): Food(n), toppings1(new string(t1)), toppings2(new string(t2)) { }
  ~Cake(){ delete toppings1, toppings2; }


  Cake(const Cake &c): Food(c){
    cout << "Copy Constructor" << endl;
    toppings1 = new string(*(c.toppings1));
    toppings2 = new string(*(c.toppings2));
  }

  Cake& operator=(const Cake &c ) {
  cout << "Assignment Overload" << endl;
  if (this!= &c){
    Food::operator=(c);
    *toppings1 = *(c.toppings1);
    *toppings2 = *(c.toppings2);
  }
  return *this;
     }

  void output() const { cout << *name << " " << *toppings1 << *toppings2 << endl; }

  private:
    string *toppings1;
    string *toppings2;
};

int main(){
  Cake c1("Ice Cream Cake,", "Chocolate Icing,", " Sprinkles");
  c1.output();

  cout << endl;

  cout << "s2: ";
  Cake c2(c1);
  c1.output();

  cout << endl;

  cout << "s3: ";
  c2 = c2;
  c1.output();

  return 0;
}
