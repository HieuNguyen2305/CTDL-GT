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
    int M;
    cin>>M;
    int n=0;
    int m=0;
    int *a= new int[N];
    int b[N][2];
    int count;
    for (int i = 2; i < N; i++) {
        count=BlumCheck(i);
        if(count != 1){
            a[n]=i;
            n++;
        }
    }
    for(int i=0;i<N-1;i++){
        for( int j=1;j<N;j++){
            for(int k=j+1;k<N;k++){
                if(a[k]==a[i]+a[j]){
                    b[m][1]=a[i];
                    b[m][2]=a[j];
                    m++;
                }
            }
        }
    }
    for (int i=0;i<N;i++){
        if (M==a[i]){
            cout<<"M la so blum nho hon N";
        }
        else cout<<"M khong la so blum trong mang";
    }
    return 0;
}
