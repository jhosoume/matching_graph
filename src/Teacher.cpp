#include "Teacher.hpp"

/**
 * Teacher constructor.
 * Defines default values for the basic attributes.
 * @param id School identifier
 * @param num_skills Number of skills that a techear has
 * @param matched_school Index of the school in the schools vector of the matching
 */
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

/**
 * Comparator of teachers according to the number of skiils
 * @return True if the current teacher has less skills than the other position.
 */
bool Teacher::operator< (const Teacher& other) const {
    return num_skills < other.num_skills;
}
