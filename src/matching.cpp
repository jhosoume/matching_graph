#include "matching.hpp"

int main(int argc, char const *argv[]) {
    Recruiting rec = Recruiting();
    rec.read("input_files/entradaProj3TAG.txt");
    // rec.show();
    cout << "Number of schools positions occupied = " << rec.num_occupied() << endl;
    rec.galeShapley();
    rec.fullfill_gap();
    // rec.show_assignment_fullinfo();
    rec.show_assignment();
    cout << "Number of schools positions occupied = " << rec.num_occupied() << endl;
    rec.unoccupied_teachers();
    return 0;
}
