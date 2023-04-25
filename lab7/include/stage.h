/// @file stage.h

#pragma once
#include "shapes.h"
#include <iostream>

/// @brief klasa drukująca kształty na std::ostream
class Stage {
public:
    /// @brief konstruktor
    Stage(int width=0, int heigh=0, char sign ='*') : _width(width), _heigh(heigh), _sign(sign) {};
  
    /// @brief funkcja drukująca kształty
    void drawShape(const Shape*, std::ostream &  = std::cout) const;

private:
    int _width; /// szerokość wydruku
    int _heigh; /// wysokość wydruku
    char _sign; /// rodzaj znaku
};
