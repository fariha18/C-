//p1.cpp F.Rahman
#include <iostream>
#include <cassert>
using namespace std;

class IntArr{
public:
  IntArr();
  IntArr(int c);

  int& operator[](int index);
  const int& operator[](int index) const;

  IntArr(const IntArr &a);
  IntArr& operator=(const IntArr &a);
  ~IntArr();

  int getSize() const;
  int getCapacity() const;

  void grow();
  void push_back(int n);
  void pop_back();

private:
  int capacity;
  int size;
  int *array;
};

//default constructor
IntArr::IntArr(): IntArr(1) {
}

IntArr::IntArr(int s): capacity (s), size (0){
  assert(capacity > 0);
  array = new int[capacity]();
}

IntArr::~IntArr(){
  delete [] array;
}

//IntArr a(b);// the big three: copy constructor
IntArr::IntArr(const IntArr& a):
capacity(a.capacity),
size(a.size), array(new int[a.capacity]) {
  for(int i = 0; i<size; i++){
    array[i] = a[i];
  }
}

IntArr& IntArr::operator=(const IntArr& a){
  if(this != &a){
    if(capacity != a.capacity){
      delete [] array;
      capacity = a.capacity;
      array = new int[a.capacity]();
    }
    size = a.size;
    for(int i=0; i<size; i++){
      array[i] = a[i];
    }
  }
  return *this;
}

int& IntArr::operator[](int index){
  assert (index >= 0 && index < size);
  return array[index];
}

const int& IntArr::operator[](int index) const{
  assert (index >= 0 && index < size);
  return array[index];
}

int IntArr::getSize() const {
  return size;
}

int IntArr::getCapacity() const{
  return capacity;
}

void IntArr::grow(){
  int *temp = new int [capacity*2+1]();
  capacity = capacity*2+1;
  for(int i=0; i<size; i++){
    temp[i] = array [i];
  }
  delete [] array;
  array = temp;
}

void IntArr::push_back(int n){
  if (size==capacity){
   cout << "Calling grow for elementv" << n << endl;
   grow();
}
  array[size++] = n;
}

void IntArr::pop_back(){
    size--;
}

int main(){
IntArr a{5};

cout << "Test Constructors and Push_Back" << endl;
for(int i=0; i<5; i++) {a.push_back((i+1)*5); }
cout << "Array A: ";
for(int i=0; i<a.getSize();i++) {cout << a[i] << " "; }
cout << "size: " << a.getSize() << " capacity: " << a.getCapacity() << endl;


cout << "\nTest Grow" << endl;
a.push_back(30);
a.push_back(35);
cout << "Array A: ";
for(int i=0; i<a.getSize(); i++) {cout << a[i] << " "; }
cout << "size: " << a.getSize() << "capacity: " << a.getCapacity() << endl;

cout << "\nTest Copy Constructor (IntArr b=a)" << endl;
IntArr b = a;
cout << "Array A: ";
for(int i=0; i<a.getSize();i++) {cout << a[i] << " "; }
cout << "size: " << a.getSize() << "capacity: " << a.getCapacity() << endl;
cout << "Array B: ";
for(int i=0; i<b.getSize();i++) {cout << b[i] << " "; }
cout << "size: " << b.getSize() << "capacity: " << b.getCapacity() << endl;

cout << "\nTest Pop_Back (pop last two elements)" << endl;
b.pop_back();
b.pop_back();
cout << "Array B: ";
for(int i=0; i<b.getSize(); i++) {cout << b[i] << " "; }
cout << "size: " << b.getSize() << "capacity: " << b.getCapacity() << endl;

cout << "\nTest Assignement Operator (a=b)" << endl;
a = b;
cout << "Array A: ";
for(int i=0; i<a.getSize();i++){ cout << a[i] << " " ; }
cout << "size: " << a.getSize() << "capacity: " << a.getCapacity() << endl;
cout << "Array B: ";
for(int i=0; i<b.getSize();i++) {cout << b[i] << " "; }
cout << "size: " << b.getSize() << " capacity: " << b.getCapacity() << endl;

  return 0;
}
