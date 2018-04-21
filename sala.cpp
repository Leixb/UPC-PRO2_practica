#include "sala.h"

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

unsigned int Sala::poner_items(Producte* prod, const unsigned int& cantidad) {
    return estant.poner_items(prod, cantidad);
}

unsigned int Sala::quitar_items(Producte* prod, const unsigned int& cantidad) {
    return estant.quitar_items(prod, cantidad);
}

void Sala::compactar() {
    estant.compactar();
}

void Sala::reorganizar() {
    estant.reorganizar();
}

void Sala::redimensionar(const unsigned int& f, const unsigned int& c) {
    estant.redimensionar(f, c);
}

void Sala::escribir() {
    estant.escribir();
}

Producte* Sala::consultar_pos(const unsigned int& f, const unsigned int& c) const {
    return estant.consultar_pos(f, c);
}
