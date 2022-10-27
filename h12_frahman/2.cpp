using namespace std;
#include <iostream>
#include <string>


class Person{

private:
  string f_name;
  string l_name;
  int age;

//declarations
public:
  Person();
  Person (string f, string l, int a);
  string getName() const;
  int getAge () const;

};

//definitions
Person:: Person(): Person("first", "last", 0) { }
Person:: Person(string f, string l, int a): f_name(f), l_name(l), age(a) { }

string Person:: getName() const {return f_name + " " + l_name;}
int Person:: getAge () const {return age;}

int main(){
  Person p1{};
  cout << p1.getName() << endl;
  cout << p1.getAge() << endl;

  Person p2{"Donald", "Duck", 100};
  cout << p2.getName() << endl;
  cout << p2.getAge() << endl;

    return 0;
}
