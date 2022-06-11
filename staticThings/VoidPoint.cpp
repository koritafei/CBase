/**
 * @file     VoidPoint.cpp
 * @brief   
 * @author   koritafei
 * @date     2020-11:16 上午
 */


#include <iostream>

int main(int argc, char **argv) {
    int i = 34;
    int &r = i;
    int *p = &i;

    std::cout << "i = " << i << "\n&i = " << &i << "\np = " << p << "\nr = "
              << r << "\n&r = "
                      "" << &r << std::endl;
    void *vp = (void *) p;
    std::cout << "vp = " << vp << "\nsizeof(void *) = " << sizeof(vp)
              << "\nsizeof(int *) = " << sizeof(int *) << "\nsizeof(double *)"
                                                          " = "
                                                          "" << sizeof(double
    *) <<
              "\nsizeof(unsigned "
              "char) = " << sizeof
                      (unsigned char) <<
              std::endl;

}


