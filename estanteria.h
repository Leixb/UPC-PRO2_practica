#ifndef ESTANTERIA_H
#define ESTANTERIA_H

#include "producte.h"

#include<vector>

using std::vector;

class Estanteria {
    vector<Producte*> estant;
    unsigned int files, columnes;

    unsigned int last_pos, elements;

    public:

    Estanteria();
    Estanteria(const unsigned int& files, const unsigned int& columnes);

    unsigned int poner_items(Producte* prod, unsigned int cantidad);

    Producte* consultar_pos(const unsigned int& f, const unsigned int& c) const;

    void compactar();
    void reorganizar();
    void redimensionar(const unsigned int& f, const unsigned int& c);

};

#endif // ifndef ESTANTERIA_H
