#pragma once
#include"school.h"
#include<iostream>
#include<vector>

class School;

class Student{
public:
    Student(std::string name, int points, std::vector<School*> schools): _name(name), _points(points), _preferred_schools(schools), _acceptedIn(nullptr) {};

    void print()const;
    std::string getName()const;
    int getPoints()const;
    School* getAcceptedSchool()const;
    void setAcceptedIn(School* school);
    std::vector<School*> getPreferredSchools()const;
protected:
    std::string _name;
    int _points;
    std::vector<School*> _preferred_schools;
    School* _acceptedIn;
};