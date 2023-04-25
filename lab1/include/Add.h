#pragma once
#include"Operation.h"

class Addition:public Operation{
public:
    Addition();
    Addition(const double a, double b): Operation(a, b, "+") {};

    double eval()const{
        return _a+_b;
    };

};