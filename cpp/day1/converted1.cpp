#include <iostream>

using namespace std;

const int N = 40;

inline int sum(int *p, int n, int d[]) {
    *p = 0;
    for (int i = 0; i < n; i++) {
        *p += d[i];
    }
    return *p;
}

int main () {
    int accum = 0;
    int data[N];

    for (int i = 0; i < N; i++) {
        data[i] = i;
    }
    int theSum = sum(&accum, N, data);
    cout << "sum: " << theSum << endl;
}