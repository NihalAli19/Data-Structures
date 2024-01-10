//Q1_22K-4054_Nihal_Ali
#include <iostream>
using namespace std;
int main() {
    int arr[5][10];
    
    cout<<"Enter elements: \n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            cin>>arr[i][j];
        }
    }
    cout<<"The elements you entered: \n";
     for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
        cout<<"Element ["<< (i+1)<<"]["<<(j+1)<<"]: "<<arr[i][j]<<"\n";
        }
     }
}
