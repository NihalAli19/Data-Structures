#include <iostream>
using namespace std;

int fib1(int n);
int fib2(int n);

int fib1(int n) {
    if (n <= 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fib2(n - 1) + fib2(n - 2);
    }
}

int fib2(int n) {
    if (n <= 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fib1(n - 1) + fib1(n - 2);
    }
}

int main() {
    int n;
    cout << "Enter number of terms for which you want to print Fibonacci Series: ";
    cin >> n;

    cout << "Fibonacci Series till " << n << " Terms:\n";

    for (int i = 1; i <= n; ++i) {
        cout << fib1(i) << ((i != n) ? ", " : ".");
    }

    return 0;
}
