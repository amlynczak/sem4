#include"school.h"
#include"student.h"
#include"table.h"

std::string School::getclass()const{
    return _name;
}

int School::getmax()const{
    return _maxSeats;
}

void School::print()const{
    std::cout << _name << " - " << _maxSeats << ": ";
    if (_accepted.empty()){
        std::cout << "brak przyjetych" << std::endl;
    }else{
        for(const auto& student : _accepted){
            std::cout << std::endl;
            std::cout << student->getName() << ": " << student->getPoints() << " ";
            if (student->getAcceptedSchool() == this){
                std::cout << "--> " << _name;
            }else{
                std::cout << "--> nieprzyjety";
            }
        }
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}

bool School::freeSeats()const{
    return _accepted.size() < _maxSeats;
}

void School::addStudent(Student *student){
    _accepted.push_back(student);
}