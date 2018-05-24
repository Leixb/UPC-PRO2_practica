/**
 * @file sala.cc
 * @brief Implementació de la classe Sala
 */
#include "excepcions.hh"
#include "inventari.hh"
#include "sala.hh"

#include<algorithm>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

Sala* Sala::fill_dre() const {
    return dreta;
}

Sala* Sala::fill_esq() const {
    return esquerra;
}

void Sala::crea_estanteria(const unsigned int& f, const unsigned int& c) {
    estant = vector<string>(f*c, "");
    files = f, columnes = c, last_pos = 0;
}

unsigned int Sala::poner_items(const string& prod_id, const unsigned int& cantidad) {
    unsigned int afegits = 0;

    while (!forats.empty() and cantidad > afegits) {
        estant[forats.top()] = prod_id, ++afegits;
        forats.pop();
    }

    {
        unsigned int i;
        for (i = last_pos; i < files*columnes and cantidad > afegits; ++i)
            estant[i] = prod_id, ++afegits;

        last_pos = i;
    }

    inv.afegir_unitats(prod_id, afegits);

    return cantidad - afegits;
}

unsigned int Sala::quitar_items(const string& prod_id, const unsigned int& cantidad) {
    const unsigned int unitats_eliminables = min(inv.consultar_producte(prod_id), cantidad);
    unsigned int eliminats = 0;

    for (unsigned int i = 0; i < last_pos and unitats_eliminables > eliminats; ++i)
        if (estant[i] == prod_id) {
            estant[i] = "", ++eliminats;
            forats.push(i);
        }

    inv.treure_unitats(prod_id, eliminats);
    return cantidad - eliminats;
}

string Sala::consultar_pos(const unsigned int& f, const unsigned int& c) const {
    string prod_id = estant.at((files - f)*columnes + c-1);
    if (prod_id == "")
        return "NULL";
    return prod_id;
}

void Sala::compactar() {
    if (!forats.empty()) {
        vector<string> v;
        v.reserve(files*columnes);
        for (const string& prod : estant)
            if (prod != "")
                v.push_back(prod);
        v.resize(files*columnes);
        estant = v;
        last_pos = inv.total_productes(),
        forats   = priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int> > ();
    }
}

void Sala::reorganizar() {
    estant.clear();
    estant.reserve(files*columnes);
    for (const pair<string, unsigned int>& prod : inv.data())
        for (unsigned int i = 0; i < prod.second; ++i)
            estant.push_back(prod.first);
    estant.resize(files*columnes);

    last_pos = inv.total_productes(),
    forats   = priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int> > ();
}

void Sala::redimensionar(const unsigned int& f, const unsigned int& c) {
    if (f*c < inv.total_productes())
        throw DimensionsInsuficients();

    compactar();
    files = f, columnes = c;
    estant.resize(files*columnes);
}

void Sala::escribir() const {
    for (unsigned int i = files-1; i < files; --i) {
        cout << ' ';
        for (unsigned int j = 0; j < columnes; ++j) {
            string prod = estant[i*columnes + j];
            cout << ' ';
            if (prod == "")
                cout << "NULL";
            else
                cout << prod;
        }
        cout << endl;
    }
    cout << "  " << inv.total_productes() << endl;
    inv.mostra(false);
}
