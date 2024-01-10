#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int n, time, k = 1;
	
	cout<<"Enter the number of crates you want to sort: ";
	cin>>n;
	
	int crates[n], cName[n];
	
	for (int i = 0; i < n; i++) {
		cout<<"Enter the time(first digit - 24 hour) for crate at position "<<(i+1)<<" to be shipped:"<<endl;
		cin>>time;
		crates[i] = time;
	}
	
	for (int i = 1; i < n; i++) {
        int key = crates[i];
        int j = i - 1;

        
        while (j >= 0 && crates[j] > key) {
            crates[j + 1] = crates[j];
            j--;
        }

                crates[j + 1] = key;
        cout<<endl<<"\n"<<k<<" pass:"<<endl;
		for (int i = 0; i < n; i++) {
			cout<<crates[i]<<" ";
		}
		k++;
    }
	
		cout<<endl<<"\nSorted Array:"<<endl;
	for (int i = 0; i < n; i++) {
		cout<<"Put crates moving out at time \""<<crates[i]<<"\" at position "<<(i+1)<<endl;
	}
}
