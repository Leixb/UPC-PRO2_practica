#ifndef SALA_H
#define SALA_H

#include "producte.h"

#include<vector>

class Sala {
    friend class Magatzem;
    unsigned int id;

    std::vector<Producte*> estant;
    unsigned int files, columnes;

    unsigned int last_pos, elements;

    Sala *dreta, *esquerra;

    public:

    /**
     * @brief Constructor
     *
     * @param id identificador de la sala.
     */
    Sala(const unsigned int& id=0);


    // Consultors

    /**
     * @return  retorna l'id associat a la sala.
     */
    unsigned int consulta_id() const;

    /**
     * @return Retorna el punter a la sala a la dreta de l'actual
     */
    Sala* fill_dre() const;
    /**
     * @return Retorna el punter a la sala a l'esquerra de l'actual
     */
    Sala* fill_esq() const;

    /**
     * @brief Consuta l'element a la posició f, c de l'estanteria
     *
     * @param f fila de l'element a buscar
     * @param c columna de l'element a buscar
     *
     * @return punter al Producte que es troba a la posicio f, c de
     * l'estanteria, si es buit retorna *nullptr*
     */
    Producte* consultar_pos(const unsigned int& f, const unsigned int& c) const;

    // Metodes

    void crea_estanteria(const unsigned int& f, const unsigned int& c);

    unsigned int poner_items(Producte* prod, unsigned int cantidad);
    unsigned int quitar_items(Producte* prod, unsigned int cantidad);

    /**
     * @brief Elimina els espais entre elements de l'estanteria mantenint
     * l'ordre entre ells.
     *
     * @post elements = last_pos (no hi ha cap espai buit entre elements)
     */
    void compactar();

    /**
     * @brief Reordena el contingut de l'estanteria alfabèticament i deixant
     * els espais buits al final.
     *
     * @post estanteria queda ordenada
     */
    void reorganizar();

    /**
     * @brief Compacta el contingut de l'estanteria i canvia les dimensions
     * de l'estanteria a f*c. Si les noves dimensions no son suficients per
     * encabir els continguts  anteriors llença una exepció i no es modifica
     * l'estanteria
     *
     * @param f nou nombre de files
     * @param c nou nombre de columnes
     *
     * @post estanteria queda compactada i amb nova mida f*c.
     *
     * @throws error si elements > f*c
     */
    void redimensionar(const unsigned int& f, const unsigned int& c);

    /**
     * @brief mostra per pantalla els continguts de l'estanteria
     */
    void escribir();

};

#endif // ifndef SALA_H

