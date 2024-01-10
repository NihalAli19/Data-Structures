#include <iostream>
using namespace std;

int main() {
	
	bool arr[5][5];
	arr[0][0]= false;
	arr[0][1] = true;
	arr[0][2] = false;
	arr[0][3] = true;
	arr[0][4] = true;
	arr[1][0] = true;
	arr[1][1] = false;
	arr[1][2] = true;
	arr[1][3] = false;
	arr[1][4] = true;
	arr[2][0]= false;
	arr[2][1] = true;
	arr[2][2] = false;
	arr[2][3]= false;
	arr[2][4]= false;
	arr[3][0] = true;
	arr[3][1]= false;
	arr[3][2]= false;
	arr[3][3]= false;
	arr[3][4] = true;
	arr[4][0] = true;
	arr[4][1] = true;
	arr[4][2] = false;
	arr[4][3] = true;
	arr[4][4]= false;
	
	int num1, num2, count = 0;
	bool arr1[5];
	bool arr2[5];
	
	cout<<"Mutual friends check for:" << endl;
	cout<<"Number 1:" << endl;
	cin>>num1;
	cout<<"Number 2:" << endl;
	cin>>num2;
	
	for (int i = num1; i <= (num1); i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] == true) {
				arr1[j] = arr[i][j];
				count++;
			}
		}
		cout<<"Count: "<< count << endl;
	}
	for (int i = 0; i < 5; i++) {
        cout<<"Element "<< (i)<<": "<<arr1[i]<<"\n";
    }
    
    // second matrix
    
    arr2[0] = false;
    arr2[1] = false;
    arr2[2] = false;
    arr2[3] = false;
    arr2[4] = false;
    
    int found = 0;
    for (int m = num2; m <= (num2); m++) {
		for (int n = 0; n < 5; n++) {
			if (arr[m][n] == true) {
				arr2[n] = arr[m][n];
				found++;
			}
		}
		cout<<"Count: "<< found << endl;
	}
	for (int i = 0; i < 5; i++) {
        cout<<"Element "<< (i)<<": "<<arr2[i]<<"\n";
    }
    
    int match = 0;
    bool matchs[5];
    matchs[0] = false;
    matchs[1] = false;
    matchs[2] = false;
    matchs[3] = false;
    matchs[4] = false;
    
    for (int i = 0; i < 5; i++) {
    	if ((arr1[i] == arr2[i]) && (arr1[i] == 1) && (arr2[i] == 1)) {
    		match++;
    		matchs[i] = arr1[i];
		}
	}
	cout<<""<<num1<<" and " <<num2<<" have "<<match<<" matches!"<< endl;
    
    for (int i = 0; i < 5; i++) {
    	if (matchs[i] == 1) {
			cout<<"Mutual friends is: "<<i<<"\n";	
		}
    }
}