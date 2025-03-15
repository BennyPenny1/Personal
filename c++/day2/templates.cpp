#include <iostream>

using namespace std;

template <typename T>
void count(T x) {
    T count = static_cast <T>(0);
    for (T i = 0; i <= x; i++) {
        //cout << "i: " << i << endl;
        
        if (x - i >= 1) {
            cout << i << ", ";
        }
        else if (x - i == 0) {
            cout << i << endl;
        }
        else {
            cout << i << ", ";
            cout << x << endl;
        }
        
    }
}
int main() {
    int n = 4;
    float f = 12.5;
    double d = 12.56781292939;
    count(n);
    count(f);
    count(d);

}