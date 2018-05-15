/**
 * @file inventari.cc
 * @brief Implementació de la classe Inventari
 */
#include<map>
#include<iostream>

#include"excepcions.hh"

#include"inventari.hh"

using namespace std;

std::map <std::string, unsigned int> Inventari::contador;

unsigned int& Inventari::query(const string& prod_id) {
    try {
        return Inventari::contador.at(prod_id);
    } catch (const out_of_range& e) {
        throw ProducteNoExistent();
    }
}

void Inventari::afegir_prod(const string prod_id) {
    if (contador.find(prod_id)!= Inventari::contador.end())
        throw ProducteJaExistent();

    Inventari::contador[prod_id] = 0;
}

void Inventari::quitar_prod(const string prod_id) {
    const map<string, unsigned int>::iterator pos = Inventari::contador.find(prod_id);

    if (pos == Inventari::contador.end())
        throw ProducteNoExistent();

    Inventari::contador.erase(pos);
}

void Inventari::afegir_unitats(const string& prod_id, const unsigned int& unitats) {
    Inventari::query(prod_id) += unitats;
}
void Inventari::treure_unitats(const string& prod_id, const unsigned int& unitats) {
    Inventari::query(prod_id) -= unitats;
}

unsigned int Inventari::consultar_producte(const string& prod_id) {
    return Inventari::query(prod_id);
}

void Inventari::mostra() {
    for (const auto& element : Inventari::contador)
        cout << "  " << element.first << ' ' << element.second << endl;
}

bool Inventari::existeix_producte(const string& prod_id) {
    return Inventari::contador.find(prod_id) != Inventari::contador.end();
}
