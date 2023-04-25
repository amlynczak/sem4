#include"Operation.h"
#include<iostream>

void Operation::print()const{
    std::cout << _a << " " << _c << " " << _b << std::endl;
}

/*virtual double Operation::eval()const{
    return 0.;
}*/

void operator >>=(const char* c, const class Operation& x){
    std::cout << c << std::endl;
    x.print();

}