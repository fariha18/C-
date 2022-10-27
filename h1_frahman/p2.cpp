// p2.cpp - F. Rahman
#include <iostream>
using namespace std;

// countdown(5) print 5
//  countdown(4) print 4
//    countdown(3) print 3
//      countdown(2) print 2
//        countdown(1) print 1 and return
//      countdown(2) return
//     countdown(3) return
//   countdown(4) return
// countdown(5) return

void countdown(int n){
  if (n==1){
    cout << n << endl;
    return;
  }

  cout << n << endl;
  countdown (n-1);
}

int main (){

  countdown (5);


  return 0;
}
