#include <iostream>

int main() {
    /* io
    std::string name;
    std::cout << "name: ";
    std::cin >> name;
    std::cout << "you name is " << name <<std::endl;
    */

    /* messages
    std::cout << "this is an output message" << std::endl;
    std::clog << "this is a log message" << std::endl;
    std::cerr << "this is an error message" << std::endl;
    */

    int age;
    std::string full_name;

    std::cout << "please type your full name and age: ";
    std::getline(std::cin, full_name);
    std::cin >> age;
    std::cout << full_name << " is " << age << " years old" <<std::endl;

}