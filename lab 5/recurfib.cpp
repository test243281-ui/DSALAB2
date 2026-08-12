#include <iostream>
using namespace std;

// recursive function to return nth Fibonacci number (0-based)
int fib(int n) {
   if(n<=1) return n;
    return fib(n-1) + fib(n-2);
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    if (!(cin >> n) || n <= 0) return 0;

    // print Fibonacci series (0-based indexing)
    for (int i = 0; i < n; ++i) {
        cout << fib(i);
        if (i < n) cout << " ";
    }
    cout << '\n';
    return 0;
}