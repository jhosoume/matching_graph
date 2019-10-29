#include "matching.hpp"

int main(int argc, char const *argv[]) {
    Recruiting rec = Recruiting();
    rec.read("input_files/entradaProj3TAG.txt");
    rec.show();
    return 0;
}
