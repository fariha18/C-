// p8.cpp - F. Rahman
#include <iostream>
using namespace std;

void outputArray(int a[4]){

   for(int i = 0;i<4; i++){
   for(int j = 0;j<4; j++){
     if(i==a[0] && j==0){
      cout<<(" X ");
      }
         else if(i==a[1] && j==1){
         cout<<" Q ";
         }
         else if(i==a[2] && j==2){
          cout<<" Q ";
            }
         else if(i==a[3] && j==3){
         cout<<" Q ";
            }
         else{
         cout<<" . ";
            }
               }
        cout<<endl;
      }
    }

int main () {
   int array[4];
   cout << "Enter 4 row values (from 0 to 3): ";
   for(int i=0;i<4;i++){
      cin >> array[i];
   }
   outputArray(array);
   return 0;
}
