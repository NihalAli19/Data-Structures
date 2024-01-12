#include <iostream>
using namespace std;

void tailBubbleSort(int arr[], int i, int j, int n) {
    if (!(i < n - 1)) {
        return;
    }

    if (!(j < n - i - 1)) {
        tailBubbleSort(arr, i + 1, 0, n);
    } 
	else {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
        }
        tailBubbleSort(arr, i, j + 1, n);
    }
}

void nontailBubbleSort(int arr[], int i, int j, int n) {
    if (!(i < n - 1)) {
        return;
    }

    if (!(j < n - i - 1)) {
        nontailBubbleSort(arr, i + 1, 0, n);
    } 
	else {
        nontailBubbleSort(arr, i, j + 1, n);
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << arr[i] << ", ";
        } else {
            cout << arr[i] << "\n";
        }
    }
}

int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int arr2[] = {20, 11, 15, 1, 2, 3};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Array 1:" << endl;
    cout << "Before Sorting: ";
    printArray(arr1, n1);

    tailBubbleSort(arr1, 0, 0, n1);

    cout << "After Sorting: ";
    printArray(arr1, n1);

    cout << "Array 2:" << endl;
    cout << "Before Sorting: ";
    printArray(arr2, n2);

    nontailBubbleSort(arr2, 0, 0, n2);

    cout << "After Sorting: ";
    printArray(arr2, n2);
}
