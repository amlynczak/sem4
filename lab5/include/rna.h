#pragma once
#include<vector>

/**
 * @brief zbior nukleotypow
 * 
 */
enum Nukleotyp{
    A='A', // adeine 
	G='G', // guanine
	C='C', // citozine
	T='T', // thymine
	U='U'  // uracil
};

/**
 * @brief klasa RNA przechowujaca wektor z nukleotypami
 * 
 */
class RNA{
    /**
     * @brief zaprzyjazniony operator <<
     * 
     * @param ostrm 
     * @param a 
     * @return std::ostream& 
     */
    friend std::ostream &operator<<(std::ostream &ostrm, const RNA &a);
public:
    /**
     * @brief Construct a new RNA object
     * 
     * @param a 
     */
    RNA(std::vector<Nukleotyp> a): _nuk(a) {};

    /**
     * @brief mutuje rna w danej klasie (przesuwa o jedno miejsce)
     * 
     * @return RNA 
     */
    RNA mutate(){
        RNA mutated(*this);
        if(!mutated._nuk.empty()){
            Nukleotyp first = mutated._nuk.front();
            mutated._nuk.erase(mutated._nuk.begin());
            mutated._nuk.push_back(first);
        }
        _nuk = mutated._nuk;
        return mutated;
    };

    /**
     * @brief operator = dla RNA
     * 
     * @param a 
     */
    void operator=(const RNA *a){
        for(int i=0; i<_nuk.size(); i++){
            _nuk[i] = a->_nuk[i];
        }
    }

    /**
     * @brief Get the Size object
     * 
     * @return int 
     */
    int getSize()const{return _nuk.size();};

    /**
     * @brief zwraca wektror z nukleotypami
     * 
     * @return std::vector<Nukleotyp> 
     */
    std::vector<Nukleotyp> get_RNA(){return _nuk;};

protected:
    std::vector<Nukleotyp> _nuk;

};

/**
 * @brief operator <<, zaprzyjazniony z RNA
 * 
 * @param ostrm 
 * @param a 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &ostrm, const RNA &a){
    for(int i=0; i<a._nuk.size(); i++){
        ostrm << (char)a._nuk[i] << " ";
    }
    ostrm << std::endl;
    return ostrm;
}

