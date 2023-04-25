#include"List.h"
#include<iostream>
#include<vector>
#include<functional>

void List::insert(int x){
    _list.push_back(x);
}

void List::print(const char *c)const{
    std::cout << c << "[";
    for(int i=0; i<_list.size(); i++){
        std::cout << " " << _list[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void List::print()const{
    std::cout << "[";
    for(int i=0; i<_list.size(); i++){
        std::cout << " " << _list[i] << " ";
    }
    std::cout << "]" << std::endl;
}

List List::filter(std::function<bool(int)> fun)const{
    List tmp;
    for(int i=0; i<_list.size(); i++){
        if(fun(i)){
          tmp._list.push_back(i);
        }
    }
return tmp;
}