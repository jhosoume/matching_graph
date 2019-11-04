#include "Position.hpp"

Position::Position()
    : skill_req{0}, matched{false}, teacher_pref{5}
    { }

Position::Position(int skill_req)
    : skill_req{skill_req}, matched{false}, teacher_pref{5}
    { }

bool Position::operator< (const Position& other) const {
    return skill_req < other.skill_req;
}
