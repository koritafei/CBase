#include <iostream>
#include <string>

using std::cin;
using std::getline;
using std::cout;
using std::endl;

int main(int argc, char** argv){
    std::string str;
    while(getline(cin, str)){
        cout << str << endl;
    }
    return 0;
}

