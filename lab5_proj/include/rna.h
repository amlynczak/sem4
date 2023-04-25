#pragma once
#include<vector>

enum Nukleotyp{
    A='A', // adeine 
	G='G', // guanine
	C='C', // citozine
	T='T', // thymine
	U='U'  // uracil
};

class RNA{
    friend std::ostream &operator<<(std::ostream &ostrm, const RNA &a);
public:
    RNA(std::vector<Nukleotyp> a): _nuk(a) {};

    RNA mutate(){
        RNA mutated(*this);
        if(!mutated._nuk.empty()){
            Nukleotyp first = mutated._nuk.front();
            mutated._nuk.erase(mutated._nuk.begin());
            mutated._nuk.push_back(first);
        }
        return mutated;
    };
    void operator=(const RNA *a){
        for(int i=0; i<_nuk.size(); i++){
            _nuk[i] = a->_nuk[i];
        }
    }
    int getSize()const{return _nuk.size();};

protected:
    std::vector<Nukleotyp> _nuk;

};

std::ostream &operator<<(std::ostream &ostrm, const RNA &a){
    for(int i=0; i<a._nuk.size(); i++){
        ostrm << (char)a._nuk[i] << " ";
    }
    ostrm << std::endl;
    return ostrm;
}

