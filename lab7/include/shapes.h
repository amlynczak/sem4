#pragma once
/** @file shapes.h
 * Plik powinien zawierać wszystkie klasy bazowe (w całości zdefiniowane w pliku nagłówkowym)
 * 1. Proszę sobie stworzyć pomocniczą strukturę/klasę Point do trzymania współrzędnych.
 * 2. Klasa Shape powinna mieć metodę "isIn" (czy punkt leży wewnątrz figury).
 * 3. Klasa BasicShape powinna mieć metodę area(),
      należy też rozważyć przechowywanie w niej punktu i geterów do niego.
 * 4. Klasa HasDiagonal powinna mieć metodę diagonal().
 * 5. Pamiętajcie o słówku kluczowym "override".
**/

#include <cmath>
#include <memory>

/// @brief pomocnicza struktura Point
struct Point {
    Point(int x=0, int y=0) :_x{x}, _y{y} {}
    int x() const {return _x;}
    int y() const {return _y;}
private:
    int _x, _y;
};

/// klasa kształtów do rysowania
class Shape {  
public:
    /**
     * @brief wirtualna klasa do sprawdzenia czy dany punkt jest w polu danej figury
     * 
     * @param a 
     * @param b 
     * @return true 
     * @return false 
     */
    virtual bool isIn(int a, int b)const = 0;
};

/// klasa do liczenia pol zamknietych ksztaltów
class BasicShape { 
public:
    /**
     * @brief wirtualna klasa, ktora zwraca pole figury
     * 
     * @return double 
     */
    virtual double area()const = 0;

private:
};


/// klasa abstrakcyjna do liczenia przekątnej
class HasDiagonal { 
public:
    /**
     * @brief wirtualna klasa, ktora zwraca dlugosc przekatnej
     * 
     * @return double 
     */
    virtual double diagonal()const = 0;
};




