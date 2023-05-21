#pragma once

template<class Type>
class shared_ptr_toy
{
public:
    explicit shared_ptr_toy(Type& new_ptr)
    {
        count = new int(1);
        ptr = new Type;
        *ptr = new_ptr;
    }

    explicit shared_ptr_toy()
    {
        count = new int(1);
        ptr = new Type;
    }



    shared_ptr_toy(const shared_ptr_toy& other) : ptr(other.ptr), count(other.count)
    {
        ++(*count);
    }

    shared_ptr_toy& operator=(shared_ptr_toy& other)
    {
        if(this->ptr == other.ptr)
            return *this;
        if(this->ptr != nullptr)
        {
            --(*count);
            this->ptr = other.ptr;
            this->count = other.count;
            ++(*count);
        }
        return *this;
    }

    ~shared_ptr_toy()
    {
        --(*count);
        if((*count) == 0)
        {
            delete count;
            delete ptr;
        }
    }

    int use_count() const
    {
        return *count;
    }

    Type get() const
    {
        return *ptr;
    }

    void del()
    {
        --(*count);
        if((*count) == 0)
        {
            delete count;
            delete ptr;
        }
        else ptr = nullptr;
    }

private:
    Type* ptr;
    int* count;
};

template<class Type>
shared_ptr_toy<Type> make_shared_toy(shared_ptr_toy<Type>& other)
{
    shared_ptr_toy<Type> ptr_toy(other);
    return ptr_toy;
}

template<class Type, class Name>
shared_ptr_toy<Type> make_shared_toy(Name&& name)
{
    Type play(std::forward<Name>(name));
    shared_ptr_toy<Type> ptr_toy(play);
    return ptr_toy;
}
