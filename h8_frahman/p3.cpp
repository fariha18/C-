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
  Cake(): Cake (" "," ") { }
  Cake(string n, string t): Food(n), toppings(t), numtoppings(0),toppings (new Cake[CAPACITY]) { }
  void addtoppings(string t){
    if (numtoppings < CAPACITY) {toppings[numtoppings++] = Cake(t);}
  }
  ~Cake(){ delete [] toppings; }
  Cake(const Cake &c): Food(c){
    cout << "Copy Constructor" << endl;
    for(int i = 0; i<CAPACITY; i++)
  {toppings = new string(*(c.toppings)); }

  }

  Cake& operator=(const Cake &c ) {
  cout << "Assignment Overload" << endl;
  if (this!= &c){
    Food::operator=(c);
    for(int i = 0; i<CAPACITY; i++)
    {*toppings = *(c.toppings); }
  }
  return *this;
     }

  void output() const { cout << *name << " " << *toppings << endl; }

  private:
    const int CAPACITY = 5;
    string *toppings;
    int numtoppings;
};

int main(){
  Cake c1("Ice Cream Cake,", "Chocolate Icing,");
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
