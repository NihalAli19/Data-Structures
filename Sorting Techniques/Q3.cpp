#include <iostream>
#include <string.h>
using namespace std;

int main() {
	
	string pos[6];
	int rank[6];
	int k = 1;
	
	for (int i = 0; i < 6; i++) {
		cout<<"Enter position name: ";
		cin>>pos[i];
		if (pos[i] == "CEO") {
			rank[i] = 1;
		}
		else if (pos[i] == "CTO") {
			rank[i] = 2;
		}
		else if (pos[i] == "CFO") {
			rank[i] = 3;
		}
		else if (pos[i] == "VP") {
			rank[i] = 4;
		}
		else if (pos[i] == "MGR") {
			rank[i] = 5;
		} 
		else if (pos[i] == "EMP") {
			rank[i] = 6;
		}
		else {
			break;
		}
	}
	
	int key;
	
	for (int i = 1; i < 6; i++) {
		key = rank[i]; 
		string posKey = pos[i];
		int j = i - 1;
		while ((j >= 0) && (rank[j] > key)) {
			rank[j+1] = rank[j];
			pos[j+1] = pos[j]; 
			j--;
		}
		rank[j+1] = key;
		pos[j+1] = posKey;
		cout<<endl<<"\n"<<k<<" pass:"<<endl;
		for (int i = 0; i < 6; i++) {
			cout<<pos[i]<<" ";
		}
		k++;
	}
	

	cout<<endl<<"\nSorted Array:"<<endl;
	for (int i = 0; i < 6; i++) {
		cout<<pos[i]<<" ";
	}
}
