#pragma once
#include"Data.h"

class Sum{
public:
    /**
     * @brief Construct a new Sum object
     * 
     * @param val 
     */
    Sum(double val): _val(val){};

    /**
     * @brief zwraca _val
     * 
     * @return double 
     */
    double value(){
        return _val;
    };

    /**
     * @brief operator () dodaje do _val wartosc w nawiasie
     * 
     * @param a 
     */
    void operator()(int a){
        _val = _val + (double)a;
    }

private:
    double _val;
};

/**
 * @brief zwraca sume wektora w data
 * 
 * @param a 
 * @return Sum 
 */
Sum sumData(const Data& a){
    return Sum(a.sumVec());
}