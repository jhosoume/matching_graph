#ifndef REC
#define REC

#include <vector>

#include "Teacher.hpp"
#include "School.hpp"

using ::std::vector;


class Recruiting {
public:
    Recruiting();
    void show();
    void read();
private:
    vector<Teacher> teachers;
    vector<School> schools;
};

#endif
