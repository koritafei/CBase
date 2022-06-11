/**
 * @file vptrdemo.cpp
 * @author koritafei (koritafei@gmail.com)
 * @brief 验证虚函数指针的存在性
 * @version 0.1
 * @date 2020-06-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>

class AB{
    public:
        virtual void f(){
            std::cout << "Base virtual function" << std::endl;
        }
        int n;
};

class AAB : public AB {
    public:
        void f(){
            std::cout << "DeviedA AB virtual function" << std::endl;
        }
};

class BAB : public AB {
    public:
        void f(){
            std::cout << "DeviedB AB virtual function" << std::endl;
        }
};

class CAB : public AB {
    public:
        void f(){
            std::cout << "DeviedC AB virtual function" << std::endl;
        }
};

class C {
};

class D {
    public:
        virtual void f(){
            std::cout << "Base virtual function" << std::endl;
        }
};

class E {
    public:
        void f(){
            std::cout << "Base virtual function" << std::endl;
        }
};

class F {
    public:
        int n;
};

int main(int argc,char** argv){
    AB a;
    AAB aab;
    BAB bab;
    CAB cab;
    C c;
    D d;
    E e;
    F f;
    char* vptr = reinterpret_cast<char*> (&a);
    char* an = reinterpret_cast<char*> (&a.n);

    if (vptr == an){
        std::cout << "vptr not exsit" << std::endl; 
        std::cout << "vptr = " << vptr << "\t an = " << an << std::endl;
    }else{
        std::cout << "vptr exsit" << std::endl; 
        std::cout << "vptr = " << &a << "\t an = " << &a.n << std::endl;
    }

    std::cout << "AB = " << &a << "\tsizeof(AB) = " << sizeof(a) << std::endl;
    std::cout << "AAB = " << &aab << "\tsizeof(AAB) = " << sizeof(aab) << std::endl;
    std::cout << "BAB = " << &bab << "\tsizeof(BAB) = " << sizeof(bab) << std::endl;
    std::cout << "CAB = " << &cab << "\tsizeof(CAB) = " << sizeof(cab) << std::endl;
    std::cout << "C = " << &c << "\tsizeof(C) = " << sizeof(c) << std::endl;
    std::cout << "F = " << &f << "\tsizeof(F) = " << sizeof(f) << std::endl;
    std::cout << "D = " << &d << "\tsizeof(D) = " << sizeof(d) << std::endl;
    std::cout << "E = " << &e << "\tsizeof(E) = " << sizeof(e) << std::endl;
}

