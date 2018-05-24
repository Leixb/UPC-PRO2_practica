 /**
 * @file sala.hh
 * @brief Especificació de la classe Sala
 */
#ifndef SALA_H
#define SALA_H

#include"inventari.hh"

#include<string>
#include<vector>
#include<queue>

/**
 * @brief Sala del magatzem
 */
class Sala {
    friend class Magatzem;

    std::vector<std::string> estant;  ///< Productes de la sala en el seu ordre corresponent.
    unsigned int files, columnes;   ///< Dimensions de l'estanteria.

    Sala *esquerra, ///< Apuntador a la Sala filla esquerra. *nullptr* si la sala actual es una fulla.
         *dreta;    ///< Apuntador a la Sala filla dreta. *nullptr* si la sala actual es una fulla.

    Inventari inv; ///< Inventari de la Sala.

    /**
     * @brief cua que conte els forats que es generen entre productes al
     * eliminar-ne.
     */
    std::priority_queue<unsigned int, std::vector<unsigned int>, std::greater<unsigned int> > forats;
    unsigned int last_pos; ///< Posició de l'estanteria a partir de la qual tot es NULL. (inclosa)

    public:

    // Consultors

    /**
     * @return Punter a la sala a la dreta de l'actual
     */
    Sala* fill_dre() const;

    /**
     * @return Punter a la sala a l'esquerra de l'actual
     */
    Sala* fill_esq() const;

    /**
     * @brief Consulta l'element a la posició f, c de l'estanteria
     *
     * @param f fila de l'element a buscar
     * @param c columna de l'element a buscar
     *
     * @return punter al Producte que es troba a la posició f, c de
     * l'estanteria, si es buit retorna *nullptr*
     */
    std::string consultar_pos(const unsigned int& f, const unsigned int& c) const;

    // Mètodes

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
     * @brief Afegeix ítems a l'estanteria
     *
     * @param prod Identificador del producte
     * @param cantidad Unitats del producte a col·locar
     *
     * @return Nombre d'unitats no col·locades
     *
     * @pre Existeix el Producte identificat per prod_id
     */
    unsigned int poner_items(const std::string& prod, const unsigned int& cantidad);

    /**
     * @brief Elimina items a l'estanteria
     *
     * @param prod Identificador del producte
     * @param cantidad Unitats del producte
     *
     * @return Nombre d'unitats no eliminades, ja que no quedaven més unitats a
     * l'estanteria
     *
     * @pre Existeix el Producte identificat per prod_id
     */
    unsigned int quitar_items(const std::string& prod, const unsigned int& cantidad);

    /**
     * @brief Elimina els espais entre elements de l'estanteria mantenint
     * l'ordre entre ells.
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
     * son suficients per encabir els continguts  anteriors llença una excepció
     * i **no** es modifica l'estanteria.
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
     * Els continguts es mostren per files en ordre descendent. El contingut
     * que es mostra son els identificadors del producte que es troba a cada
     * posició. Si es buida es mostra "NULL".
     *
     * Desprès es mostra el nombre de productes a l'estanteria no nuls
     * seguit d'un inventari per ordre alfabètic de cada producte i el nombre
     * d'unitats que es troben a l'estanteria. Si el producte no es troba a
     * l'estanteria no es mostra.
     */
    void escribir() const;
};

#endif // ifndef SALA_H

