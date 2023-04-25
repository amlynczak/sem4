#pragma once
#include"Operation.h"

class Division:public Operation{
public:
    Division();
    Division(double a, double b): Operation(a, b, "/") {};
    
    double eval()const{
        return (_a/_b);
    }

};