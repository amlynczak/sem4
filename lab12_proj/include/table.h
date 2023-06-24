#pragma once
#include"student.h"
#include"school.h"
#include<iostream>
#include<vector>
#include<algorithm>

class Student;
class School;

class Table{
public:
    Table(std::vector<Student*> students): _candidates(students) {};
    Table(std::vector<School*> schools): _schools(schools) {};
    Table(std::vector<Student>& students);
    Table(School *school);

    void printStud()const;
    void sortpoints();
    void recruit();
    double getAverageStudScore()const;
    void printRecruit()const;

    void operator+=(const Student& candidate);
    void operator+=(School* school);
protected:
    std::vector<School*> _schools;
    std::vector<Student*> _candidates;
};