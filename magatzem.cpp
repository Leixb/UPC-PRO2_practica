#include "sala.h"

#include <map>
#include <list>
#include <queue>
using namespace std;

class Magatzem {
    Sala *root;

    list<Producte> productes;

    map<string, list<Producte>::iterator> prod_map;
    vector<Sala*> sala_map;

    Producte* str_to_prod(const string& prod_id) {
        return &(*prod_map.at(prod_id));
    }

    public:

    void inicialitza();

    void poner_prod(const string& prod_id) {
        prod_map["hello"] = productes.begin();
        if (prod_map.find(prod_id) != prod_map.end()) throw "Ja existeix";
        productes.push_back(Producte(prod_id));
        prod_map[prod_id] = std::prev(productes.end());
    }

    void quitar_prod(const string& prod_id) {
        auto const pos = prod_map.find(prod_id);
        if (pos == prod_map.end()) throw "No existeix";
        productes.erase(pos->second);
        prod_map.erase(pos);
    }

    unsigned int poner_items(const unsigned int& sala_id, const string& prod_id, const unsigned int& cantidad) {
        Sala* sala = sala_map.at(sala_id);
        return sala->poner_items(str_to_prod(prod_id), cantidad);
    }

    unsigned int distribuir(const string& prod_id, const unsigned int& cantidad) {
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

    void compactar(const unsigned int& sala_id) {
        sala_map.at(sala_id)->compactar();
    }

    void reorganizar(const unsigned int& sala_id) {
        sala_map.at(sala_id)->reorganizar();
    }

    void redimensionar(const unsigned int& sala_id, const unsigned int& f, const unsigned int& c) {
        sala_map.at(sala_id)->redimensionar(f, c);
    }

    void inventario() {
        productes.sort(
            [](const Producte& a, const Producte& b) -> bool {
                return a.consulta_id() < b.consulta_id();
            }
        );
        for (const Producte& prod : productes)
            prod.mostra();
    }

    void escribir(const unsigned int& sala_id) const {
        sala_map.at(sala_id)->escribir();
    }

    Producte* consultar_pos(const unsigned int& sala_id, const unsigned int& f, const unsigned int& c) const {
        return sala_map.at(sala_id)->consultar_pos(f, c);
    }

    unsigned int consultar_prod(const string& prod_id) const;
};
