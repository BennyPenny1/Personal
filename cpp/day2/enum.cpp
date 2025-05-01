#include <iostream>

enum days {MON, TUE, WED, THU, FRI, SAT, SUN};

int main() {


    int f = SUN;
    std::cout << f << "\n";
    f++;
    std::cout << f << "\n";
    f--;
    std::cout << f << "\n";
}
days operator++(days d) {
    return static_cast<days>((static_cast<int>(d) + 1) % 7);
}
days operator--(days d) {
    int x = (static_cast<int>(d) - 1);
    if (x < 0) {
        return SUN;
    }
    else {
        return static_cast<days>(x);
    }
}
