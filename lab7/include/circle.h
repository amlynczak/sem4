#pragma once
#include "shapes.h"

/// klasa Circle 
/// posiada konstruktor, gettery, metodę isIn oraz area 

class Circle : public Shape, public BasicShape{ // TODO dziedziczenie
public:
    /**
     * @brief Construct a new Circle object
     * 
     * @param a wspolzedna x srodka
     * @param b wspolzedna y srodka
     * @param radius promien kola
     */
    Circle(int a, int b, int radius){
        _center = Point(a, b);
        _radius = radius;
    }

    /**
     * @brief Construct a new Circle object
     * 
     * @param cen punkt srodka
     * @param radius promien kola
     */
    Circle(Point cen, int radius){
        _center = cen;
        _radius = radius;
    }
    
    /**
     * @brief zwraca pole kola
     * 
     * @return double 
     */
    double area()const;

    /**
     * @brief wzraca, czy dany punkt jest w polu kola
     * 
     * @param a 
     * @param b 
     * @return true 
     * @return false 
     */
    bool isIn(int a, int b)const;
private:
    int _radius;
    Point _center;
};