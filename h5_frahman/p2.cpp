// p2.cpp - F. Rahman
#include <iostream>
using namespace std;

void print (const int a[], const int &SIZE ){
  for(int row = 0; row < SIZE; row++){
    for(int col = 0; col < SIZE; col++){
      if(col == row)
        cout << " Q ";
      else
        cout << " . ";
             }
        cout << endl;
       }
        }

bool isSafePosition(const int a[], const int &SIZE, int row, int col){
  for(int row = 0; row < SIZE; row++){
   for(int col = row + 1; col < SIZE; col++){
    if(a[row] == a[col])

      return false;

      if((row - col) == (a[row] - a[col] ))

        return false;
             }
           }

           return true;
         }

bool solve (int a[], const int &SIZE, int row){
  if ( row == SIZE) {
     return true;
 }
  else
    for (int row = 0; row < SIZE; row++){
      for (int col = 0; col < SIZE; col++){
        cout << "check: "<< row << " " << col << endl;
      if (isSafePosition( a, SIZE,  row, col -1)) {
        a[row] = col;
         return true;
       }

      print (a,SIZE);
          }
            }
              }

int main(){
  cout << endl;


  const int SIZE = 8;
  int a[SIZE];
  for(int i = 0; i < SIZE; i++) { a [i] = -1; }

  solve (a, SIZE, 0);

  cout << endl;
  return 0;
}
