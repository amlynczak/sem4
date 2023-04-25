#pragma once
#include"Operation.h"
#include<cmath>

class Exponentiation:public Operation{
public:
    Exponentiation();
    Exponentiation(double a, double b): Operation(a, b, "^") {};

    double eval()const{
        return pow(_a,_b);
    };
};