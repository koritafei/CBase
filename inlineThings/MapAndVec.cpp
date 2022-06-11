/**
 * @brief        : 
 * @Author       : koritafei
 * @Date         : 2020-04-12 10:44:28 +0800
 * @Email        : koritafei@gmail.com
 * @LastEditors: koritafei
 * @LastEditTime: 2020-04-12 10:52:29 +0800
 * */

#include <vector>
#include <unordered_map>
#include <iostream>

using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;

int main(int argc, char** argv){
    unordered_map<int, std::string> map;
    map.insert(std::make_pair(1, "qwer"));
    map.insert(std::make_pair(2, "qw"));
    map.insert(std::make_pair(3, "qer"));
    map.insert(std::make_pair(4, "wer"));
    map.insert(std::make_pair(5, "qwe"));
    map.insert(std::make_pair(6, "qwr"));
    for(auto iter = map.begin(); iter != map.end(); iter++){
        cout << iter->first << '\t' << iter->second << endl;
    }
    vector<int> del{1,10,20,40,2,100,900};
    for(auto iter = del.begin(); iter != del.end(); iter++){
        cout << *iter << endl;
        if(map.count(*iter)){
            map.erase(*iter);
        }
    }

    for(auto iter = map.begin(); iter != map.end(); iter++){
        cout << iter->first << '\t' << iter->second << endl;
    }

    return 0;
}
