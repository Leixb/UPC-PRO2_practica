/**
 * @file sala.cc
 * @brief Implementació de la classe Sala
 */
#include "sala.hh"
#include "excepcions.hh"
#include "inventari.hh"

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
    files = f, columnes = c;
}

unsigned int Sala::poner_items(const string& prod_id, unsigned int cantidad) {
    unsigned int afegits = 0;
    for (unsigned int i = 0; i < files*columnes and (cantidad > afegits); ++i)
        if (!Inventari::existeix_producte(estant[i]))
            estant[i] = prod_id, ++afegits;
    inv.afegir_unitats(prod_id, afegits);
    return cantidad-afegits;
}

unsigned int Sala::quitar_items(const string& prod_id, unsigned int cantidad) {
    int eliminats = 0;
    for (unsigned int i = 0; i < files*columnes and cantidad - eliminats; ++i)
        if (estant[i] == prod_id)
            estant[i] = "", ++eliminats;
    inv.treure_unitats(prod_id, eliminats);
    return cantidad - eliminats;
}

string Sala::consultar_pos(const unsigned int& f, const unsigned int& c) const {
    string prod_id = estant.at((files - f)*columnes + c-1);
    if (Inventari::existeix_producte(prod_id)) return prod_id;
    return "NULL";
}

void Sala::compactar() {
    vector<string> v;
    for (const string& prod : estant)
        if (Inventari::existeix_producte(prod)) v.push_back(prod);
    v.resize(files*columnes);
    estant = v;
}

void Sala::reorganizar() {
    sort(estant.begin(), estant.end(),
        [](const string& a, const string& b) {
            if (!Inventari::existeix_producte(a)) return false;
            return !Inventari::existeix_producte(b) or a < b;
        }
    );
}

void Sala::redimensionar(const unsigned int& f, const unsigned int& c) {
    if (f*c < inv.total_productes()) throw DimensionsInsuficients();
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
            if (Inventari::existeix_producte(prod)) cout << prod;
            else cout << "NULL";
        }
        cout << endl;
    }
    cout << "  " << inv.total_productes() << endl;
    inv.mostra(false);
}
