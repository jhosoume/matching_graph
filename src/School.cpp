#include "School.hpp"

School::School()
    : id{-1}, num_pos{0}, skills_req{0}
    { professors.clear(); }

School::School(int id, int num_pos, int skills_req)
    : id{id}, num_pos{num_pos}, skills_req{skills_req}
    { professors.clear(); }

int School::vacancies() {
    return num_pos - professors.size();
}
