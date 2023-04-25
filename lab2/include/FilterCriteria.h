#pragma once
#include<iostream>
#include<vector>
#include<functional>


/**
 * @brief klasa FilterCriteria przetrzymujaca vector z kryteriami
 * 
 */
class FilterCriteria{
public:
    /**
     * @brief dodaje funkcje do wektora
     * 
     */
    void add(std::function<bool(int)>);

    /**
     * @brief zwraca dana funkcje(z danego miejsca)
     * 
     * @param n 
     * @return std::function<bool(int)> 
     */
    std::function<bool(int)> get(int n)const;

    /**
     * @brief zwraca rozmiar
     * 
     * @return int 
     */
    int size()const;


private:
    std::vector<std::function<bool(int)>> _criteria;
};