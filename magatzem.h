#ifndef MAGATZEM_H
#define MAGATZEM_H

#include "sala.h"

#include <map>
#include <list>
#include <vector>

class Magatzem {
    Sala *root;

    std::list<Producte> productes;

    std::map<std::string, std::list<Producte>::iterator> prod_map;
    std::vector<Sala*> sala_map;

    Producte* str_to_prod(const std::string& prod_id);

    public:

    void inicialitza();

    void poner_prod(const std::string& prod_id);
    void quitar_prod(const std::string& prod_id);

    unsigned int poner_items(const unsigned int& sala_id, const std::string& prod_id, const unsigned int& cantidad);
    unsigned int quitar_items(const unsigned int& sala_id, const std::string& prod_id, const unsigned int& cantidad);

    unsigned int distribuir(const std::string& prod_id, const unsigned int& cantidad);

    void compactar(const unsigned int& sala_id);
    void reorganizar(const unsigned int& sala_id);
    void redimensionar(const unsigned int& sala_id, const unsigned int& f, const unsigned int& c);

    void inventario();
    void escribir(const unsigned int& sala_id) const;

    Producte* consultar_pos(const unsigned int& sala_id, const unsigned int& f, const unsigned int& c) const;
    unsigned int consultar_prod(const std::string& prod_id) const;
};

#endif // ifndef MAGATZEM_H
