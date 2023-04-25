#pragma once

class Operation{

friend void operator >>=(const char* c, const class Operation& x);

public:
    Operation();
    Operation(double a, double b, const char *c): _a(a), _b(b), _c(*c) {};
    //~Operation();

    virtual double eval()const{
        return 0;
    };
    void print()const;


    
protected:
    double _a;
    double _b;
    char _c;

};

