#include <iostream>
#include <vector>

class performer {
    public:
    virtual void perform() {
        std::cout << "Error: base class perform called" << "\n";
    }
};
class jester : public performer {
    public:
    void perform() override {
        std::cout << "jester makes a joke" << "\n";
    }
};
class actor : public performer {
    public:
    void perform() override {
        std::cout << "actor acts" << "\n";
    }
};

int main() {
    std::vector<performer*> performance;
    performance.push_back(new actor());
    performance.push_back(new jester());
    for (std::vector<performer*>::iterator performer = performance.begin(); performer < performance.end(); performer++) {
        (*performer)->perform();
    }
}
