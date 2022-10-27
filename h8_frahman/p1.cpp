// p1.cpp - F. Rahman
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
  Cake(): Cake (" " , " ") { }
  Cake(string n, string t): Food(n), topping(new string(t)) { }
  ~Cake(){ delete topping; }

  Cake(const Cake &c): Food(c){
    cout << "Copy Constructor" << endl;
    topping = new string(*(c.topping));
  }

  Cake& operator=(const Cake &c ) {
  cout << "Assignment Overload" << endl;
  if (this!= &c){
    Food::operator=(c);
    *topping = *(c.topping);
  }
  return *this;
     }

  void output() const { cout << *name << " " << *topping << endl; }

  private:
    string *topping;
};

int main(){

  Cake c1("Ice Cream Cake,", "Chocolate Icing");
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
