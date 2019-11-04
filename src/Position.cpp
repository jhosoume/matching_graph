#include "Position.hpp"


/**
 * Postion constructor.
 * Defines default values for the basic attributes.
 * @param skill_req Suggested number of skills that a teacher should have to fill the position
 * @param matched Indicates if the position is filled
 * @param teacher_pref If the position is occupied, indicates the preference of the teacher
 * (lesser values greater the preference)
 * @return Position with default values.
 */
Position::Position()
    : skill_req{0}, matched{false}, teacher_pref{5}
    { }

Position::Position(int skill_req)
    : skill_req{skill_req}, matched{false}, teacher_pref{5}
    { }

/**
 * Comparator of positions according to the skill required.
 * @return True if the current position has less skill requirements than the other position.
 */
bool Position::operator< (const Position& other) const {
    return skill_req < other.skill_req;
}
