/**
 * @file SingletonExtra.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// brief: a singleton base class offering an easy way to create singleton
#include <iostream>
/*
template<typename T>
class Singleton{
public:
    static T& get_instance(){
        static T instance;
        return instance;
    }
    virtual ~Singleton(){
        std::cout<<"destructor called!"<<std::endl;
    }
    Singleton(const Singleton&)=delete;
    Singleton& operator =(const Singleton&)=delete;
protected:
    Singleton(){
        std::cout<<"constructor called!"<<std::endl;
    }

};*/
/********************************************/
// Example:
// 1.friend class declaration is requiered!
// 2.constructor should be private

/*
class DerivedSingle:public Singleton<DerivedSingle>{
   // !!!! attention!!!
   // needs to be friend in order to
   // access the private constructor/destructor
   friend class Singleton<DerivedSingle>;
public:
   DerivedSingle(const DerivedSingle&)=delete;
   DerivedSingle& operator =(const DerivedSingle&)= delete;
private:
   DerivedSingle()=default;
};*/

// int main(int argc, char* argv[]){
//     DerivedSingle& instance1 = DerivedSingle::get_instance();
//     DerivedSingle& instance2 = DerivedSingle::get_instance();
//     return 0;
// }


// brief: a singleton base class offering an easy way to create singleton
#include <iostream>

template<typename T>
class Singleton{
public:
    static T& get_instance() noexcept(std::is_nothrow_constructible<T>::value){
        static T instance{Token()};
        return instance;
    }
    virtual ~Singleton() =default;
    Singleton(const Singleton&)=delete;
    Singleton& operator =(const Singleton&)=delete;
protected:
    struct Token{}; // helper class
    Singleton() noexcept=default;
};


/********************************************/
// Example:
// constructor should be public because protected `token` control the access

// This does not useful in C++11, for the list initialization 
class DerivedSingle:public Singleton<DerivedSingle>{
public:
   DerivedSingle(Token){
       std::cout<<"constructor called!"<<std::endl;
   }

   ~DerivedSingle(){
       std::cout<<"destructor called!"<<std::endl;
   }
   DerivedSingle(const DerivedSingle&)=delete;
   DerivedSingle& operator =(const DerivedSingle&)= delete;
};

int main(int argc, char* argv[]){
    DerivedSingle& instance1 = DerivedSingle::get_instance();
    DerivedSingle& instance2 = DerivedSingle::get_instance();
    DerivedSingle({});
    return 0;
}

#include <iostream>

class A
{
public:
    A() {
        std::cout<<"constructor" <<std::endl;
    }
    ~A(){
        std::cout<<"destructor"<<std::endl;
    }
};

// template<typename T>
// T& get_global(){
//     static T instance;
//     return instance;
// }

// int main(int argc, char *argv[])
// {
//     A& instance_1 = get_global<A>();
//     A& instance_2 = get_global<A>();
//     return 0;
// }

