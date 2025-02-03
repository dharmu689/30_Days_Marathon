#include <iostream>
#include <cmath>

using namespace std;

void primeFactors(int n, int i = 2) {
    if (n <= 1) {
        return;
    }

    if (n % i == 0) {
        cout << i << endl;
        primeFactors(n / i, i); // Stay with the same divisor
    } else {
        primeFactors(n, i + 1); // Increment the divisor
    }
}

int main() {
    int n;
    cin >> n;
    primeFactors(n);
    return 0;
}