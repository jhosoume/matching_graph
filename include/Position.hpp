#ifndef POS
#define POS

#include "Teacher.hpp"

/**
 * \class Position
 * \brief Indicates that a school has a position to be filled by a teacher
 * \author: jhosoume
 * \date: 2019/11/02 20:00:00
 *
 * Contact: ju.hosoume@gmail.com
 */
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
