/**
 * @brief Implementació de la classe Sala
 */
#include "sala.hh"
#include "excepcions.hh"

#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

Sala* Sala::fill_dre() const {
    return dreta;
}

Sala* Sala::fill_esq() const {
    return esquerra;
}

void Sala::crea_estanteria(const unsigned int& f, const unsigned int& c) {
    estant = vector<string>(f*c, "");
    last_pos = elements = 0;
    files = f, columnes = c;
}

unsigned int Sala::poner_items(const string& prod_id, unsigned int cantidad) {
    for (unsigned int i = 0; i < files*columnes and cantidad; ++i)
        if (estant[i] == "")
            --cantidad, estant[i] = prod_id,
            last_pos = max(last_pos, i),
            ++elements;
    return cantidad;
}

unsigned int Sala::quitar_items(const string& prod_id, unsigned int cantidad) {
    for (unsigned int i = 0; i <= last_pos and cantidad; ++i) 
        if (estant[i] == prod_id)
            estant[i] = "", --cantidad, --elements;
    // last_pos ?
    return cantidad;
}


string Sala::consultar_pos(const unsigned int& f, const unsigned int& c) const {
    return estant.at(f*columnes + c);
}

void Sala::compactar() {
    //stable_sort(estant.begin(), estant.end(),
    stable_sort(estant.begin(), estant.begin()+last_pos,
        [](const string& a, const string& b)  -> bool  {
            if (b == "") return true;
            else if (a == "") return false;
            return true;
        }
    );
}

void Sala::reorganizar() {
    sort(estant.begin(), estant.begin()+last_pos+1,
        [](const string& a, const string& b) {
            if (b == "") return true;
            else if (a == "") return false;
            return a < b;
        }
    );
}

void Sala::redimensionar(const unsigned int& f, const unsigned int& c) {
    if (f*c < elements) throw DimensionsInsuficients();
    compactar();
    files = f, columnes = c, last_pos = elements;
    estant.resize(files*columnes);
}

void Sala::escribir() const {
    unsigned int no_nulls = 0;
    map<string, unsigned int> inventori;
    for (unsigned int i = files-1; i < files; --i) {
        cout << ' ';
        for (unsigned int j = 0; j < columnes; ++j) {
            string prod = estant[i*columnes + j];
            cout << ' ';
            if (prod == "") cout << "NULL";
            else {
                cout << prod;
                ++inventori[prod], ++no_nulls;
            }
        }
        cout << endl;
    }
    cout << "  " << no_nulls << endl;
    for (const pair<string, int>& prod : inventori)
        cout << "  " << prod.first << ' ' << prod.second << endl;
}
