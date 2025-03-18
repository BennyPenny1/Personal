#include <iostream>

enum days {SUN, MON, TUE, WED, THU, FRI, SAT};

int main() {


    int f = SUN;
    std::cout << f << "\n";
    f++;
    std::cout << f << "\n";
}
days operator++(days d) {
    return static_cast<days>((static_cast<int>(d) + 1) % 7);
}
