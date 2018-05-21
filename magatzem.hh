/**
 * @file magatzem.hh
 * @brief Especificació de la classe Magatzem
 */
#ifndef MAGATZEM_H
#define MAGATZEM_H

#include "inventari.hh"
#include "sala.hh"

#include <vector>

/**
 * @brief Classe principal, administra les sales i l'inventari.
 */
class Magatzem {
    unsigned int n_sales; ///< Nombre de sales al magatzem.
    Sala *root; ///< Sala principal, arrel, de l'arbre de sales.
    std::vector<Sala*> sala_map; ///< Relaciona l'identificador d'una sala amb la seva posició a la memòria.

    Inventari inv;

    /**
     * @brief Llegeix per std_in un arbre binari en preordre i l'associa a
     * pare.
     *
     * @param pare node sobre el que es forma l'arbre llegit.
     *
     * @pre a std_in trobem un arbre binari en *preordre* en els quals 0
     * marquen les fulles i els nodes son naturals entre 1 i n_sales inclòs
     * sense repetir.
     */
    void forma_arbre_pre(Sala* pare);

    public:

    /**
     * @brief Llegeix per std_in tota la informació necessària per a formar
     * l'arbre de sales així com les seves estanteries.
     *
     * @pre std_in conté una entrada vàlida.
     *
     * @post n_sales conte el nombre de sales, root apunta a un arbre que conte
     * d'informació entrada i sala_map conté les direccions en memòria de cada
     * sala de l'arbre indexades pel seu identificador.
     */
    void inicialitza();

    /**
     * @brief Afegeix un producte a la llista de productes.
     *
     * @param prod_id id del producte a afegir
     *
     * @throws ProducteJaExistent() si el producte a afegir ja existeix
     *
     * @see Inventari#poner_prod
     */
    void poner_prod(const std::string& prod_id);

    /**
     * @brief Elimina un producte de la llista de productes
     *
     * @param prod_id id del producte a eliminar
     *
     * @throws ProducteNoExistent() si el producte a eliminar no existeix
     *
     * @see Inventari#quitar_prod
     */
    void quitar_prod(const std::string& prod_id);

    /**
     * @brief Afegeix una quantitat d'un producte a una sala
     *
     * @param sala_id identificador de la sala a afegir el producte
     * @param prod_id identificador del producte a afegir
     * @param cantidad quantitat d'unitats de producte a afegir
     *
     * @return unitats de producte que no s'han pogut afegir ja que la sala
     * s'ha omplert fins la seva màxima capacitat
     *
     * @throws ProducteNoExistent() si no existeix el producte prod_id
     *
     * @see Sala#poner_items
     */
    unsigned int poner_items(const unsigned int& sala_id, const std::string& prod_id, const unsigned int& cantidad);

    /**
     * @brief Elimina una quantitat d'un producte a una sala
     *
     * @param sala_id identificador de la sala a eliminar el producte
     * @param prod_id identificador del producte a eliminar
     * @param cantidad quantitat d'unitats de producte a eliminar
     *
     * @return unitats de producte que no s'han pogut eliminar ja que no hi
     * havia prous unitats del producte a la sala.
     *
     * @throws ProducteNoExistent() si no existeix el producte prod_id
     *
     * @see Sala#quitar_items
     */
    unsigned int quitar_items(const unsigned int& sala_id, const std::string& prod_id, const unsigned int& cantidad);

    /**
     * @brief Distribueix una quantitat de producte pel magatzem
     *
     * @param prod_id identificador del producte a distribuir
     * @param cantidad quantitat de producte
     *
     * @return nombre d'unitats del producte que no s'han pogut distribuir
     * seguint el procediment de distribució.
     *
     * @see Sala#distribuir
     */
    unsigned int distribuir(const std::string& prod_id, const unsigned int& cantidad);

    /**
     * @brief Compacta l'estanteria de la sala identificada per sala_id.
     *
     * @param sala_id identificador de la sala
     *
     * @post la estanteria de la sala esta compactada
     *
     * @see Sala#compactar
     */
    void compactar(const unsigned int& sala_id);

    /**
     * @brief Reorganitza l'estanteria de la sala identificada per sala_id.
     *
     * @param sala_id identificador de la sala
     *
     * @post la estanteria de la sala esta ordenada
     *
     * @see Sala#reorganizar
     */
    void reorganizar(const unsigned int& sala_id);

    /**
     * @brief Canvia les dimensions de l'estanteria de la sala
     *
     * @param sala_id identificador de la sala
     * @param f nou nombre de files
     * @param c nou nombre de columnes
     *
     * @post la estanteria de la sala te noves dimensions
     *
     * @throws DimensionsInsuficients() si les noves dimensions de l'estanteria no poden contenir
     * els productes que tenia anteriorment
     *
     * @see Sala#redimensionar
     */
    void redimensionar(const unsigned int& sala_id, const unsigned int& f, const unsigned int& c);

    /**
     * @brief Mostra per std_out els identificadors de producte i el nombre
     * d'unitats al magatzem ordenats alfabeticament per identificador
     *
     * @see Inventari#mostra
     */
    void inventario();

    /**
     * @brief Mostra per std_out el contingut de l'estanteria de la sala.
     *
     * @param sala_id identificador de la sala a mostrar
     *
     * @see Sala#escribir
     */
    void escribir(const unsigned int& sala_id) const;

    /**
     * @brief Consulta el producte que es troba a la posició f, c de la sala
     * sala_id
     *
     * @param sala_id identificador de la sala a consultar
     * @param f fila a consultar
     * @param c columna a consultar
     *
     * @return identificador del producte que es troba a la posició especificada del
     * magatzem, "NULL" si la posició es buida.
     *
     * @see Sala#consultar_pos
     */
    std::string consultar_pos(const unsigned int& sala_id, const unsigned int& f, const unsigned int& c) const;

    /**
     * @brief Consulta el nombre d'unitats d'un producte al magatzem.
     *
     * @param prod_id identificador del producte a consultar.
     *
     * @return nombre d'unitats del producte al magatzem.
     *
     * @throws ProducteNoExistent() si el producte no existeix.
     *
     * @see Inventari#consultar_producte
     */
    unsigned int consultar_prod(const std::string& prod_id);
};

#endif // ifndef MAGATZEM_H
