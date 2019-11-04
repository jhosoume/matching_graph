#include "matching.hpp"

int main(int argc, char const *argv[]) {
    Recruiting rec = Recruiting();
    rec.read("input_files/entradaProj3TAG.txt");
    // rec.show();
    // cout << "Number of schools positions occupied = " << rec.num_occupied() << endl;
    // Apply Gale Shapley Algorithm
    rec.galeShapley();
    // Provide non occupied teacher to empty school
    rec.fullfill_gap();
    // rec.show_assignment_fullinfo();
    // Print all assignemnts
    rec.show_assignment();
    cout << "Number of schools positions occupied = " << rec.num_occupied() << endl;
    rec.unoccupied_teachers();
    return 0;
}
