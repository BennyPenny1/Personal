#include <iostream>

#define MACRO(x) (x*x)

using namespace std;

inline int il(int x) {
    return x * x;
}
int main() {
    int x = 5;
    cout << "macro " << MACRO(x) << endl;
    cout << "const " << il(x) << endl; 
}

