using namespace std;
#include <iostream>
#include <string>

class Address{
public:
  Address () : Address ("location") { }
  Address (string loc):location (loc) { }
  string getAddress ( ) const {return location; }
  void setAddress (string loc) { location = loc; }

private:
  string location;
};

class Person{
  //declarations
  public:
    Person(): Person ("first", "last", 0) {}
    Person(int a): Person ("first", "last", a) {}
    Person (string f, string l, int a): f_name(f), l_name (l), age (a) {}
    string getName() const {return f_name + " " + l_name; }
    int getAge () const {return age; }
    Address getaddress () const { return home}

  private:
  string f_name;
  string l_name;
  int age;
  Address home;

};
// obj.memberfunction()
//non-member function
void output (Person&p){
  cout << "name: " << p.getName() << " age: " << p.getAge ();
  cout << "address: " << p.getAddress (). getLocation () << endl;
}


int main(){
  Person p1{};
  cout << p1.getName() << endl;
  cout << p1.getAge() << endl;

  Person p2{"Donald", "Duck", 100};
  cout << p2.getName() << endl;
  cout << p2.getAge() << endl << endl;

  Address a1{};
  cout << a1.getAddress() << endl;

  Address a2{"222-05 56th Ave. Bayside NY"};
  cout << a2.getAddress() << endl;

  output (p2);

    return 0;
}
