#include "dog.h"
#include <iostream>


Dog::Dog(const std::string& _name, int& _age, shared_ptr_toy<Toy> _myToy) : name(_name), age(_age), myToy(_myToy){}

Dog::Dog(const std::string& _name) : name(_name), age(0), myToy(){}

Dog::Dog(int& _age) : name("No name"), age(_age), myToy(){}

Dog::Dog() : name("No name"), age(0), myToy(){}

std::ostream& operator<<(std::ostream& out, const Dog& dog)
{
        out << "Name dog: " << dog.name << "\nAge: " << dog.age << "\nLovely toy: " << dog.myToy.get().getToy() << std::endl;
        return out;
}
