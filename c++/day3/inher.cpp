#include <iostream>

class vehicle {
    public:
    virtual void start() {
        std::cout << "vroom" << "\n";
    }
   virtual void stop() {
        std::cout << "moorv" << "\n";
    }
};
class toyota : public vehicle {
    public:
    void toy_yoda() {
        std::cout << "last forever i do" << "\n";
    }
    void start() override {
        std::cout << "vroom im a toyota" << "\n";
    }
};

int main() {
    toyota tacoma;
    tacoma.start();
    tacoma.toy_yoda();
    vehicle car;
    car.start();
}
