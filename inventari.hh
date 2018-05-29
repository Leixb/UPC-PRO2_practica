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
     *
     * @cost
     * constant (unordered_set)
     */
    static bool existeix_producte(const std::string& prod_id);

    /**
     * @brief Afegeix un producte a l'inventari.
     *
     * @param prod_id Identificador del producte.
     *
     * @throws ProducteJaExistent() si existeix un producte amb l'identificador
     * especificat a l'estanteria.
     *
     * @post Es registra el producte a l'inventari. Si es llença un error no es
     * modifica el paràmetre implícit.
     *
     * @cost logarítmic en el nombre de productes
     */
    static void poner_prod(const std::string& prod_id);

    /**
     * @brief Elimina un producte de l'inventari.
     *
     * @param prod_id Identificador del producte.
     *
     * @throws ProducteNoExistent() si NO existeix un producte amb
     * l'identificador especificat a l'estanteria.
     *
     * @post El producte queda eliminat de l'inventari.
     *
     * @cost logarítmic en el nombre de productes
     */
    static void quitar_prod(const std::string& prod_id);

    /**
     * @brief Afegeix unitats de producte al inventari.
     *
     * @param prod_id Identificador del producte.
     * @param unitats Unitats de producte a afegir.
     *
     * @post El nombre d'unitats del producte prod_id a l'inventari s'ha
     * incrementat en *unitats*.
     *
     * @throws ProducteNoExistent() si NO existeix un producte amb
     * l'identificador especificat a l'estanteria.
     *
     * @cost
     * logarítmic en el nombre de productes
     */
    void afegir_unitats(const std::string& prod_id, const unsigned int& unitats=1);

    /**
     * @brief Treu unitats de producte al inventari.
     *
     * @param prod_id Identificador del producte.
     * @param unitats Unitats de producte a treure.
     *
     * @pre El nombre d'unitats a treure (unitats) és >= a el nombre d'unitats
     * que es troben a l'inventari.
     * @post El nombre d'unitats del producte prod_id ha disminuït en
     * *unitats*.
     *
     * @throws ProducteNoExistent() si no existeix un producte amb
     * l'identificador especificat a l'estanteria.
     *
     * @cost
     * logarítmic en el nombre de productes
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
     *
     * @cost
     * logarítmic en nombre de productes
     */
    unsigned int consultar_producte(const std::string& prod_id) const;

    /**
     * @brief Mostra per std_out el contingut de l'inventari.
     *
     * Mostra línia per línia l'identificador de producte seguit del nombre
     * d'unitats que es troben a l'inventari. Els productes s'ordenen
     * alfabèticament per identificador.
     *
     * @cost
     * lineal en nombre de productes
     */
    void mostra(const bool& show_zeros=true) const;

    /**
     * @brief Consulta el nombre de productes a l'inventari.
     *
     * @return Nombre de productes registrats a l'inventari.
     *
     * @cost
     * constant (retorna el valor de l'atribut elements).
     */
    unsigned int total_productes() const;

    /**
     * @brief Accedeix al contingut de l'inventari.
     *
     * @return Referència constant al comptador del paràmetre implícit.
     *
     * @see Sala#reorganizar
     */
    const std::map <std::string, unsigned int>& data() const;
};
#endif /* ifndef INVENTARI_H */
