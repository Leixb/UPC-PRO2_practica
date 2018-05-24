/**
 * @file inventari.hh
 * @brief Especificació de la classe Inventari.
 */
#ifndef INVENTARI_H
#define INVENTARI_H

#include<map>
#include<unordered_set>

class Inventari {
    static std::unordered_set <std::string> productes; ///< Conjunt de productes registrats.

    std::map <std::string, unsigned int> comptador; ///< Comptador de productes.
    unsigned int elements; ///< Nombre d'unitats a l'inventari.

    public:

    /**
     * @brief Comprova que el producte es troba a l'inventari.
     *
     * @param prod_id Identificador del producte.
     *
     * @return  *true* si el producte es troba a l'inventari, *false*
     * altrament.
     */
    static bool existeix_producte(const std::string& prod_id);

    /**
     * @brief Afegeix un producte a l'inventari.
     *
     * @param prod_id Identificador del producte.
     *
     * @thows ProducteJaExistent() si existeix un producte amb l'identificador especificat
     * a l'estanteria.
     *
     * @post Es registra el producte a l'inventari. Si es llença un error no es modifica el
     * paràmetre implícit.
     */
    static void poner_prod(const std::string& prod_id);

    /**
     * @brief Elimina un producte de l'inventari.
     *
     * @param prod_id Identificador del producte.
     *
     * @thows ProducteNoExistent() si NO existeix un producte amb l'identificador especificat
     * a l'estanteria.
     *
     * @post El producte queda eliminat de l'inventari.
     */
    static void quitar_prod(const std::string& prod_id);

    /**
     * @brief Afegeix unitats de producte al inventari.
     *
     * @param prod_id Identificador del producte.
     * @param unitats Unitats de producte a afegir.
     *
     * @post El nombre d'unitats del producte prod_id a l'inventari s'ha incrementat en *unitats*.
     *
     * @thows ProducteNoExistent() si NO existeix un producte amb
     * l'identificador especificat a l'estanteria.
     */
    void afegir_unitats(const std::string& prod_id, const unsigned int& unitats=1);

    /**
     * @brief Treu unitats de producte al inventari.
     *
     * @param prod_id Identificador del producte.
     * @param unitats Unitats de producte a treure.
     *
     * @pre El nombre d'unitats a treure (unitats) és >= a el nombre d'unitats que es
     * troben a l'inventari.
     * @post El nombre d'unitats del producte prod_id s'ha decrementat en
     * *unitats*.
     *
     * @thows ProducteNoExistent() si no existeix un producte amb
     * l'identificador especificat a l'estanteria.
     */
    void treure_unitats(const std::string& prod_id, const unsigned int& unitats=1);

    /**
     * @brief Consulta el nombre d'unitats del producte al magatzem.
     *
     * @param prod_id Identificador del producte.
     *
     * @return  Unitats del producte a l'inventari.
     *
     * @throws ProducteNoExistent() si no existeix el producte amb
     * l'identificador.
     */
    unsigned int consultar_producte(const std::string& prod_id) const;

    /**
     * @brief Mostra per std_out el contingut de l'inventari.
     *
     * Mostra línia per línia l'identificador de producte seguit del nombre
     * d'unitats que es troben a l'inventari. Els productes s'ordenen
     * alfabèticament per identificador.
     */
    void mostra(const bool& show_zeros=true) const;

    /**
     * @brief Consulta el nombre de productes a l'inventari.
     *
     * @return Nombre de productes registrats a l'inventari.
     */
    unsigned int total_productes() const;

    /**
     * @return Referència constant al comptador del paràmetre implícit.
     *
     * @see Sala#reorganizar
     */
    const std::map <std::string, unsigned int>& data() const;
};
#endif /* ifndef INVENTARI_H */
