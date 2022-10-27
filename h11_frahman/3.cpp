// p1.cpp - F. Rahman
#include <iostream>
#include <string>
using namespace std;

class Flight{
public:
//Flight(): Flight (" ") { }
Flight(): Flight (" ", 0){ }
Flight(string p, int n): flightNumber(n)  ,passengers(new string (p)) { }
~Flight(){ delete [] passengers; }

Flight(const Flight &f){
  cout << "Copy Constructor" << endl;
  passengers = new string(*(f.passengers));
  flightNumber = f.flightNumber;
}

Flight& operator=(const Flight &f ) {
cout << "Assignment Overload" << endl;
if (this!= &f){
  *passengers = *(f.passengers);
  flightNumber = f.flightNumber;
}
return *this;
   }


void output() const { cout << *passengers << " " << flightNumber << endl;}

protected:
  int flightNumber;
  string *passengers;
};

void add(string p){
if(passengers == flightNumber){
grow();
}
passengers[size++] = s;
}

void Flight::pop_back(){
       passengers--;
   }

int Flight::getSize() const {
     return size;
   }

int Flight::getCapacity() const{
  return capacity;
}

void Flight::push_back(int n){
  if (passengers==flightNumber){
   cout << "Calling grow for element" << n << endl;
   grow();
}
  array[passengers++] = n;
}

int main(){

Flight f;
Flight f2("John",236974);
//f3(233665,"Mary");
//f4(233785,"Cindy");
//f5(230055,"Sam");
f.output();

  return 0;

}
