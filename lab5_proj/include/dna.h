#pragma once
#include "rna.h"

class DNA{
    friend class RNA;
    friend std::ostream &operator<<(std::ostream &ostrm, const DNA &a);
public:
    DNA(RNA rna1, RNA rna2): _rna1(rna1), _rna2(rna2){};
private:
    RNA _rna1;
    RNA _rna2;

};

std::ostream &operator<<(std::ostream &ostrm, const DNA &a){
    int size = a._rna1.getSize();
    ostrm << a._rna1;
    for(int i=0; i<size; i++){
        ostrm << "| " ;
    }
    ostrm << std::endl;
    ostrm << a._rna2 << std::endl;
    return ostrm;
};