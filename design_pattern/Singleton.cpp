/**
 * @file Singleton.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-04
 * 
 * @copyright Copyright (c) 2022
 * cite from
 * https://www.cnblogs.com/sunchaothu/p/10389842.html
 */
#include <iostream>
#include <memory> // shared_ptr
#include <mutex>  // mutex
// version1:
// with problems below:
// 1. thread is not safe
// 2. memory leak
// 有缺陷的懒汉式
class Singleton{
private:
    Singleton(){
        std::cout<<"constructor called!"<<std::endl;
    }
    Singleton(Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
    static Singleton* m_instance_ptr;
public:
    ~Singleton(){
        std::cout<<"destructor called!"<<std::endl;
    }
    static Singleton* get_instance(){
        if(m_instance_ptr==nullptr){
              m_instance_ptr = new Singleton;
        }
        return m_instance_ptr;
    }
    void use() const { std::cout << "in use" << std::endl; }
};

// Singleton* Singleton::m_instance_ptr = nullptr;

// version 2:
// with problems below fixed:
// 1. thread is safe now
// 2. memory doesn't leak
// 线程安全、内存安全的懒汉式单例 （智能指针，锁
class Singleton{
public:
    typedef std::shared_ptr<Singleton> Ptr;
    ~Singleton(){
        std::cout<<"destructor called!"<<std::endl;
    }
    Singleton(Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
    static Ptr get_instance(){

        // "double checked lock"
        if(m_instance_ptr==nullptr){
            std::lock_guard<std::mutex> lk(m_mutex);
            if(m_instance_ptr == nullptr){
              m_instance_ptr = std::shared_ptr<Singleton>(new Singleton);
            }
        }

        return m_instance_ptr;
    }


private:
    Singleton(){
        std::cout<<"constructor called!"<<std::endl;
    }
    static Ptr m_instance_ptr;
    static std::mutex m_mutex;
};

// initialization static variables out of class
// Singleton::Ptr Singleton::m_instance_ptr = nullptr;
// std::mutex Singleton::m_mutex;

// int main(){
//     Singleton::Ptr instance = Singleton::get_instance();
//     Singleton::Ptr instance2 = Singleton::get_instance();
//     return 0;
// }


//最推荐的懒汉式单例(magic static )——局部静态变量
class Singleton
{
public:
    ~Singleton(){
        std::cout<<"destructor called!"<<std::endl;
    }
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
    static Singleton& get_instance(){
        static Singleton instance;
        return instance;
    }

private:
    Singleton(){
        std::cout<<"constructor called!"<<std::endl;
    }
};

int main(int argc, char *argv[])
{
    Singleton& instance_1 = Singleton::get_instance();
    Singleton& instance_2 = Singleton::get_instance();
    return 0;
}

