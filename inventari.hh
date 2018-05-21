/**
 * @file inventari.hh
 * @brief Especificació de la classe Inventari
 */
#ifndef INVENTARI_H
#define INVENTARI_H

#include<map>
#include<unordered_set>

class Inventari {
    std::map <std::string, unsigned int> contador;

    static std::unordered_set <std::string> productes;

    unsigned int elements;

    public:

    static void afegir_prod(const std::string& prod_id);

    /**
     * @brief Afegeix un producte a l'inventari
     *
     * @param prod_id Identificador del producte
     *
     * @thows ProducteNoExistent() si no existeix un producte amb
     * l'identificador especificat a l'estanteria
     *
     * @post el producte queda eliminat de l'inventari
     */
    static void quitar_prod(const std::string& prod_id);

    /**
     * @brief Afegeix unitats de producte al inventari
     *
     * @param prod_id Identificador del producte
     * @param unitats Unitats de producte a afegir
     *
     * @post El nombre d'unitats del producte prod_id d'ha augmentat unitats
     *
     * @thows ProducteNoExistent() si no existeix un producte amb
     * l'identificador especificat a l'estanteria
     */
    void afegir_unitats(const std::string& prod_id, const unsigned int& unitats=1);

    /**
     * @brief Treu unitats de producte al inventari
     *
     * @param prod_id Identificador del producte
     * @param unitats Unitats de producte a afegir
     *
     * @pre El nombre d'unitats a treure (unitats) és >= a el nombre d'unitats que es
     * troben a l'inventari.
     * @post El nombre d'unitats del producte prod_id d'ha decrementat
     * unitats
     *
     * @thows ProducteNoExistent() si no existeix un producte amb
     * l'identificador especificat a l'estanteria
     */
    void treure_unitats(const std::string& prod_id, const unsigned int& unitats=1);

    /**
     * @brief Consulta el nombre d'unitats del producte al magatzem
     *
     * @param prod_id Identificador del producte
     *
     * @return  Unitats del producte a l'Inventari
     */
    unsigned int consultar_producte(const std::string& prod_id) const;

    /**
     * @brief Comprova que el producte es troba a l'inventari
     *
     * @param prod_id Identificador del producte
     *
     * @return  true si el producte es troba a l'inventari, false altrament
     */
    static bool existeix_producte(const std::string& prod_id);

    /**
     * @brief Mostra per std_out el contingut de l'inventari
     *
     * Mostra linea per linea l'identificador de producte seguit del nombre
     * d'unitats que es troben a l'inventari. Els productes s'ordenen
     * alfabeticament per identificador
     */
    void mostra(const bool& show_zeros=true) const;

    unsigned int total_productes() const;

    const std::map <std::string, unsigned int>& data();
};
#endif /* ifndef INVENTARI_H */
