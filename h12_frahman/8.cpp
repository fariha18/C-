#include <iostream>
using namespace std;





// countup(5)
//  countup(4)
//   countup(3)
//     countup(2)
//      countup(1) print 1 and return
//    countup(2)  print 2 and return
//  countup(3) print 3 and return
// countup(4)  print 4 and return
// countup(5)  print 5 and return

void countup(int n){
  if (n==1){
    cout << n << endl;
    return;
  }
  countup (n-1);
  cout << n << endl;
}




int main(){



  return 0;
}
