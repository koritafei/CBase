#include <iostream>

/**
 * @brief 处理第一个参数
 * 
 * @tparam T 
 * @param head 
 */
template <typename T>
void g(T head){
    std::cout << head << " ";
}

/**
 * @brief 参数为空的处理
 * 
 */
void f(){
}

/**
 * @brief 可变模板函数
 * 
 * @tparam T 
 * @tparam Tail 
 * @param head 
 * @param tail 
 */
template <typename T,typename...Tail>
void f(T head,Tail...tail){
    g(head);
    f(tail...);
}


int main(int argc, char** argv){
    std::cout<<"First : ";
    f(1,2,"wer","sfsdf");
    std::cout << std::endl;
    std::cout<<"Second : ";
    f(1,"dasdasd","wer","sfsdf");
    std::cout << std::endl;
}
