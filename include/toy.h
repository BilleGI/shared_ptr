#pragma once
#include <string>

class Toy
{
public:
    explicit Toy();
    explicit Toy(const std::string& _name);

    std::string getToy();
private:
    std::string name;
};
