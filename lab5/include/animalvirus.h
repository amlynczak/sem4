#pragma once
#include<iostream>
#include<string>
#include<vector>

/**
 * @brief klasa AnimalVirus posaidajaca dodatowa informacje o zwierzeciu, ktore go przenosi
 * 
 */
class AnimalVirus : public Virus{
public:
    /**
     * @brief Construct a new Animal Virus object
     * 
     */
    AnimalVirus() = default;

    /**
     * @brief Construct a new Animal Virus object
     * 
     * @param name 
     * @param animal 
     * @param a 
     */
    AnimalVirus(std::string name, std::string animal, std::vector<Nukleotyp> a): Virus(name), _animal(animal){
        _rna = new RNA(a);
    };

    /**
     * @brief Construct a new Animal Virus object using already existing object
     * 
     * @param avir 
     */
    AnimalVirus(AnimalVirus& avir): _animal(avir._animal){
        if(avir._rna != nullptr){
            _rna = new RNA(*avir._rna);
        }else{
            _rna = nullptr;
        }
        _name = avir._name;
        _age = 0;
        avir._age++;
        std::cout << avir._animal<< " mutacja -> " << avir._name << " Wiek: " << avir._age <<std::endl;
    }

    /**
     * @brief Construct a new Animal Virus object using already existing object
     * 
     * @param avir 
     */
    AnimalVirus(const AnimalVirus& avir): _animal(avir._animal){
        if(avir._rna != nullptr){
            _rna = new RNA(*avir._rna);
        }else{
            _rna = nullptr;
        }
        _name = avir._name;
        _age = 0;
        std::cout << avir._animal<< " mutacja -> " << avir._name << " Wiek: " << avir._age <<std::endl;
    }

    /**
     * @brief Construct a new Animal Virus object (moving one)
     * 
     * @param avir 
     */
    AnimalVirus(AnimalVirus&& avir): AnimalVirus(avir){
        std::cout << avir._animal<< " replikacja -> " << avir._name << " Wiek: " << avir._age <<std::endl;
    };

    /**
     * @brief opearotr = dla AnimalVirus&
     * 
     * @param avir 
     * @return AnimalVirus& 
     */
    AnimalVirus& operator=(AnimalVirus& avir){
        _name = avir._name;
        _age = avir._age;
        _animal = avir._animal;
        _rna = new RNA(avir._rna->get_RNA());
        avir._age++;
        return *this;
    }

    /**
     * @brief operator = dla AnimalVirus&&
     * 
     * @param avir 
     * @return AnimalVirus& 
     */
    AnimalVirus& operator=(AnimalVirus&& avir){
        _name = avir._name;
        _age = avir._age;
        _animal = avir._animal;
        _rna = new RNA(avir._rna->get_RNA());
        avir._age++;
        return *this;
    }

    /**
     * @brief Get the name object
     * 
     * @return std::string 
     */
    std::string get_name(){return _name;};

    /**
     * @brief Get the age object
     * 
     * @return int 
     */
    int get_age(){return _age;};

    /**
     * @brief zwraca RNA z klasy
     * 
     * @return RNA* 
     */
    RNA *get_RNA(){return _rna;};

    /**
     * @brief Get the animal host object
     * 
     * @return std::string 
     */
    std::string get_animal_host(){return _animal;};



private:
    std::string _animal;
};