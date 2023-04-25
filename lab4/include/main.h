#pragma once
#include<iostream>

/**
 * @brief klasa product dla wszystkich produktow
 * 
 */
class Product{
public:
    /**
     * @brief Construct a new Product object
     * 
     * @param name nazwa produktu
     * @param price cena produktu
     */
    Product(std::string name, double price): p_name(name), p_price(price){};

    /**
     * @brief defaultowe wypisywanie
     * 
     */
    void Wypisz(){
        std::cout << p_name << " Cena: " << p_price << std::endl;
    }
protected:
    std::string p_name;
    double p_price;
};