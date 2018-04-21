#include "magatzem.h"

#include <map>
#include <list>
#include <queue>
#include <iostream>
using namespace std;


Producte* Magatzem::str_to_prod(const string& prod_id) {
    return &(*prod_map.at(prod_id));
}

void Magatzem::inicialitza() {
    cin >> n_sales;
    sala_map = vector<Sala*> (n_sales+1, nullptr);

    unsigned int n;
    cin >> n;
    root = new Sala(n);
    sala_map[n] = root;

    forma_arbre_post(root);

    for (unsigned int i = 1; i <= n_sales; ++i) {
        unsigned int f, c;
        cin >> f >> c;
        sala_map[i]->crea_estanteria(f, c);
    }
}

void Magatzem::forma_arbre_post(Sala* pare) {
    unsigned int esq, dre;
    cin >> esq;
    if (esq)
        forma_arbre_post(
            sala_map[esq] = pare->esquerra = new Sala(esq)
        );
    cin >> dre;
    if (dre)
        forma_arbre_post(
            sala_map[dre] = pare->dreta = new Sala(dre)
        );
}

void Magatzem::poner_prod(const string& prod_id) {
    if (prod_map.find(prod_id) != prod_map.end()) throw "Ja existeix";
    productes.push_back(Producte(prod_id));
    prod_map[prod_id] = std::prev(productes.end());
}

void Magatzem::quitar_prod(const string& prod_id) {
    auto const pos = prod_map.find(prod_id);
    if (pos == prod_map.end()) throw "No existeix";
    productes.erase(pos->second);
    prod_map.erase(pos);
}

unsigned int Magatzem::poner_items(const unsigned int& sala_id, const string& prod_id, const unsigned int& cantidad) {
    Sala* sala = sala_map.at(sala_id);
    return sala->poner_items(str_to_prod(prod_id), cantidad);
}

unsigned int Magatzem::quitar_items(const unsigned int& sala_id, const std::string& prod_id, const unsigned int& cantidad) {
    Sala* sala = sala_map.at(sala_id);
    return sala->quitar_items(str_to_prod(prod_id), cantidad);
}

unsigned int Magatzem::distribuir(const string& prod_id, const unsigned int& cantidad) {
    Producte* prod = str_to_prod(prod_id);

    queue<std::pair<Sala*, int> > salas;
    salas.push({root, cantidad});

    unsigned int no_distribuidas = 0;

    while(!salas.empty()) {
        unsigned int cantidad = salas.front().second;
        Sala* sala = salas.front().first;
        salas.pop();

        cantidad = sala->poner_items(prod, cantidad);
        if (cantidad) {
            if (sala->fill_esq() != NULL) {
                salas.push({sala->fill_esq(), cantidad/2 + cantidad%2});
                salas.push({sala->fill_dre(), cantidad/2});
            } else no_distribuidas += cantidad;
        }
    }

    return no_distribuidas;
}

void Magatzem::compactar(const unsigned int& sala_id) {
    sala_map.at(sala_id)->compactar();
}

void Magatzem::reorganizar(const unsigned int& sala_id) {
    sala_map.at(sala_id)->reorganizar();
}

void Magatzem::redimensionar(const unsigned int& sala_id, const unsigned int& f, const unsigned int& c) {
    sala_map.at(sala_id)->redimensionar(f, c);
}

void Magatzem::inventario() {
    productes.sort(
            [](const Producte& a, const Producte& b) -> bool {
            return a.consulta_id() < b.consulta_id();
            }
            );
    for (const Producte& prod : productes)
        prod.mostra();
}

void Magatzem::escribir(const unsigned int& sala_id) const {
    sala_map.at(sala_id)->escribir();
}

Producte* Magatzem::consultar_pos(const unsigned int& sala_id, const unsigned int& f, const unsigned int& c) const {
    return sala_map.at(sala_id)->consultar_pos(f, c);
}

unsigned int Magatzem::consultar_prod(const string& prod_id) const {} // TODO
