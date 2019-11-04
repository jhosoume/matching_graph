#include "School.hpp"

/**
 * School constructor.
 * Defines default values for the basic attributes.
 * @param id School identifier
 * @param num_pos Number of positions that a School has in a matching
 * @param skills_req Skills required for each position
 * @return School with default values.
 */
School::School()
    : id{-1}, num_pos{0}
    { positions.clear(); }

School::School(int id, int num_pos, vector<int> skills_req)
    : id{id}, num_pos{num_pos}
    {
        positions.clear();
        for (int req : skills_req) {
            positions.push_back(Position(req));
        }
        if (num_pos != skills_req.size()) {
            throw "Number of position avaiable and skills are not equal";
        }
    }

int School::vacancies() {
    int occuppied = 0;
    for (Position pos : positions) {
        if (pos.matched) ++occuppied;
    }
    return num_pos - occuppied;
}

/**
 * Includes a teacher in a position without cheking if the position was previously occupied.
 * @param pos_indx Index of the position in the school
 * @param teacher Teacher to be included in the position
 * @param pref Indicates the preference level of the teacher to occupy the position
 */
void School::assign_teacher(const int& pos_indx, Teacher& teacher, const int& pref) {
    teacher.assigned = true;
    teacher.matched_school = id;
    positions.at(pos_indx).teacher = teacher;
    positions.at(pos_indx).matched = true;
    positions.at(pos_indx).teacher_pref = pref;
}

bool School::is_full() {
    for (Position pos : positions) {
        if (!pos.matched) return false;
    }
    return true;
}

bool School::is_empty() {
    for (Position pos : positions) {
        if (pos.matched) return false;
    }
    return true;
}

/**
 * Includes a new teacher in a position without cheking if the position was previously occupied.
 * @param pos_indx Index of the position in the school
 * @param teacher New teacher to be included in the position
 * @param pref Indicates the preference level of the new teacher to occupy the position
 */
int School::change_teacher(const int& pos_indx, Teacher& teacher, const int& pref) {
    int old_teacher_id = positions.at(pos_indx).teacher.id;
    teacher.assigned = true;
    teacher.matched_school = id;
    positions.at(pos_indx).teacher = teacher;
    positions.at(pos_indx).matched = true;
    positions.at(pos_indx).teacher_pref = pref;
    return old_teacher_id;
}
