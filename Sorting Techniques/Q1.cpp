#include <iostream>
using namespace std;

int main() {
	//int arr[] = {23,8,11,19,5};
	int arr[] = {78,5,7,64,35};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	int temp = 0, k = 1;
	
	cout<<"Unsorted Array:"<<endl;
	for (int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
	
	for (int i = 1; i < n; i++) {
		
		for (int j = 0; j < (n - 1); j++) {
		
		
			if (arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			
			cout<<endl<<"\n"<<k<<" Pass:"<<endl;
			for (int i = 0; i < n; i++) {
			cout<<arr[i]<<" ";
			}
			k++;
		}
		}
	}
	cout<<endl<<"\nSorted Array:"<<endl;
	for (int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
}
