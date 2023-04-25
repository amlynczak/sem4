#include"FilterCriteria.h"

void FilterCriteria::add(std::function<bool(int)>){
    
}

std::function<bool(int)> FilterCriteria::get(int n)const{
    return _criteria[n];
}

int FilterCriteria::size()const{
    return _criteria.size();
}