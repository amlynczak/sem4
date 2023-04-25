#pragma once
#include<iostream>
#include<string>

/**
 * @brief klasa Data - 'rodzic'
 * 
 */
class Data {
    /**
     * @brief operator << do wypisywania elementow przy operatorze << w klasie List
     * 
     * @param ostrm 
     * @param a 
     * @return std::ostream& 
     */
    friend std::ostream &operator<<(std::ostream &ostrm, const Data &a){
        a.print();
        return ostrm;
    };
public:
    virtual void print()const = 0;
};

/**
 * @brief klasa Fraction posiadajaca licznik i mianownik
 * 
 */
class Fraction : public Data {
public:
    /**
     * @brief Construct a new Fraction object
     * 
     * @param licz 
     * @param mian 
     */
    Fraction(int licz, int mian = 1) : _licznik(licz), _mianownik(mian){}

    /**
     * @brief drukuje jeden element typu Fraction
     * 
     */
    void print() const {
        if(_mianownik != 1){
            std::cout << _licznik << "/" << _mianownik;
        }else{
            std::cout << _licznik;
        }
    }
private:
    int _licznik;
    int _mianownik;
};


/**
 * @brief klasa String Data posiadajaca napis
 * 
 */
class StringData : public Data {
public:
    /**
     * @brief Construct a new String Data object
     * 
     * @param s 
     */
    StringData(const std::string& s) : _str(s) {}

    /**
     * @brief drukuje napis zapisany w _str
     * 
     */
    void print() const {
        std::cout << _str;
    }
private:
    std::string _str;
};