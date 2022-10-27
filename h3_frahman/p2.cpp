// p2.cpp - F. Rahman
using namespace std;
#include <iostream>
#include <cmath>

void displayChessBoard(int QueenCol[8]){

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(j == QueenCol[i])
        cout << " Q ";
      else
        cout << " . ";
             }
        cout << endl;
       }
}

bool queensAreSafe(int QueenCol[ ]){

  for(int i = 0; i < 8; i++){
   for(int j = i+1; j < 8; j++){
    if(QueenCol[i] == QueenCol[j])

      return false;

    if((i - j) == (QueenCol[i] - QueenCol[j]))

      return false;
             }
       }

       return true;
}

int main( ) {

  int QueenCol[8];
      cout << "Enter 8 column values : ";
   for(int i = 0; i < 8; i++)
      cin >> QueenCol[i];

  displayChessBoard(QueenCol);
    if(queensAreSafe(QueenCol))
        cout << endl << "Queens are safe!";
    else
        cout << endl << "Queens are not safe!";

        return 0;
}
