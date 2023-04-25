#pragma once
#include "rna.h"
#include<vector>

class Virus{
    friend class RNA;
public:
    Virus(std::string name): _name(name), _rna(nullptr), _age(0) {};
    Virus(const Virus& a) : _name(a._name), _age(0) {
        if(a._rna != nullptr){
            _rna = new RNA(*a._rna);
        }else{
            _rna = nullptr;
        }
        //a.increase_age();
    }

    std::string get_name(){return _name;};
    RNA *get_RNA(){return _rna;};
    int get_age(){return _age;};
    void increase_age(){_age++;}
    void set_RNA(std::vector<Nukleotyp> rna){
        if (_rna != nullptr){
            delete _rna; 
        }
        _rna = new RNA(rna);
    }
    
protected:
    std::string _name;
    RNA *_rna;
    int _age;
};