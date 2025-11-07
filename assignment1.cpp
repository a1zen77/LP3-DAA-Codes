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
void fibonacci_iterative(int n) {
    int a = 0, b = 1, next;
    for (int i = 0; i < n; i++) {
        if (i <= 1)
            next = i;
        else {
            next = a + b;
            a = b;
            b = next;
        }
        cout << next << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << endl;
    cout << "Fibonacci Series (Iterative): ";
    fibonacci_iterative(n);
    cout << endl;
    cout << "Fibonacci Series (Recursive): ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci_recursive(i) << " ";
    }
    cout << endl;
    return 0;
}