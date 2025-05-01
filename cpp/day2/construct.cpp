#include <iostream>

class point {
    public:
    point() {
        x = 0;
        y = 0;
    }
    point(double x_val, double y_val) {
        x = x_val;
        y = y_val;
    }
    point(double x_val) {
        x = x_val;
        y = 0;
    }
    int get_x() {
        return x;
    }
    int get_y() {
        return y;
    }
    void change_x(int x_val) {
        x = x_val;
    }
    void change_y(int y_val) {
        y = y_val;
    }
    void change_val(int x_val, int y_val) {
        x = x_val;
        y = y_val;
    }
    friend std::ostream& operator<<(std::ostream& out, const point& p);
    private:
    double x, y;

};

int main() {
    point p = point();

    std::cout << "x: " << p.get_x() << " y: " << p.get_y() << "\n";
    std::cout << p <<"\n";

    p.change_val(4, 5);
    std::cout << p << "\n";

    p.change_x(5);
    p.change_y(4);

    std::cout << "x: " << p.get_x() << " y: " << p.get_y() << "\n";

    point p2 = point(5, 8);

    std::cout << p2 <<"\n";
}

std::ostream& operator<<(std::ostream& out, const point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
