#include <iterator>
#include <iostream>

int main(int argc,char** argv){

    std::ostream_iterator<std::string> oo{std::cout};
    std::istream_iterator<std::string> ii{std::cin};
    std::istream_iterator<std::string> eos{};

    *oo = "Hello ";
    ++oo;
    *oo = "World!\n";
    std::string ss;

    ss = *ii;
    *oo = ss;

    return 0;
}
