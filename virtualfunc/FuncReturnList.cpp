#include <iostream>
#include <vector>
#include <map>

std::vector<std::string> returnList(){
    return {"return", "list", "c++11"};
}

std::map<int, std::string> returnmap(){
    return {std::make_pair(1, "qwe"), std::make_pair(2, "sdfsdf")};
}

auto func() -> std::vector<std::string>{
    return {"first", "second", "three"};
}

int main(int argc, char** argv){
    std::vector<std::string> res{returnList()};
    for(auto iter : res){
        std::cout << iter << std::endl;
    }
    std::map<int, std::string> m{returnmap()};
    for(auto iter = m.begin(); iter != m.end(); iter++){
        std::cout << iter->first << '\t' << iter->second << std::endl;
    }

    res.clear();
    res = func();
    for(auto iter : res){
        std::cout << iter << std::endl;
    }
    return 0;
}
