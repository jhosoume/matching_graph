#ifndef SCHOOL
#define SCHOOL

#include <vector>

using ::std::vector;

class School {
public:
    School();
    School(int id, int num_pos, vector<int> skills_req);
    int vacancies();
    
    int id;
    int num_pos;
    vector<int> skills_req;
    vector<int> professors;
};

#endif
