#pragma once
#include"MyInt.h"
#include<iostream>
#include<utility>
#include<string>

/**
 * @brief klasa przchowujaca tablice elementow MyInt
 * 
 */
class MyArray{
    friend class MyInt;
    friend std::ostream& operator<<(std::ostream &strm, const MyArray &a);
public:
    MyArray(int n=0): _size(0), _tab(new MyInt[n]){};

    /**
     * @brief Construct a new My Array object using already exsisting object
     * 
     * @param arr 
     */
    MyArray(const MyArray& arr){
        _size = arr.size();
        _tab = new MyInt[_size];
        for(int i=0; i<_size; i++){
            _tab[i].value() = arr._tab[i].value();
        }
    };
    
    MyArray(MyArray &&a){
        _size = std::exchange(a._size, 0);
        _tab = new MyInt[_size];
        for(int i=0; i<_size; i++){
            _tab[i].value() = std::exchange(a._tab[i].value(), 0);
        }
    }
    
    ~MyArray(){
        delete[] _tab;
    }

    /**
     * @brief zwraca rozmiar przechowywany w kalsie
     * 
     * @return int 
     */
    int size()const{return _size;};

    /**
     * @brief operator [] zwracajacy n-ty element w _tab (bez zmieniania warotsci)
     * 
     * @param n 
     * @return MyInt 
     */
    int& operator[](int n)const{
        return _tab[n%_size].value();
    };

    /**
     * @brief operator ++ zwiekszajacy 
     * 
     * @param n 
     * @return MyArray 
     */
    MyArray operator++(int){
        MyArray *tmp = this;
        for(int i=0; i<_size; i++){
            (tmp->_tab[i].value())++;
        }
        return *tmp;
    }
    
    MyArray& operator=(const MyArray& a){
        if(&a==this) return *this;
        
        delete[] _tab;
        
        _size = a._size;
        _tab = new MyInt[_size];
        for(int i=0; i<_size; i++){
            _tab[i].value() = a._tab[i].value();
        }
        return *this;
    };
    
protected:
    MyInt *_tab;
    int _size;

};

/**
 * @brief operator << do drukowania dla elementow MyArray
 * 
 * @param ostrm 
 * @param a 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &strm, const MyArray &a){
    strm<<"[";
    for(int i=0; i<a.size(); i++){
        strm << a._tab[i].value() << ",";
    }
    strm<<a._tab[a.size()-1].value()<<"]";
    return strm;
}