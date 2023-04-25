#pragma once
#include "rna.h"
#include<iostream>
#include<vector>

class Virus{
    friend class RNA;
public:
    /**
     * @brief Construct a new Virus object
     * 
     */
    Virus() = default;

    /**
     * @brief Construct a new Virus object
     * 
     * @param name 
     */
    Virus(std::string name): _name(name), _rna(nullptr), _age(0) {};

    /**
     * @brief Construct a new Virus object using aleady existing object
     * 
     * @param a 
     */
    Virus(const Virus& a) : _name(a._name), _age(0) {
        if(a._rna != nullptr){
            _rna = new RNA(*a._rna);
        }else{
            _rna = nullptr;
        }
        //a.increase_age();
    }

    /**
     * @brief Construct a new Virus object using already existing object
     * 
     * @param a 
     */
    Virus(Virus& a) : _name(a._name), _age(0) {
        if(a._rna != nullptr){
            _rna = new RNA(*a._rna);
        }else{
            _rna = nullptr;
        }
        a.increase_age();
    }

    /**
     * @brief Construct a new Virus object(move )
     * 
     * @param a 
     */
    Virus(Virus&& a):Virus(a){
        _rna->mutate();
        _name += "-"+std::to_string(a._age);
    }

    /**
     * @brief opearotr = dla Virus&
     * 
     * @param a 
     * @return Virus& 
     */
    Virus& operator=(Virus& a){
        _name = a._name;
        _age = a._age;
        _rna = new RNA(a._rna->get_RNA());
        a._age++;
        return *this;
    }

    /**
     * @brief operator= dla Virus&&
     * 
     * @param a 
     * @return Virus& 
     */
    Virus& operator=(Virus&& a){
        _name = a._name;
        _age = a._age;
        _rna = new RNA(a._rna->get_RNA());
        a._age++;
        return *this;
    }

    /**
     * @brief Get the name object
     * 
     * @return std::string 
     */
    std::string get_name(){return _name;};

    /**
     * @brief zwraca rna
     * 
     * @return RNA* 
     */
    RNA *get_RNA(){return _rna;};

    /**
     * @brief Get the age object
     * 
     * @return int 
     */
    int get_age(){return _age;};

    /**
     * @brief zwieksza wiek o 1
     * 
     */
    void increase_age(){_age++;}

    /**
     * @brief ustala RNA
     * 
     * @param rna 
     */
    void set_RNA(std::vector<Nukleotyp> rna){
        if (_rna != nullptr){
            delete _rna; 
        }
        _rna = new RNA(rna);
    }
    
protected:
    std::string _name;
    RNA *_rna;
    mutable int _age;
};