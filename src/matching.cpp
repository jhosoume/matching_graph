#include "matching.hpp"

int main(int argc, char const *argv[]) {
    Recruiting rec = Recruiting();
    rec.read("input_files/entradaProj3TAG.txt");
    rec.show();
    rec.schools.at(0).assign_teacher(0, rec.teachers.at(0), 1);
    rec.show_assignment();
    rec.galeShapley();
    return 0;
}
