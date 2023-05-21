//#include "shared_ptr.h"
//#include <utility>

//template<class Type>
//shared_ptr_toy<Type> ::shared_ptr_toy(Type& new_ptr)
//{
//    count = new int(1);
//    ptr = new Type;
//    *ptr = new_ptr;
//}

//template<class Type>
//shared_ptr_toy<Type>::shared_ptr_toy()
//{
//    count = new int(1);
//    ptr = new Type;
//}

//template<class Type>
//shared_ptr_toy<Type>::shared_ptr_toy(const shared_ptr_toy& other) : ptr(other.ptr), count(other.count)
//{
//    ++(*count);
//}

//template<class Type>
//shared_ptr_toy<Type>& shared_ptr_toy<Type>:: operator=(shared_ptr_toy& other)
//{
//    if(this->ptr == other.ptr)
//        return *this;
//    if(this->ptr != nullptr)
//    {
//        --(*count);
//        this->ptr = other.ptr;
//        this->count = other.count;
//        ++(*count);
//    }
//    return *this;
//}

//template<class Type>
//shared_ptr_toy<Type>::~shared_ptr_toy()
//{
//    --(*count);
//    if((*count) == 0)
//    {
//        delete count;
//        delete ptr;
//    }
//}
//template<class Type>

//int shared_ptr_toy<Type>::use_count() const
//{
//    return *count;
//}

//template<class Type>
//Type shared_ptr_toy<Type>::get() const
//{
//    return *ptr;
//}

//template<class Type>
//void shared_ptr_toy<Type>::del()
//{
//    --(*count);
//    if((*count) == 0)
//    {
//        delete count;
//        delete ptr;
//    }
//    else ptr = nullptr;
//}


//template<class Type>
//shared_ptr_toy<Type> make_shared_toy(shared_ptr_toy<Type>& other)
//{
//    shared_ptr_toy<Type> ptr_toy(other);
//    return ptr_toy;
//}

//template<class Type, class Name>
//shared_ptr_toy<Type> make_shared_toy(Name&& name)
//{
//    Type play(std::forward<Name>(name));
//    shared_ptr_toy<Type> ptr_toy(play);
//    return ptr_toy;
//}
