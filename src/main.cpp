#include <iostream>
#include <algorithm>
#include <vector>
#include "dog.h"
#include "shared_ptr.h"
#include "dog.h"

bool answer()
{
    char mean;
    while(true)
    {
        std::cin >> mean;
        std::cin.get();
        if(mean == 'y') return true;
        else if(mean == 'n')return false;
    }
}

void checkName(std::string& name)
{
    while(true)
    {
        auto it = std::find_if(name.begin(), name.end(), [](const char &c)
                               {
                                   return !std::isalpha(c);
                               });
        if(it == name.end())
            return;
        std::cout << "Enter the correct name: ";
        getline(std::cin, name);
    }
}

void checkAge(int& age)
{
    while(age < 0 || age > 30)
    {
        std::cout << "Eter the correct age: ";
        std::cin >> age;
    }
}

void listToys(std::vector<shared_ptr_toy<Toy>>& toys)
{
    std::cout << "List toys: " << std::endl;
    for(int i = 0; i < toys.size(); ++i)
    {
        std::cout << i+1 << " - " << toys[i].get().getToy() << std::endl;
    }
}

void checklist(int& num, int&& maxSize)
{
    while(num > maxSize)
    {
        std::cout << "Enter the correct number: ";
        std::cin >> num;
    }
}

void initialization(std::vector<Dog>& dogs, std::vector<shared_ptr_toy<Toy>>& toys,bool ans[])
{
    int count = 0;
    for(int i = 0; i < 2; ++i)
        if(ans[i])
            count+=(i + 1);

    if(count == 0) dogs.push_back(Dog());
    else if(count == 1)
    {
        std::string name;
        std::cout << "Enter the name dog: ";
        getline(std::cin, name);
        checkName(name);
        dogs.push_back(Dog(name));
    }
    else if(count == 2)
    {
        int age;
        std::cout << "Enter the age dog: ";
        std::cin >> age;
        checkAge(age);
        dogs.push_back(Dog(age));
    }
    else if(count == 3)
    {
        std::string name;
        int age;
        std::cout << "Enter the name dog: ";
        getline(std::cin, name);
        checkName(name);
        std::cout << "Enter the age dog: ";
        std::cin >> age;
        checkAge(age);
        listToys(toys);
        std::cout << "Is the dog`s favorite toy on the list?" << std::endl;
        if(answer())
        {
            int number;
            std::cout << "Enter the number toy: ";
            std::cin >> number;
            checklist(number, toys.size());
            dogs.push_back(Dog(name, age, make_shared_toy<Toy>(toys[number-1])));
        }
        else
        {
            std::string toy;
            std::cout << "Enter the name toy: ";
            getline(std::cin, toy);
            checkName(toy);
            toys.push_back(make_shared_toy<Toy>(toy));
            dogs.push_back(Dog(name, age, make_shared_toy<Toy>(toys[toys.size()-1])));
        }
    }
}

void separator(char&& symbol)
{
    std::cout << std::endl;
    for(int i = 0; i < 40; ++i)
        std::cout << symbol;
    std::cout << std::endl;
}

int main()
{
    std::vector<Dog> dogs;
    std::vector<shared_ptr_toy<Toy>> toys;
    std::cout << "The program implements a smart pointer." << std::endl;

    while(true)
    {
        std::string name;
        std::cout << "Add a toy to a dog." << std::endl;
        std::cout << "Enter the name of the toy: ";
        getline(std::cin, name);
        checkName(name);
        toys.push_back(make_shared_toy<Toy>(name));
        std::cout << "Countinue adding toys?" <<std::endl;
        if(!answer())
            break;
        separator('-');
    }
    std::cout << std::endl;
    while(true)
    {
        bool mean[2];
        std::cout << "To add a dog, answer a couple of questions: " << std::endl;
        for(int i =0; i < 2 ; ++i)
        {
            if(i == 0)
            {
                std::cout << "Does the dog have a name?(y/n)" << std::endl;
                mean[i] = answer();
            }
            if(i == 1)
            {
                std::cout << "Does the dog have an age?(y/n)" << std::endl;
                mean[i] = answer();
            }
        }

        initialization(dogs, toys, mean);

        std::cout << "Continue entering dogs?(y/n)" << std::endl;
        if(!answer())
            break;
        separator('=');
    }
    std::cout << std::endl;
    for(int i = 0; i < dogs.size(); ++i)
    {
        std::cout << dogs[i] << std::endl;
        if(i!=(dogs.size()-1))separator('/');
    }

    return 0;
}
