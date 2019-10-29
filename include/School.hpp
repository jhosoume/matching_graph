#ifndef SCHOOL
#define SCHOOL

#include <vector>

using ::std::vector;

class School {
public:
    School();
    School(int id, int num_pos, int skills_req);
    int vacancies();
private:
    int id;
    int num_pos;
    int skills_req;
    vector<int> professors;
};

#endif
