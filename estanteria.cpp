#include "producte.h"

#include<vector>
using std::vector;

#include<algorithm>
using std::sort;
using std::stable_sort;

class Estanteria {
    vector<Producte*> estant;
    unsigned int files, columnes;

    unsigned int last_pos, elements;

    public:

    Estanteria(): files(0), columnes(0) {}
    Estanteria(const unsigned int& files, const unsigned int& columnes):
        estant(vector<Producte*>(files*columnes, NULL)), files(files), columnes(columnes),
        last_pos(0), elements(0) {}

    unsigned int poner_items(Producte* prod, unsigned int cantidad) {
        for (unsigned int i = 0; i < files*columnes and cantidad; ++i)
            if (estant[i] == NULL)
                --cantidad, estant[i] = prod,
                ++last_pos, last_pos = std::max(last_pos, i);
        return cantidad;
    }

    Producte* consultar_pos(const unsigned int& f, const unsigned int& c) const {
        return estant[f*columnes + c];
    }

    void compactar() {
        stable_sort(estant.begin(), estant.end()/*, CUSTOM_SORT_TODO*/);
        // custom sort:   si NULL al final, sino com si fossin iguals
    }

    void reorganizar() {
        sort(estant.begin(), estant.end()); // COMPROVAR QUE PASSA AMB EL NULL!!!
    }

    void redimensionar(const unsigned int& f, const unsigned int& c) {
        if (f*c < elements) throw "too small";
        compactar();
        files = f, columnes = c;
    }

};
