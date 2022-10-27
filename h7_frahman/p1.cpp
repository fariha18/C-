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


IntArr::IntArr() {
  for(int i=0; i<5; i++)
  capacity = 5;
  cout << endl;
}

IntArr::IntArr(int c): capacity (c), size (0){
  assert(c > 0);
  c = array[c];
}

int& IntArr::operator[](int index){
  assert (index > 0 || index < (size - 1));
  return *array;
}


const int& IntArr::operator[](int index) const{
  assert (index > 0 || index < size - 1);
  return *array;
}

//IntArr a(b);
IntArr::IntArr(const IntArr& a){
  int b;
  capacity = b;
  size = b;
  a = *array;
  IntArr( IntArr &b) : (IntArr &a);
}

IntArr& IntArr::operator=(const IntArr& a){
  int b;
  if (a != b)
  if (a(capacity)!=b(capacity))
  delete a;
  delete a(capacity);

  a(capacity) = capacity*2+1;
  const int c;
  c(size) = size*2;
  IntArr::IntArr(const IntArr&a) : (IntArr &c);

}

IntArr::~IntArr(){
  delete array;
}

int IntArr::getSize() const {
  cout << size << endl;
}

int IntArr::getCapacity() const{
  cout << capacity << endl;
}

void IntArr::grow(){
  tempArray = original_capacity*2+1;
  IntArr::IntArr(const IntArr array) : (IntArr tempArray);
  delete array;
  *array = NewArray;
}
void IntArr::push_back(int n){
  if (size==capacity){
   cout << grow() << endl;
}
   for(int i=0; i<5; i++){
   n = 5;
  }
  size++;
}
void IntArr::pop_back(){
  if (size!=0)
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
