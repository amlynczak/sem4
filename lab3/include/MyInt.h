#pragma once
#include<iostream>

/**
 * @brief klasa MyInt zawierajaca wartosci
 * 
 */
class MyInt{
    friend std::ostream& operator<<(std::ostream& strm, const MyInt &a);
public:
    /**
     * @brief Construct a new My Int object
     * 
     */
    MyInt() = default;

    /**
     * @brief Construct a new My Int object
     * 
     * @param size 
     */
    MyInt(size_t size){};

    /**
     * @brief Destroy the My Int object
     * 
     */
    ~MyInt() = default;

    /**
     * @brief zwraca wartosc przechowywana w klasie
     * 
     * @return int& 
     */
    int& value(){return _val;};
    int value()const{return _val;};

    void *operator new[](std::size_t size)throw(){
        size = size/sizeof(MyInt);
        std::cout << "--- NEW[] --- rozmiar = " <<  size - 2 <<" sizeof = " << size*sizeof(MyInt) << std::endl;
        void *tmp = ::new MyInt[size];
        return tmp;
    };

    /**
     * @brief usuwanie zaalokowanego wskaznika wyswietlajac jednoczesnie rozmiar
     * 
     * @param ptr 
     */
    void operator delete[](void *ptr, std::size_t size)throw(){
        std::cout << "--- DELETE[] --- rozmiar = " << size/sizeof(MyInt) << std::endl;
        ::delete [] static_cast<MyInt*>(ptr);
    };

    /**
     * @brief operator = przypisujacy wartosc do _val
     * 
     * @param n 
     * @return int 
     */

private:
    int _val;
};

/**
 * @brief operator << dla MyInt
 * 
 * @param ostrm 
 * @param a 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &ostrm, const MyInt &a){
    return ostrm<<a.value();
}