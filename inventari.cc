/**
 * @file inventari.cc
 * @brief Implementació de la classe Inventari
 */
#include<map>
#include<iostream>

#include"excepcions.hh"

#include"inventari.hh"

using namespace std;

Inventari::Inventari(): last_query(nullptr), last_query_id("NULL") {}

unsigned int& Inventari::query(const string& prod_id) {
    if (prod_id == last_query_id) return *last_query;
    try {
        last_query = &contador.at(prod_id);
    } catch (const out_of_range& e) {
        throw ProducteNoExistent();
    }
    last_query_id = prod_id;
    return *last_query;
}

void Inventari::afegir_prod(const string prod_id) {
    if (contador.find(prod_id)!= contador.end())
        throw ProducteJaExistent();

    contador[prod_id] = 0;
}

void Inventari::quitar_prod(const string prod_id) {
    const map<string, unsigned int>::iterator pos = contador.find(prod_id);

    if (pos == contador.end())
        throw ProducteNoExistent();

    if (prod_id == last_query_id) last_query_id = "";

    contador.erase(pos);
}

void Inventari::afegir_unitats(const string& prod_id, const unsigned int& unitats) {
    query(prod_id) += unitats;
}
void Inventari::treure_unitats(const string& prod_id, const unsigned int& unitats) {
    query(prod_id) -= unitats;
}

unsigned int Inventari::consultar_producte(const string& prod_id) {
    return query(prod_id);
}

void Inventari::mostra() const {
    for (const auto& element : contador)
        cout << "  " << element.first << ' ' << element.second << endl;
}

bool Inventari::existeix_producte(const string& prod_id) const {
    return contador.find(prod_id) != contador.end();
}
