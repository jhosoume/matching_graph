#ifndef REC
#define REC

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>

#include "Teacher.hpp"
#include "School.hpp"
#include "helper.hpp"

using ::std::string;
using ::std::vector;
using ::std::cout;
using ::std::endl;
using ::std::getline;
using ::std::stoi;


class Recruiting {
public:
    Recruiting();
    void show() const;
    void show_assignment() const;
    void read(const string& filename);
    int find_teacher_indx(int teacher_id);
    int find_school_indx(int school_id);
    bool shouldChange(Position& pos, Teacher& teacher);
    void galeShapley();

    vector<Teacher> teachers;
    vector<School> schools;
};

#endif
