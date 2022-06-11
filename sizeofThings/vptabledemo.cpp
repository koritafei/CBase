/**
 * @file vptabledemo.cpp
 * @author koritafei (koritafei@gmail.com)
 * @brief 虚函数表验证
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
            std::cout << "Base virtual f function" << std::endl;
        }

        virtual void g(){
            std::cout << "Base virtual g function" << std::endl;
        }

        int n;
};

class AAB : public AB {
    public:
        void f(){
            std::cout << "DeviedA AAB f function" << std::endl;
        }
};

class BAB : public AB {
    public:
        void f(){
            std::cout << "DeviedB BAB f function" << std::endl;
        }
};

class CAB : public AB {
    public:
        void f(){
            std::cout << "DeviedC CAB  f function" << std::endl;
        }
};

int main(int argc,char** argv){
    AB *a = new AB();
    AB *aab = new AAB();
    AB *bab = new BAB();
    AB *cab = new CAB();


    typedef void(*Func)(void);
    long* pvptr = (long*) bab;
    long* vptr = (long*) *pvptr;

    Func f = (Func)vptr[0];
    Func af = (Func)vptr[1];

    f();
    af();
    AB *b = dynamic_cast<AB*>(bab);
    pvptr = (long*) b;
    vptr = (long*) *pvptr;
    Func f1 = (Func)vptr[0];
    Func af1 = (Func)vptr[1];

    f1();
    af1();
}

