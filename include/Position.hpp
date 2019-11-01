#ifndef POS
#define POS

#include "Teacher.hpp"

class Position {
public:
    Position();
    Position(int skill_req);

    int skill_req;
    bool matched;
    Teacher teacher; //id
    int teacher_pref;
};


#endif
