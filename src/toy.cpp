#include "toy.h"


Toy::Toy() : Toy("No name") {};

Toy::Toy(const std::string& _name) : name(_name){};

std::string Toy::getToy()
{
    return name;
}

