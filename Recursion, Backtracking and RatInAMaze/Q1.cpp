#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n;
    cout << "Enter number of terms for which you want to print Fibonacci Series: ";
    cin >> n;

    cout << "Fibonacci Series till " << n << " Terms:\n";

    for (int i = 1; i <= n; ++i) {
        cout << fib(i) << ((i != n) ? ", " : ".");
    }

    return 0;
}
