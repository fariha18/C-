using namespace std;
#include <iostream>
#include <string>


class Person{

private:
  string f_name;
  string l_name;
  int age;

public:
  Person(): f_name("first"), l_name("last"), age(0) { }

  string getName() const {return f_name + " " + l_name;}
  int getAge () const {return age;}

};


int main(){
  Person p{};
  cout << p.getName() << endl;
  cout << p.getAge() << endl;

    return 0;
}
