#pragma once
#include"student.h"
#include<iostream>
#include<vector>

class Student;

class School{
public:
    School(std::string name, int seats): _name(name), _maxSeats(seats){};

    std::string getclass()const;
    int getmax()const;
    void print()const;
    bool freeSeats()const;
    void addStudent(Student *student);

protected:
    std::string _name;
    int _maxSeats;
    std::vector<Student*> _accepted;
};