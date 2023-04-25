#pragma once
#include "shapes.h"

/// klasa Rectangle 
/// posiada konstruktor, gettery, metodę isIn, area i diagonal 

class Rectangle : public Shape, public HasDiagonal, public BasicShape { // TODO dziedziczenie
public:
    /**
     * @brief Construct a new Rectangle object
     * 
     * @param Ax wspolzedna x puntu pierwszego
     * @param Ay wspolzedna y punktu pierwszego
     * @param Bx wspolzedna x punktu drugiego
     * @param By wspolzedna y punktu drugiego
     */
    Rectangle(int Ax, int Ay, int Bx, int By){
        _A = Point(Ax, Ay);
        _B = Point(Bx, By);
    }

    /**
     * @brief Construct a new Rectangle object
     * 
     * @param A punkt 1
     * @param B punkt 2
     */
    Rectangle(Point A, Point B){
        _A = A;
        _B = B;
    };

    /**
     * @brief sprawdza, czy dany punkt o wspolzednych a, b jest w polu danej figury
     * 
     * @param a 
     * @param b 
     * @return true 
     * @return false 
     */
    bool isIn(int a, int b)const;

    /**
     * @brief zwraca pole prostokata
     * 
     * @return double 
     */
    double area()const;

    /**
     * @brief zwraca dlugosc przekatnej prostokata
     * 
     * @return double 
     */
    double diagonal()const;

    

private:
    Point _A;
    Point _B;
};