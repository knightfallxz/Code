#include <iostream>
#include <memory>
#include <string>

struct Person {
    std::shared_ptr<Person> friend1;
    std::shared_ptr<Person> friend2;
    std::shared_ptr<std::string> name;

    Person(const std::string& personName)
        : name(std::make_shared<std::string>(personName)) {}

    ~Person() { std::cout << "~Person() for " << *name << std::endl; }
};

int main() {
    auto person1 = std::make_shared<Person>("knightfall");
    auto person2 = std::make_shared<Person>("azrael");
    person1->friend2 = person2;
    person2->friend1 = person1;
    person1->friend2 = nullptr;
    person2->friend1 = nullptr;
    return 0;
}

