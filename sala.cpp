#include "estanteria.h"

class Sala {
    unsigned int id;

    Estanteria estant;
    Sala *dreta, *esquerra;
    //Sala *pare;

    public:

    unsigned int poner_items(Producte* prod, const unsigned int& cantidad) {
        return estant.poner_items(prod, cantidad);
    }

    void compactar() {
        estant.compactar();
    }

    void reorganizar() {
        estant.reorganizar();
    }

    void redimensionar(const unsigned int& f, const unsigned int& c) {
        estant.redimensionar(f, c);
    }

    Producte* consultar_pos(const unsigned int& f, const unsigned int& c) const {
        return estant.consultar_pos(f, c);
    }

};
