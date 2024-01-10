//Q3_22K-4054_Nihal_Ali

#include <iostream>

using namespace std;

int main() {
	int row1,row2,col1,col2;
	
	// Matrix 1
	cout<<"Enter details for MATRIX 1:"<< endl;
	cout<<"Rows: "<< endl;
	cin>>row1;
	cout<<"Columns: "<< endl;
	cin>>col1;
	
	int mat1[row1][col1];   // Matrix 1 declaration 
	
	cout<<"Enter elements: \n";
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            cin>>mat1[i][j];
        }
    }
    
	// Matrix 2
	cout<<"\nEnter details for MATRIX 2:"<< endl;
	cout<<"Rows: "<< endl;
	cin>>row2;
	cout<<"Columns: "<< endl;
	cin>>col2;
	
	int mat2[row2][col2];    // Matrix 2 declaration 
	
	cout<<"Enter elements: \n";
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            cin>>mat2[i][j];
        }
    }
    
    int mat3[10][10];  // Multiplication result matrix declaration 
    
    // Initializing Matrix 3 with 0 due to garbarge value
    
    for (int i = 0; i < 10; i++) {
    	for (int j = 0; j < 10; j++) {
    		mat3[i][j] = 0;
		}
	}
	
	// Multiplication matrix logic 
	
    if (col1 == row2) {
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col2; j++) {
            	for (int m = 0; m < col1; m++) {
					mat3[i][j] += mat1[i][m] * mat2[m][j];  
				}
            }
        }
    }
    else {
    	cout<<"Matrix is not multipliable!" << endl;
	}
	
	cout<<"Matrix 1: \n";
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            cout<<" "<< mat1[i][j];
        }
        cout<< endl;
    }
    
    cout << endl;
    cout<<"Matrix 2: \n";
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            cout<<" "<< mat2[i][j];
        }
        cout<< endl;
    }
    
	// Multiplication Matrix output - Matrix 3
	
	cout << endl <<"Multiplication result: "<< endl;
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			cout<<" "<< mat3[i][j];
		}
		cout << endl;
	}
    
}