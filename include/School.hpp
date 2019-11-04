#ifndef SCHOOL
#define SCHOOL

#include <vector>
#include <exception>

#include "Position.hpp"
#include "Teacher.hpp"

using ::std::vector;

/**
 * \class School
 * \brief Class to store state values of a school in a matching problem
 * \author: jhosoume
 * \date: 2019/11/02 20:00:00
 *
 * Contact: ju.hosoume@gmail.com
 */
class School {
public:
    School();
    School(int id, int num_pos, vector<int> skills_req);
    int vacancies();
    void assign_teacher(const int& pos_indx, Teacher& teacher, const int& pref);
    bool is_full();
    bool is_empty();
    int change_teacher(const int& pos_indx, Teacher& teacher, const int& pref);

    int id;
    int num_pos;
    vector<Position> positions;
};

#endif
