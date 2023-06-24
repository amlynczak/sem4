#include"table.h"
#include<numeric>

Table::Table(std::vector<Student>& students){
    for(const auto& student : students){
        _candidates.push_back(new Student(student));
    }
}

Table::Table(School *school){
    _schools.push_back(school);
}

void Table::printStud()const{
    for(const auto& student: _candidates){
        student->print();
    }
    std::cout<<std::endl;
}

void Table::sortpoints(){
    std::sort(_candidates.begin(), _candidates.end(), [](const Student* a, const Student* b) {
                  return a->getPoints() > b->getPoints();
              }
            );
}

void Table::recruit(){
    for (auto& student : _candidates) {
        bool accepted = false;
        for (auto& school : student->getPreferredSchools()) {
            if (school->freeSeats()) {
                school->addStudent(student);
                student->setAcceptedIn(school);
                accepted = true;
                break;
            }else{
               student->setAcceptedIn(nullptr);
            }
        }
    }
}

double Table::getAverageStudScore()const{
    if (_candidates.empty()) {
        return 0.0;
    }
    double sum = std::accumulate(_candidates.begin(), _candidates.end(), 0.0,
        [](double total, const Student* student) {
            return total + student->getPoints();
        }
    );
    return sum / _candidates.size();
}

void Table::printRecruit()const{
    for (const auto& school : _schools) {
        school->print();
    }
}

void Table::operator+=(const Student& candidate){
    Student* newCandidate = new Student(candidate);
    _candidates.push_back(newCandidate);
}

void Table::operator+=(School* school){
    _schools.push_back(school);
}
