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
        for (int req : school.skills_req) {
            cout << req << " ";
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
}
