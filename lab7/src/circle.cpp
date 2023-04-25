#include "circle.h"

double Circle::area()const{
    return M_PI * (double)_radius * (double)_radius;
}

bool Circle::isIn(int a, int b)const{

    double odleg, side1, side2;

    side1 = fabs(_center.x() - (double)a);
    side2 = fabs(_center.y()- (double)b);

    odleg = sqrt(side1*side1 + side2*side2);

    if(odleg <= _radius){
        return true;
    }

    

    return false;
}
