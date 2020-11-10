#include <iostream>
using namespace std;



int main(){
    int array[3][3]={{1,2,3},{4,5,6},{6,7,8}};
    int array2[3][3]={{1,2,3},{4,5,6},{6,7,8}};
    int sum[3][3],multiply[3][3];

    for (int i = 0; i <3 ; ++i) {
        for (int j = 0; j <3 ; ++j) {
            sum[i][j] = array[i][j]+ array2[i][j];
            cout << sum[i][j]<< "  ";
        }
        cout <<"\n";
    }

    cout << "\narray*array2 is  \n";

    for (int k = 0; k <3 ; ++k) {
        for (int i = 0; i <3 ; ++i) {
            multiply[k][i]=0;
            for (int j = 0; j <3 ; ++j) {
                multiply[k][i]+=array[k][j]*(array2[j][i]);
            }
            cout << multiply[k][i]<<"  ";

        }
        cout << "\n";
    }
    return 0;
    
}
