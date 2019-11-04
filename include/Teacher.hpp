#ifndef TEACHER
#define TEACHER

#include <vector>

using ::std::vector;

/**
 * \class Teacher
 * \brief Class to store state values of a teacher in a matching problem
 * \author: jhosoume
 * \date: 2019/11/02 20:00:00
 *
 * Contact: ju.hosoume@gmail.com
 */
class Teacher {
public:
    Teacher();
    Teacher(int id, int num_skills, vector<int> preferences);
    bool is_assigned();
    bool operator< (const Teacher& other) const;

    int id;
    int num_skills;
    vector<int> school_prefs;
    int matched_school;
    bool assigned;
};

#endif
