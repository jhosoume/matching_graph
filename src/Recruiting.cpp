#include "Recruiting.hpp"

Recruiting::Recruiting() {
    teachers.clear();
    schools.clear();
}

void Recruiting::show() const {
    cout << "--------------------------------" << endl;
    cout << "TEACHERS: " << endl;
    for (Teacher teacher : teachers) {
        cout << "T id: " << teacher.id << endl;
        cout << "\tNum Skills: " << teacher.num_skills << endl;
        cout << "\tSchool Preferences ";
        for (int pref : teacher.school_prefs) {
            cout << pref << " ";
        }
        cout << endl;
    }

    cout << "--------------------------------" << endl;
    cout << "Schools: " << endl;
    for (School school : schools) {
        cout << "S id: " << school.id << endl;
        cout << "\tNum Pos: " << school.num_pos << endl;
        cout << "\tNum Skills Required ";
        for (Position pos : school.positions) {
            cout << pos.skill_req << " ";
        }
        cout << endl;
    }

}

void Recruiting::show_assignment() const {
    cout << "--------------------------------" << endl;
    for (School school : schools) {
        cout << "School of id " << school.id << " got the following teachers: " << endl;
        for (Position pos : school.positions) {
            if (pos.matched) cout << pos.teacher.id << " ";
        }
        cout << endl;
    }

}

void Recruiting::read(const string& filename) {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        throw std::runtime_error("[ERR] " + filename + " could not be opened");
    }

    string line;
    vector<string> line_parts;
    string temp;
    vector<string> parts;
    int id, skills, num_pos;
    vector<int> school_prefs, school_reqs;

    while(getline(ifs, line), line[0] != '(');
    while(line[0] == '(') {
        school_prefs.clear();
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        line_parts = split(line, ":");
        for (int indx = 0; indx < line_parts.size(); ++indx) {
            line_parts[indx] = line_parts[indx].substr(
                line_parts[indx].find("(") + 1, line_parts[indx].find(")") - 1);
        }
        parts = split(line_parts[0], ",");
        id = stoi(parts[0].substr(1));
        skills = stoi(parts[1]);
        parts = split(line_parts[1], ",");
        for (string pref : parts) {
            school_prefs.push_back(stoi(pref.substr(1)));
        }
        teachers.push_back(Teacher(id, skills, school_prefs));
        getline(ifs, line);
    }
    while(getline(ifs, line), line[0] != '(');
    while(line[0] == '(') {
        school_reqs.clear();
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        line_parts = split(line, ":");
        for (int indx = 0; indx < line_parts.size(); ++indx) {
            line_parts[indx] = line_parts[indx].substr(
                line_parts[indx].find("(") + 1, line_parts[indx].find(")") - 1);
        }
        id = stoi(line_parts[0].substr(1));
        line_parts.erase(line_parts.begin());
        if (line_parts.size() > 1) {
            num_pos = 2;
        } else {
            num_pos = 1;
        }
        for (string req : line_parts) {
            school_reqs.push_back(stoi(req));
        }
        schools.push_back(School(id, num_pos, school_reqs));
        getline(ifs, line);
    }
    std::sort(teachers.begin(), teachers.end());
}

int Recruiting::find_teacher_indx(int teacher_id) {
    for (int indx = 0; indx < teachers.size(); ++indx) {
        if (teachers.at(indx).id == teacher_id) return indx;
    }
    return -1;
}

int Recruiting::find_school_indx(int school_id) {
    for (int indx = 0; indx < schools.size(); ++indx) {
        if (schools.at(indx).id == school_id) return indx;
    }
    return -1;
}

bool Recruiting::shouldChange(Position& pos, Teacher& teacher, const int& pref) {
    // if (teacher.num_skills != pos.skill_req) return false;
    // Compares  already in position with teacher that is applying to teacher
    // Pref is from teacher that is applying
    if (pos.teacher_pref > pref) return true;
    return false;
}

void Recruiting::galeShapley() {
    queue<int> free_teachers;
    int teacher_indx;
    int old_teacher_id;
    int old_teacher_indx;
    for (int indx = 0; indx < teachers.size(); ++indx) {
        Teacher& teacher = teachers.at(indx);
        if (!teacher.assigned) free_teachers.push(indx);
    }
    while(!free_teachers.empty()) {
        teacher_indx = free_teachers.front(); free_teachers.pop();
        Teacher& teacher = teachers.at(teacher_indx);
        for (int pref_indx = 0; pref_indx < teacher.school_prefs.size(); ++pref_indx) {
            int school_indx = teacher.school_prefs.at(pref_indx);
            School& school = schools.at(school_indx - 1);
            for (int pos_indx = 0; pos_indx < school.positions.size(); ++pos_indx) {
                Position& pos = school.positions.at(pos_indx);
                // if (!pos.matched && teacher.num_skills >= pos.skill_req) {
                if (!pos.matched) {
                    school.assign_teacher(pos_indx, teacher, pref_indx);
                    break;
                } else if(pos.matched && shouldChange(pos, teacher, pref_indx)) {
                    old_teacher_id = school.change_teacher(pos_indx, teacher, pref_indx);
                    old_teacher_indx = find_teacher_indx(old_teacher_id);
                    Teacher& old_teacher = teachers.at(old_teacher_indx);
                    old_teacher.assigned = false;
                    old_teacher.matched_school = -1;
                    free_teachers.push(old_teacher_indx);
                    break;
                }
            }
            if (teacher.assigned) {
                break;
            }
        }
    }
}

int Recruiting::num_occupied() const {
    int num_occ = 0;
    for (const School& school : schools) {
        for (const Position& pos : school.positions) {
            if (pos.matched) ++num_occ;
        }
    }
    return num_occ;
}

void Recruiting::unoccupied_teachers() const {
    cout << "Unoccupied Teachers: " << endl;
    for (Teacher teacher : teachers) {
        if (!teacher.assigned)
        cout << teacher.id << " ";
    }
}
