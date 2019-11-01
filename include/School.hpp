#ifndef SCHOOL
#define SCHOOL

#include <vector>
#include <exception>

#include "Position.hpp"
#include "Teacher.hpp"

using ::std::vector;

class School {
public:
    School();
    School(int id, int num_pos, vector<int> skills_req);
    int vacancies();
    void assign_teacher(const int& pos_indx, Teacher& teacher);
    bool is_full();

    int id;
    int num_pos;
    vector<Position> positions;
};

#endif
