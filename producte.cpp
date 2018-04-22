#include "producte.h"
#include "excepcions.h"

#include <iostream>
using namespace std;

Producte::Producte(string id): id(id), unitats(0) {}

string Producte::consulta_id() const {
    return id;
}
unsigned int Producte::consulta_unitats() const {
    return unitats;
}

void Producte::afegir(const unsigned int& num) {
    unitats+=num;
};

void Producte::treure(const unsigned int& num) {
    if (unitats < num) throw UnitatsInsuficients();
    unitats-=num;
}

void Producte::mostra() const {
    cout << "  " << id << ' ' << unitats << endl;
}
