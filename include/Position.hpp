#ifndef POS
#define POS

#include "Teacher.hpp"

class Position {
public:
    Position();
    Position(int skill_req);
    bool operator< (const Position& other) const;

    int skill_req;
    bool matched;
    Teacher teacher; //id
    int teacher_pref;
};


#endif
