#pragma once
/**
 * @brief klasa zelazko dla zelazek
 * 
 */
class Zelazko : public Product{
public:
    /**
     * @brief Construct a new Zelazko object
     * 
     * @param name 
     * @param price 
     * @param tempMax 
     */
    Zelazko(std::string name, double price, int tempMax): Product(name, price), p_tempMax(tempMax){};

    /**
     * @brief ustawia temperature zelazka w danej skali (jest ograniczenie w protected)
     * 
     * @param n 
     */
    void UstawTemperature(int n){
        if(n<=p_tempMax){ p_temp = n;}else{
            std::cout << "Ten model nie obsluguje takiego zakresu temperatur." << std::endl;
        }
    };

    /**
     * @brief Get the Temp object
     * 
     * @return int 
     */
    int getTemp(){
        return p_temp;
    }

    /**
     * @brief wypisanie dla zelazka
     * 
     */
    void Wypisz(){
        std::cout << p_name << " Cena: " << p_price << " Temperatura: " << p_temp << " Zakres: " << p_tempMax << std::endl;
    }
protected:
    int p_temp;
    int p_tempMax;
};

class ZelazkoTefal : public Zelazko{
public:
    /**
     * @brief Construct a new Zelazko Tefal object
     * 
     * @param price 
     */
    ZelazkoTefal(double price): Zelazko(" Tefal", price, 7){};
protected:
};

class ZelazkoPhilips : public Zelazko{
public:
    /**
     * @brief Construct a new Zelazko Philips object
     * 
     * @param price 
     */
    ZelazkoPhilips(double price): Zelazko(" Philips", price, 5){};

protected:
};