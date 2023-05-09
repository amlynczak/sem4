#pragma once
#include"greaterclass.h"
#include<iostream>
#include<vector>

/**
 * @brief template do zwracania wiekszego elementu
 * 
 * @tparam T 
 * @param a 
 * @param b 
 * @return const T& 
 */
template<typename T> const T& Tmax(const T &a, const T &b){
    return ((a>b)? a:b);
}

/**
 * @brief template do konversji
 * 
 * @tparam T 
 * @tparam S 
 * @param a 
 * @return T 
 */
template<typename T, typename S> T convert(S a){
    return (T)a;
}

/**
 * @brief template do swap
 * 
 * @tparam T 
 * @param a 
 * @param b 
 */
template<typename T> void Tswap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

/**
 * @brief template max
 * 
 * @tparam T 
 * @param v 
 * @return const T 
 */
template<typename T> const T Tmax(std::vector<T> v){
    size_t size = v.size();
    T max = v[0];
    for(size_t i=0; i<size; i++){
        max = Tmax(max, v[i]);
    }
    return max;
}