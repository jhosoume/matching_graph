#include "School.hpp"

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

int School::change_teacher(const int& pos_indx, Teacher& teacher, const int& pref) {
    int old_teacher_id = positions.at(pos_indx).teacher.id;
    teacher.assigned = true;
    teacher.matched_school = id;
    positions.at(pos_indx).teacher = teacher;
    positions.at(pos_indx).matched = true;
    positions.at(pos_indx).teacher_pref = pref;
    return old_teacher_id;
}
