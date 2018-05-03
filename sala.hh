 /**
 * @file sala.hh
 * @brief Especificació de la classe Sala
 */
#ifndef SALA_H
#define SALA_H

#include<vector>
#include<string>

/**
 * @brief Sala del magatzem
 */
class Sala {
    friend class Magatzem;

    std::vector<std::string> estant;  ///< Productes de la sala en el seu ordre corresponent.
    unsigned int files, columnes;   ///< Dimensions de l'estanteria.

    unsigned int last_pos,      ///< Ultima posició en la que es pot trobar un element no NULL.
                 elements;      ///< Nombre de productes a la sala.

    Sala *esquerra, ///< Apuntador a la Sala filla esquerra. *nullptr* si la sala actual es una fulla.
         *dreta;    ///< Apuntador a la Sala filla dreta. *nullptr* si la sala actual es una fulla.

    public:

    // Consultors

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
    std::string consultar_pos(const unsigned int& f, const unsigned int& c) const;

    // Metodes

    /**
     * @brief Assigna una mida a l'estanteria de la sala
     *
     * @param f Nombre de files
     * @param c Nombre de columnes
     *
     * @post La sala conté una estanteria buida de mida f*c
     */
    void crea_estanteria(const unsigned int& f, const unsigned int& c);

    /**
     * @brief Afegeix items a l'estanteria
     *
     * @param prod Identificador del producte
     * @param cantidad Unitata del producte a colocar
     *
     * @return Nombre d'unitats no colocades
     *
     * @pre Existeix el Producte identificat per prod_id
     */
    unsigned int poner_items(const std::string& prod, unsigned int cantidad);

    /**
     * @brief Elimina items a l'estanteria
     *
     * @param prod Identificador del producte
     * @param cantidad Unitata del producte
     *
     * @return Nombre d'unitats no eliminades, ja que no quedaven més unitats a
     * l'estanteria
     *
     * @pre Existeix el Producte identificat per prod_id
     */
    unsigned int quitar_items(const std::string& prod, unsigned int cantidad);

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
     * @brief Compacta i canvia les dimensions de l'estanteria
     *
     * Si les nova mida de l'estanteria es suficient per a mantenir els
     * productes, es compacta (@ref compactar) el contingut de l'estanteria i
     * canvia les dimensions de l'estanteria a f*c. Si les noves dimensions no
     * son suficients per encabir els continguts  anteriors llença una exepció
     * i **no** es modifica l'estanteria.
     *
     *
     * @param f nou nombre de files
     * @param c nou nombre de columnes
     *
     * @post estanteria queda compactada i amb nova mida f*c.
     *
     * @throws DimensionsInsuficients() si elements > f*c
     */
    void redimensionar(const unsigned int& f, const unsigned int& c);

    /**
     * @brief Treu per std_out els continguts de l'estanteria
     *
     * Els continugts es mostren per files en ordre descendent. El contingut
     * que es mostra son els identificadors del producte que es troba a cada
     * posició. Si es buida es mostra "NULL".
     *
     * Despres es mostra el nombre de productes a l'estanteria no NULLs
     * seguit d'un inventari per ordre alfabetic de cada producte i el nombre
     * d'unitats que es troben a l'estanteria. Si el producte no es troba a
     * l'estanteria no es mostra.
     */
    void escribir() const;

};

#endif // ifndef SALA_H

