#include <iostream>

class point {
    public:
    void change_x(int xin) {
        if (xin > -50 && xin < 50) {
            x = xin;
        }
        else {
            std::cerr << "x must be -50 < x < 50\n";
        }
    }
    void change_y(int yin) {
        if (yin > -50 && yin < 50) {
            y = yin;
        }
        else {
            std::cerr << "y must be -50 < y < 50\n";
        }
    }

    private:
    double x = 0, y = 0;

    public:
    void show_x() {
        std::cout << x << "\n";
    }
    void show_y() {
        std::cout << y << "\n";
    }
    friend std::ostream& operator<<(std::ostream& out, point& p);
};

int main() {

    point p;
    p.change_x(6);
    p.change_y(5);

    std::cout << p << "\n";
}
std::ostream& operator<<(std::ostream& out, point& p){
    out << "x: " << p.x << "\n" << "y: " << p.y << "\n";
    return out;
}
