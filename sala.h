#ifndef SALA_H
#define SALA_H

#include "estanteria.h"

class Sala {
    unsigned int id;

    Estanteria estant;
    Sala *dreta, *esquerra;
    //Sala *pare;

    public:

    unsigned int consulta_id();

    unsigned int poner_items(Producte* prod, const unsigned int& cantidad);
    unsigned int quitar_items(Producte* prod, const unsigned int& cantidad);

    void compactar();
    void reorganizar();
    void redimensionar(const unsigned int& f, const unsigned int& c);

    Producte* consultar_pos(const unsigned int& f, const unsigned int& c) const;
};

#endif // ifndef SALA_H

