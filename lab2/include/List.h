#pragma once
#include<iostream>
#include<vector>
#include<functional>

/**
 * @brief klasa posiadajaca liste
 * 
 */
class List{
public:
    /**
     * @brief Construct a new List object
     * 
     */
    List() = default;

    /**
     * @brief dodaje parametr do wektora _list
     * 
     * @param x 
     */
    void insert(int x);

    /**
     * @brief wyswietlanie listy z danym tekstem
     * 
     * @param c 
     */
    void print(const char *c)const;

    /**
     * @brief wyswiwtlanie listy bez tekstu
     * 
     */
    void print()const;

    /**
     * @brief filtruje liczby w wektorze za pomoca danej funkcji 
     * 
     * @return List 
     */
    List filter(std::function<bool(int)>)const;

    /**
     * @brief operator [] ktory zwraca liczbe z danej pozycji
     * 
     * @param x 
     * @return int& 
     */
    int& operator[](int x){
        return _list[x];
    };
    
private:
    std::vector<int> _list;
};