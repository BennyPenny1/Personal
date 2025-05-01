#include <iostream>

const int N = 40;
int Sum(int x) {
    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += i;
    }
    return sum;
}
int main() {
    int sum = Sum(N);
    std::cout << "sum: " << sum << std::endl;
}