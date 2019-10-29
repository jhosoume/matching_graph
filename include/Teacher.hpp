#ifndef TEACHER
#define TEACHER

#include <vector>

#include "School.hpp"

using ::std::vector;

class Teacher {
public:
    Teacher();
    Teacher(int id, int num_skills, vector<int> preferences);
    bool is_assigned();
private:
    int id;
    int num_skills;
    vector<int> school_prefs;
    School matched_school;
    bool assigned;

};

#endif
