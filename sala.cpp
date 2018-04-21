#include "sala.h"

#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

Sala::Sala(const unsigned int& id): id(id) {}

unsigned int Sala::consulta_id() {
    return id;
}

Sala* Sala::fill_dre() {
    return dreta;
}

Sala* Sala::fill_esq() {
    return esquerra;
}

void Sala::crea_estanteria(const unsigned int& f, const unsigned int& c) {
    estant = vector<Producte*>(f*c, nullptr);
    last_pos = elements = 0;
    files = f, columnes = c;
}

unsigned int Sala::poner_items(Producte* prod, unsigned int cantidad) {
    for (unsigned int i = 0; i < files*columnes and cantidad; ++i)
        if (estant[i] == nullptr)
            --cantidad, estant[i] = prod, prod->afegir(),
                ++last_pos, last_pos = std::max(last_pos, i),
                ++elements;
    return cantidad;
}

unsigned int Sala::quitar_items(Producte* prod, unsigned int cantidad) {
    for (unsigned int i = 0; i <= last_pos and cantidad; ++i) 
        if (estant[i] == prod)
            estant[i] = nullptr, --cantidad, --elements,
                prod->treure();
    // last_pos ?
    return cantidad;
}


Producte* Sala::consultar_pos(const unsigned int& f, const unsigned int& c) const {
    return estant.at(f*columnes + c);
}

void Sala::compactar() {
    //stable_sort(estant.begin(), estant.end(),
    stable_sort(estant.begin(), estant.begin()+last_pos,
            [](Producte* a, Producte* b)  -> bool  {
            if (b == nullptr) return true;
            else if (a == nullptr) return false;
            return true;
            }
            );
}

void Sala::reorganizar() {
    //sort(estant.begin(), estant.end(),
    sort(estant.begin(), estant.begin()+last_pos,
            [](Producte* a, Producte* b) {
            if (b == nullptr) return true;
            else if (a == nullptr) return false;
            return a->consulta_id() < b->consulta_id();
            }
        );
}

void Sala::redimensionar(const unsigned int& f, const unsigned int& c) {
    if (f*c < elements) throw "too small";
    compactar();
    files = f, columnes = c, last_pos = elements;
    estant.resize(files*columnes);
}

void Sala::escribir() {
    unsigned int no_nulls = 0;
    map<Producte*, int> inventori;
    for (unsigned int i = files-1; i < files; --i) {
        cout << ' ';
        for (unsigned int j = 0; j < columnes; ++j) {
            Producte* prod = estant[i*columnes + j];
            cout << ' ';
            if (prod == nullptr) cout << "NULL";
            else {
                cout << prod->consulta_id();
                ++inventori[prod], ++no_nulls;
            }
        }
        cout << endl;
    }
    cout << "  " << no_nulls << endl;
    for (auto prod : inventori) {
        cout << "  " << prod.first->consulta_id() << ' ' << prod.second << endl;
    }
    // TODO: unitats en total i llista de productes
}
