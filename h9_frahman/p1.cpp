//p1.cpp F.Rahman
#include <iostream>
using namespace std;

class Person{
public:
  Person():Person(" ") { };
  Person(string n): name(n) { };
  virtual void output() const { cout << name << " ";}

  string name;
};

class Student: public Person{
public:
  Student():Student(" ", 0) { };
  Student(string n, int i): name(n), id(i) { };
  void output() const override { cout << name << " " << id; }

  int id;
  string name;
};

int main(){
  Person *p = nullptr;
    Student s("Jake",1010);
    p = &s;
    p->output();
    return 0;
}
