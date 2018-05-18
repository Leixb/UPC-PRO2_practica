/**
 * @file magatzem.cc
 * @brief Implementació de la classe Magatzem
 */
#include "magatzem.hh"
#include "excepcions.hh"
#include "inventari.hh"

#include <map>
#include <list>
#include <queue>
#include <iostream>
using namespace std;

void Magatzem::inicialitza() {
    cin >> n_sales;
    sala_map = vector<Sala*> (n_sales+1, nullptr);

    unsigned int n;
    cin >> n;
    root = new Sala();
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
            sala_map[esq] = pare->esquerra = new Sala()
        );
    cin >> dre;
    if (dre)
        forma_arbre_post(
            sala_map[dre] = pare->dreta = new Sala()
        );
}

void Magatzem::poner_prod(const string& prod_id) {
    Inventari::afegir_prod(prod_id);
    inv.afegir_unitats(prod_id, 0);
}

void Magatzem::quitar_prod(const string& prod_id) {
    if (inv.consultar_producte(prod_id))
        throw ProducteNoExistent(); // TODO
    Inventari::quitar_prod(prod_id);
}

unsigned int Magatzem::poner_items(const unsigned int& sala_id, const string& prod_id, const unsigned int& cantidad) {
    Sala* sala = sala_map.at(sala_id);

    if (!Inventari::existeix_producte(prod_id)) throw ProducteNoExistent();

    const unsigned int sobrants = sala->poner_items(prod_id, cantidad);

    inv.afegir_unitats(prod_id, cantidad - sobrants);

    return sobrants;
}

unsigned int Magatzem::quitar_items(const unsigned int& sala_id, const string& prod_id, const unsigned int& cantidad) {
    Sala* sala = sala_map.at(sala_id);

    if (!Inventari::existeix_producte(prod_id)) throw ProducteNoExistent();

    const unsigned int sobrants = sala->quitar_items(prod_id, cantidad);

    inv.treure_unitats(prod_id, cantidad - sobrants);

    return sobrants;
}

unsigned int Magatzem::distribuir(const string& prod_id, const unsigned int& cantidad) {

    if (!Inventari::existeix_producte(prod_id)) throw ProducteNoExistent();

    queue<pair<Sala*, int> > salas;
    salas.push({root, cantidad});

    unsigned int no_distribuidas = 0;

    while(!salas.empty()) {
        unsigned int cantidad_sala = salas.front().second;
        Sala* sala = salas.front().first;
        salas.pop();

        cantidad_sala = sala->poner_items(prod_id, cantidad_sala);
        if (cantidad_sala) {
            if (sala->fill_esq() != NULL) {
                salas.push({sala->fill_esq(), cantidad_sala/2 + cantidad_sala%2});
                salas.push({sala->fill_dre(), cantidad_sala/2});
            } else no_distribuidas += cantidad_sala;
        }
    }

    inv.afegir_unitats(prod_id, cantidad - no_distribuidas);

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
    inv.mostra();
}

void Magatzem::escribir(const unsigned int& sala_id) const {
    sala_map.at(sala_id)->escribir();
}

string Magatzem::consultar_pos(const unsigned int& sala_id, const unsigned int& f, const unsigned int& c) const {
    return sala_map.at(sala_id)->consultar_pos(f, c);
}

unsigned int Magatzem::consultar_prod(const string& prod_id) {
    return inv.consultar_producte(prod_id);
}
