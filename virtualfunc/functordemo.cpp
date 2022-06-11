/**
 * @brief        : 
 * @Author       : koritafei
 * @Date         : 2020-05-09 15:17:36 +0800
 * @Email        : koritafei@gmail.com
 * @LastEditors  : koritafei
 * @LastEditTime : 2020-05-09 15:25:05 +0800
 * */

#include <iostream>

/**
 * @brief 函数对象，functor
 * 
 * @tparam T 
 */
template <typename T>
class Less_than{
    public:
    
        Less_than(const T& v):val(v){
        }

        bool operator()(const T& v) const{
            return v < val;
        }
    private:
        const T val;
};


int main(int argc,char** argv){
    Less_than<int> li{42};
    std::cout << li(54) << std::endl;
    
}
