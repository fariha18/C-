// p3.cpp - F. Rahman
#include <iostream>
using namespace std;

//output(5) print
  //output(4) print
    //output(3) print
      //output(2) print
        //output(1) print and return
        //output(2) return
      //output(3) return
   //output(4) return
//output(5) return

void output (int a[], int size){
  if (size == 1){
  cout << a[size-1] << endl;
  return;
  }
  cout << a[size-1] << endl;
  output(a,size-1);
}


 int sum (int a[], int size){
   if (size == 1){
   cout << a[size-1] << endl;
   return a[size-1] ;
}

   cout <<  a [size-1] << endl;
   return sum(a, size-1) + a[size -1];

}


int main (){
  const int CAPACITY = 5;
  int a[CAPACITY]= {1,2,3,4,5};

  //output(a,5);

  int total = sum(a,5);
  cout<<"Sum: : "<< total;
  return 0;

}
