#include "sala.h"

#include <map>
using std::map;

#include <list>
using std::list;

class Magatzem {
    Sala *root;

    list<Producte> productes;

    map<string, list<Producte>::iterator> prod_map;
    map<unsigned int, Sala*> sala_map;

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

    unsigned int poner_items(const unsigned int& sala_id, const string& prod_id, const unsigned int& cantidad);

    void distribuir(const string& prod_id, const unsigned int& cantidad);

    void compactar(const unsigned int& sala_id);
    void reorganizar(const unsigned int& sala_id);
    void redimensionar(const unsigned int& sala_id, const unsigned int& f, const unsigned int& c);

    void inventario() const;
    void escribir(const unsigned int& sala_id) const;

    Producte* consultar_pos(const unsigned int& sala_id, const unsigned int& f, const unsigned int& c) const;
    unsigned int consultar_prod(const string& prod_id) const;
};
