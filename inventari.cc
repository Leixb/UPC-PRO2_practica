/**
 * @file inventari.cc
 * @brief Implementació de la classe Inventari
 */
#include"excepcions.hh"
#include"inventari.hh"

#include<iostream>
#include<map>
#include<unordered_set>

using namespace std;

unordered_set <string> Inventari::productes;

void Inventari::afegir_prod(const string& prod_id) {
    if (!productes.emplace(prod_id).second)
        throw ProducteJaExistent();
}

void Inventari::quitar_prod(const string& prod_id) {
    if (!productes.erase(prod_id))
        throw ProducteNoExistent();
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
    try {
        return contador.at(prod_id);
    } catch (const std::out_of_range& e) {
        return 0;
    }
}

void Inventari::mostra(const bool& show_zeros) const {
    for (const pair<string, unsigned int>& element : Inventari::contador)
        if (Inventari::existeix_producte(element.first)
                and (element.second or show_zeros))
            cout << "  " << element.first << ' ' << element.second << endl;
}

unsigned int Inventari::total_productes() const {
    return elements;
}

bool Inventari::existeix_producte(const string& prod_id) {
    return productes.find(prod_id) != productes.end();
}

const map <string, unsigned int>& Inventari::data() {
    return contador;
};
