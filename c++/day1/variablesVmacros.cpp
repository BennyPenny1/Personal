#include <iostream>

#define MACRO(x) (x*x);
using namespace std;
int main() {
    int x = 5;
    inline int il(x) {return x * x};
    cout << "macro " << MACRO(X) << endl;
    cout << "const " << il(x) << endl; 
}

