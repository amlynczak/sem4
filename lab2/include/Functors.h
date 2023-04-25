#pragma once
#include<iostream>
#include<vector>
#include<functional>

/**
 * @brief klas DivisibleBy ktora "sprawdza" podzielnosc
 * 
 */
class DivisibleBy{
public:
    /**
     * @brief Construct a new Divisible By object
     * 
     * @param x 
     */
    DivisibleBy(int x): _x(x) {};

    /**
     * @brief operator() w ktorym podana jest liczba do porownania
     * 
     * @param n porownywana liczba
     * @return true 
     * @return false 
     */
    bool operator()(int n){
        return ((n%_x)==0);
    };

private:
    int _x;
};

/**
 * @brief klasa GreaterBy sprawdzajaca czy dana liczba jest wieksza od _x
 * 
 */
class GreaterThan{
public:
    /**
     * @brief Construct a new Greater Than object
     * 
     * @param x int do zapisu do _x
     */
    GreaterThan(int x): _x(x){};

    /**
     * @brief operator() w ktorym podana jest liczba do porownania
     * 
     * @param n sprawdzana liczba
     * @return true 
     * @return false 
     */
    bool operator()(int n){
        return (n >_x);
    };

private:
    int _x;
};