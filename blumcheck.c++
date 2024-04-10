#include <iostream>
#include <cmath>
using namespace std;

// Kiểm tra số nguyên tố
int PrimeCheck(int n) {
    int count = 0;
    for (int i = 2; i <= n; i++)
        if (n % i == 0) count++;
    if (count == 1) return 1;
    else return 0;
}

// Kiểm tra số nửa nguyên tố Blum
int BlumCheck(int n) {
    int count = 1;
    for (int i = 2; i < sqrt(n); i++) {
        if (PrimeCheck(i) && PrimeCheck(n / i) && (i * (n / i) == n)) {
            cout << n << " là số Blum: " << n << " = " << i << "*" << n / i << endl;
            count++;
        }
    }
    if (count == 1) cout << n << " không phải số Blum" << endl;
    return count;
}

int main() {
    int N = 1000000; // Giá trị N = 10^6
    for (int i = 2; i < N; i++) {
        BlumCheck(i);
    }
    return 0;
}
