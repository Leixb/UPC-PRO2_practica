#include "sala.h"

#include <map>
using std::map;

class Magatzem {
    Sala *root;

    vector<Producte> productes;

    map<string, Producte*> prod_map;
    map<unsigned int, Sala*> sala_map;

    public:

    void inicialitza();

    void poner_prod(const string& prod_id);
    void quitar_prod(const string& prod_id);

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
