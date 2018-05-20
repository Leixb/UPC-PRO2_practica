/**
 * @file inventari.cc
 * @brief Implementació de la classe Inventari
 */
#include"excepcions.hh"
#include"inventari.hh"

#include<iostream>
#include<map>

using namespace std;

unordered_map <string, bool> Inventari::productes;

void Inventari::afegir_prod(const string& prod_id) {
    const pair<unordered_map<string, bool>::iterator, bool> res = productes.emplace(prod_id, true);
    if (!res.second) {
        if (res.first->second)
            throw ProducteJaExistent();
        res.first->second = true;
    }
}

void Inventari::quitar_prod(const string& prod_id) {
    if (!Inventari::existeix_producte(prod_id))
        throw ProducteNoExistent();
    productes[prod_id] = false;
}

void Inventari::afegir_unitats(const string& prod_id, const unsigned int& unitats) {
    if (!Inventari::existeix_producte(prod_id))
        throw ProducteNoExistent();
    contador[prod_id] += unitats;
    elements += unitats;
}
void Inventari::treure_unitats(const string& prod_id, const unsigned int& unitats) {
    if (!Inventari::existeix_producte(prod_id))
        throw ProducteNoExistent();
    contador[prod_id] -= unitats;
    elements -= unitats;
}

unsigned int Inventari::consultar_producte(const string& prod_id) const {
    if (!Inventari::existeix_producte(prod_id))
        throw ProducteNoExistent();
    return contador.at(prod_id);
}

void Inventari::mostra(const bool& show_zeros) const {
    for (const auto& element : Inventari::contador)
        if (Inventari::existeix_producte(element.first)
                and (show_zeros or element.second))
            cout << "  " << element.first << ' ' << element.second << endl;
}

unsigned int Inventari::total_productes() const {
    return elements;
}

bool Inventari::existeix_producte(const string& prod_id) {
    return productes[prod_id];
}
