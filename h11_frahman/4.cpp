// p1.cpp - F. Rahman
#include <iostream>
#include <string>
using namespace std;

class Phone{
public:
Phone(): Phone (" ") { }
Phone(string n): name(new string (n)) { }
~Phone(){ delete name; }

Phone(const Phone &p){
  cout << "Copy Constructor" << endl;
  name = new string(*(p.name));
}
Phone& operator=(const Phone &p ) {
cout << "Assignment Overload" << endl;
if (this!= &p){
  *name = *(p.name);
}
return *this;
   }

void output() const { cout << *name << endl;}

protected:
  string *name;
};


class Wallpaper : public Phone {
public:
  Wallpaper(): Wallpaper (" " , " ") { }
  Wallpaper(string n, string t): Phone(n), type(new string(t)) { }
  ~Wallpaper(){ delete type; }

  Wallpaper(const Wallpaper &w): Phone(w){
    cout << "Copy Constructor" << endl;
    type = new string(*(w.type));
  }

  Wallpaper& operator=(const Wallpaper &w ) {
  cout << "Assignment Overload" << endl;
  if (this!= &w){
    Phone::operator=(w);
    *type = *(w.type);
  }
  return *this;
     }

  void output() const { cout << *name << " " << *type << endl; }

  private:
    string *type;
};

int main(){

  Wallpaper w1("Iphone,", "Live Wallpaper");
  w1.output();

  return 0;

}
