#pragma once
#include "shapes.h"

/// klasa ShapeComposite 
/// posiada konstruktor oraz metodę isIn

enum class ShapeOperation { INTERSECTION, SUM, DIFFERENCE };

class ShapeComposite : public Shape {
public:
    /**
     * @brief Construct a new Shape Composite object
     * 
     * @param sh1 shape 1
     * @param sh2 shape 2
     * @param oper typ operacji
     */
    ShapeComposite(std::shared_ptr<const Shape> sh1, std::shared_ptr<const Shape> sh2, ShapeOperation oper){
        _sh1 = sh1;
        _sh2 = sh2;
        _oper = oper;
    };

    /**
     * @brief zwraca true or false zaleznie od danego typu operacji - do rysowania polaczen ksztaltow
     * 
     * @param a 
     * @param b 
     * @return true 
     * @return false 
     */
    bool isIn(int a, int b) const override{
        if(_oper == ShapeOperation::INTERSECTION){
            return _sh1->isIn(a, b) && (_sh2->isIn(a, b));
        }
        if(_oper == ShapeOperation::SUM){
            return _sh1->isIn(a, b) || (_sh2->isIn(a, b));
        }
        if(_oper == ShapeOperation::DIFFERENCE){
            return _sh1->isIn(a, b) && !(_sh2->isIn(a, b));
        }
        return false;
    }

private:
    std::shared_ptr<const Shape> _sh1;
    std::shared_ptr<const Shape> _sh2;
    ShapeOperation _oper;
};