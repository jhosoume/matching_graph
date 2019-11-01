#include "Teacher.hpp"

Teacher::Teacher()
    : id{-1}, num_skills{0}, matched_school{-1}
    {}

Teacher::Teacher(int id, int num_skills, vector<int> preferences)
    : id{id}, num_skills{num_skills}, school_prefs{preferences},
      assigned{false}, matched_school{-1}
    {}

bool Teacher::is_assigned() {
    return assigned;
}

bool Teacher::operator< (const Teacher& other) const {
    return num_skills < other.num_skills;
}
