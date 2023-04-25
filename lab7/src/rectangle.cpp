#include"rectangle.h"

bool Rectangle::isIn(int a, int b)const{
    double minX, maxX, minY, maxY;
    if(_A.x()<_B.x()){
        minX = _A.x();
        maxX = _B.x();
    }else{
        minX = _B.x();
        maxX = _A.x();
    }

    if(_A.y()<_B.y()){
        minY = _A.y();
        maxY = _B.y();
    }else{
        minY = _B.y();
        maxY = _A.y();
    }

    if(a<=maxX && a>=minX && b>=minY && b<=maxY){
        return true;
    }

    return false;

}

double Rectangle::area()const{
    double side1, side2;
    side1 = _A.x() - _B.x();
    side2 = _A.y() - _B.y();

    return side1*side2;
}

double Rectangle::diagonal()const{
    double side1, side2;
    side1 = _A.x() - _B.x();
    side2 = _A.y() - _B.y();

    double diag;
    diag = sqrt(side1*side1 + side2*side2);

    return diag;
}