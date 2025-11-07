#include <iostream>
using namespace std;

// Recursive function to calculate nth Fibonacci number
int fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Iterative function to calculate nth Fibonacci number
int fibonacci_iterative(int n) {
    if (n <= 1)
        return n;
    int a = 0, b = 1, next;
    for (int i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << endl;
    cout << "Fibonacci Series (Iterative): ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci_iterative(i) << " ";
    }
    cout << endl;
    cout << endl;
    cout << "Fibonacci Series (Recursive): ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci_recursive(i) << " ";
    }
    cout << endl;
    return 0;
}