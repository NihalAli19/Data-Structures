#include <iostream>
using namespace std;

struct dates {
	int day;
	int month;
	int year;
};

int main() {
	int n = 0, k = 1;
	
	cout<<"Enter the number of dates you want to store: ";
	cin>>n;
	
	dates d[n];
	
	for (int i = 0; i < n; i++) {
		cout<<"Day: ";
		cin>>d[i].day;
		cout<<"Month: ";
		cin>>d[i].month;
		cout<<"Year: ";
		cin>>d[i].year;
	}
	
	int min = 0, temp = 0;
	
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i+1; j < n; j++) {
			if (d[j].year < d[min].year) {
				min = j;	
			}	
		}
		
		temp = d[i].year;
		d[i].year = d[min].year;
		d[min].year = temp;
		
		temp = d[i].month;
		d[i].month = d[min].month;
		d[min].month = temp;
		
		temp = d[i].day;
		d[i].day = d[min].day;
		d[min].day = temp;
		
		cout<<endl<<"\n"<<k<<" pass:"<<endl;
		for (int i = 0; i < n; i++) {
			cout<<""<<d[i].day<<"/"<<d[i].month<<"/"<<d[i].year<<endl;
		}
		k++;
	}
		cout<<endl<<"\nSorted Array:"<<endl;
		for (int i = 0; i < n; i++) {
			cout<<""<<d[i].day<<"/"<<d[i].month<<"/"<<d[i].year<<endl;
		}
}
