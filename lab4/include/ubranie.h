#pragma once
#include<iostream>

/**
 * @brief klasa ubranie dla spodni i koszul
 * 
 */
class Ubranie: public Product{
public:
    /**
     * @brief Construct a new Ubranie object
     * 
     * @param name 
     * @param price 
     */
    Ubranie(std::string name, double price): Product(name, price){};

    /**
     * @brief prasowanie dla wszystkich
     * 
     * @param a 
     */
    void Prasuj(Zelazko a){
        if(p_wyprasowanie == false){
            std::cout << "---Prasuje Koszula bawelniana zelazkiem o temp. " << a.getTemp() << std::endl;
            p_wyprasowanie = true;
        }else{
            std::cout << "---Ubranie nie wymaga prasowania. "<<std::endl;
        }
    };

    /**
     * @brief gniecenie
     * 
     */
    void Pogniec(){
        if(p_wyprasowanie == true){
            p_wyprasowanie = false;
        }
    }

    
protected:
    bool p_wyprasowanie;
};

/**
 * @brief klasa koszula dla koszul jedwabnej oraz bawelnanej
 * 
 */
class Koszula: public Ubranie{
public:
    /**
     * @brief Construct a new Koszula object
     * 
     * @param name 
     * @param price 
     * @param dlugosc 
     */
    Koszula(std::string name, double price, int dlugosc): Ubranie(name, price), p_dlugosc(dlugosc) {};

    /**
     * @brief skraca rekawy
     * 
     */
    void SkrocRekawy(){
        if(p_dlugosc == true){
            p_dlugosc = false;
        }
    };
    
    /**
     * @brief wypisuje dla koszul
     * 
     */
    void Wypisz(){
        std::string wyp;
        std::string dlug;
        if(p_wyprasowanie == true){
            wyp = "Wyprasowane.";
        }else{wyp = "Pogniecione.";};

        if(p_dlugosc == true){
            dlug = "Dlugi rekaw.";
        }else{dlug = "Krotki rekaw.";}
        std::cout << p_name << " Cena: " << p_price << " " << wyp << " " << dlug << std::endl;
    }
protected:
    bool p_dlugosc;
};

/**
 * @brief klasa spodnie dla spodni
 * 
 */
class Spodnie: public Ubranie{
public:
    /**
     * @brief Construct a new Spodnie object
     * 
     * @param name 
     * @param price 
     * @param kant 
     * @param maxTemp 
     */
    Spodnie(std::string name, double price, int kant, int maxTemp): Ubranie(name, price), p_kant(kant), p_maxTemp(maxTemp) {};
     
     /**
      * @brief prasowane kantow
      * 
      * @param a 
      */
    void PrasujKanty(Zelazko a){
        if(a.getTemp()>p_maxTemp){
            std::cout << "Zelazko za gorace." << std::endl;
        }else{
            if(p_wyprasowanie == false){
                p_wyprasowanie = true;
            }else{
                std::cout << "---Ubranie nie wymaga prasowania." << std::endl;
            }
        };
        
    };

    /**
     * @brief wypisz dla spodni
     * 
     */
    void Wypisz(){
        std::string wyp;
        std::string kant;
        if(p_wyprasowanie == true){
            wyp = "Wyprasowane.";
        }else{wyp = "Pogniecione.";};

        if(p_kant== true){
            kant = "Kanty";
        }else{kant = "Brak Kantow.";}
        std::cout << p_name << " Cena: " << p_price << " " << wyp << " " << kant << std::endl;
    }
protected:
    bool p_kant;
    int p_maxTemp;
};

/**
 * @brief koszula jedwabna
 * 
 */
class KoszulaJedwabna: public Koszula{
public:
    /**
     * @brief Construct a new Koszula Jedwabna object
     * 
     * @param price 
     * @param dlug 
     */
    KoszulaJedwabna(double price, int dlug): Koszula("koszula jedwabna ", price, dlug){};
protected:

};

class KoszulaBawelniana: public Koszula{
public:
    /**
     * @brief Construct a new Koszula Bawelniana object
     * 
     * @param price 
     * @param dlug 
     */
    KoszulaBawelniana(double price, int dlug): Koszula("koszula bawelniana ", price, dlug){};
protected:

};

class SpodnieJedwabne: public Spodnie{
public:
    /**
     * @brief Construct a new Spodnie Jedwabne object
     * 
     * @param price 
     */
    SpodnieJedwabne(double price): Spodnie("spodnie jedwabne ", price, 0, 3){};

protected:

};

class SpodnieBawelniane: public Spodnie{
public:
    /**
     * @brief Construct a new Spodnie Bawelniane object
     * 
     * @param price 
     */
    SpodnieBawelniane(double price): Spodnie("spodnie bawelniane", price, 0, 7){};
protected:

};