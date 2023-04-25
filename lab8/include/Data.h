#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>
#include<numeric>
#include<iomanip>

class Data{
public:
    /**
     * @brief Construct a new Data object
     * 
     * @param str 
     * @param vec 
     */
    Data(std::string str, std::initializer_list<double> vec): _str(str), _vec(vec){};

    /**
     * @brief drukuje element data - najpierw _str, pozniej wartosci w wektorze
     * 
     */
    void print()const{
        auto print = [](const double& n) { std::cout << std::setw(6) << n << ' '; };
        std::cout << _str << ": ";
        std::for_each(_vec.begin(), _vec.end(), print);
        std::cout << std::endl;
    };

    /**
     * @brief Get the Vector object
     * 
     * @return std::vector<double> 
     */
    std::vector<double> getVector()const{
        return _vec;
    }

    /**
     * @brief zwraca sume liczb zapisanych w wektorze
     * 
     * @return double 
     */
    double sumVec()const{
        double sum = std::accumulate(_vec.begin(), _vec.end(), 0.0);
        return sum;
    }
private:
    std::string _str;
    std::vector<double> _vec;
};