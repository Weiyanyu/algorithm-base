//
// Created by 72419 on 2018/3/15 0015.
//

#ifndef CPP_STUDENT_H
#define CPP_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int score;

    bool operator<(const Student &other) {
        return score != other.score ? score < other.score : name < other.name;
    }

    friend ostream& operator<<(ostream &os, const Student &student) {
        os << "Student: " << student.name << " " << student.score << endl;
        return os;
    }
};

#endif //CPP_STUDENT_H
