#pragma once
#include<iostream>
#include<string>
#include<vector>

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
    virtual double eval() = 0;
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
    /**
     * @brief zwraca liczbe dziesietna zrobiona z ulamka
     * 
     * @return double 
     */
    double eval(){
        return ((double)_licznik/(double)_mianownik);
    }
    /**
     * @brief zwraca licznik
     * 
     * @return int 
     */
    int getA(){return _licznik;}
    /**
     * @brief zwraca mianownik
     * 
     * @return int 
     */
    int getB(){return _mianownik;}
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
        std::cout << "\"" <<_str << "\"";
    }
    double eval(){
        return 0;
    }
private:
    std::string _str;
};

class CharData : public Data{
public:
    /**
     * @brief Construct a new Char Data object
     * 
     * @param c 
     */
    CharData(const char& c): _c(c){};
    /**
     * @brief drukuje dany znak zapisany w _c
     * 
     */
    void print()const{
        std::cout << "'" << _c << "'";
    }
    double eval(){
        return 0;
    }
private:
    char _c;
};