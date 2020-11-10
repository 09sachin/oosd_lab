#include <iostream>
using namespace std;


int main() {
   int n,max;
   cin >> n;

   int array[n];


   for (int i = 0; i <n ; ++i) {
       cin >> array[i];
   }
   max = array[0];

   for (int j = 1; j <n ; ++j) {
       if(array[j]>max){
           max = array[j];
       }
   }
   cout << max<<endl;

   return 0;
}