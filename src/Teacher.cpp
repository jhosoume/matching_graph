#include "Teacher.hpp"

Teacher::Teacher()
    : id{-1}, num_skills{0}
    { matched_school = School(); }

Teacher::Teacher(int id, int num_skills, vector<int> preferences)
    : id{id}, num_skills{num_skills}, school_prefs{preferences},
      assigned{false}
    { matched_school = School(); }

bool Teacher::is_assigned() {
    return assigned;
}
