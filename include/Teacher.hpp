#ifndef TEACHER
#define TEACHER

#include <vector>

using ::std::vector;

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
