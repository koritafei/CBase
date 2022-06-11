/**
 * @file reference.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 引用的实现解析
 * @version 0.1
 * @date 2020-06-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>

struct TRef{
    char &c;
};

class  ref_pointer_ch {
    public:
        char _ch;
        char& _ref;
        ref_pointer_ch(char ch):_ch(ch), _ref(_ch){}
};

int main(int argc,char** argv){
    int a = 10;
    int& ra = a;
    std::cout << "a address is " << &a << "\tra address is " << &ra << std::endl;
    std::cout << "a size is " << sizeof(a) << "\tra size is " << sizeof(ra) << std::endl;

    char ch = 'a';
    char &refch = ch;
    TRef ref {refch};
    std::cout << "char size is " << sizeof(ch) << "\tRef size is "<< sizeof(refch) << "\tReference size is " << sizeof(ref) << std::endl;
    ref_pointer_ch uch{ch};
    std::cout << "union address is " << &uch._ch << "\tunion reference is " << uch._ref << std::endl;
}

