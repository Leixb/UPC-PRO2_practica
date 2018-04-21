#include "estanteria.h"

#include<algorithm>
#include<vector>
using namespace std;

Estanteria::Estanteria(): files(0), columnes(0) {}
Estanteria::Estanteria(const unsigned int& files, const unsigned int& columnes):
    estant(vector<Producte*>(files*columnes, nullptr)), files(files), columnes(columnes),
    last_pos(0), elements(0) {}

    unsigned int Estanteria::poner_items(Producte* prod, unsigned int cantidad) {
        for (unsigned int i = 0; i < files*columnes and cantidad; ++i)
            if (estant[i] == nullptr)
                --cantidad, estant[i] = prod, prod->afegir(),
                    ++last_pos, last_pos = std::max(last_pos, i),
                    ++elements;
        return cantidad;
    }

unsigned int Estanteria::quitar_items(Producte* prod, unsigned int cantidad) {
    for (unsigned int i = 0; i <= last_pos and cantidad; ++i) 
        if (estant[i] == prod)
            estant[i] = nullptr, --cantidad, --elements;
    // last_pos ?
    return cantidad;
}


Producte* Estanteria::consultar_pos(const unsigned int& f, const unsigned int& c) const {
    return estant.at(f*columnes + c);
}

void Estanteria::compactar() {
    //stable_sort(estant.begin(), estant.end(),
    stable_sort(estant.begin(), estant.begin()+last_pos,
            [](Producte* a, Producte* b)  -> bool  {
            if (b == nullptr) return true;
            else if (a == nullptr) return false;
            return true;
            }
            );
}

void Estanteria::reorganizar() {
    //sort(estant.begin(), estant.end(),
    sort(estant.begin(), estant.begin()+last_pos,
            [](Producte* a, Producte* b) {
            if (b == nullptr) return true;
            else if (a == nullptr) return false;
            return a->consulta_id() < b->consulta_id();
            }
        );
}

void Estanteria::redimensionar(const unsigned int& f, const unsigned int& c) {
    if (f*c < elements) throw "too small";
    compactar();
    files = f, columnes = c, last_pos = elements;
    estant.resize(files*columnes);
}

void Estanteria::escribir() {

}
