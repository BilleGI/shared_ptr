#pragma once
#include "toy.h"
#include "shared_ptr.h"
#include <string>


class Dog
{
public:
    explicit Dog(const std::string& _name, int& _age, shared_ptr_toy<Toy> _myToy);
    explicit Dog(const std::string& _name);
    explicit Dog(int& _age);
    explicit Dog();
    friend std::ostream& operator<<(std::ostream& out, const Dog& dog);
private:
    std::string name;
    int age;
    shared_ptr_toy<Toy> myToy;
};
