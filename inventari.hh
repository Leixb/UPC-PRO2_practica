/**
 * @file inventari.hh
 * @brief Especificació de la classe Inventari
 */
#ifndef INVENTARI_H
#define INVENTARI_H
#include<map>

class Inventari {
    static std::map <std::string, unsigned int> contador;

    /**
     * @brief Retorna una referencia al nombre d'unitats del producte
     * si exiteix
     *
     * @param prod_id Identificador del producte
     *
     * @return Referència al nombre d'unitats del producte
     *
     * @throws ProducteNoExsitent() si el producte no existeix
     */
    static unsigned int& query(const std::string& prod_id);

    Inventari() {}

    public:

    /**
     * @brief Afegeix un producte a l'inventari.
     *
     * @param prod_id Identificador del producte
     *
     * @thows ProducteJaExistent() si ja existeix un producte amb
     * l'identificador especificat a l'estanteria
     *
     * @post L'inventari conte una nova entrada per el producte especificat amb
     * 0 unitats
     */
    static void afegir_prod(const std::string prod_id);

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
    static void quitar_prod(const std::string prod_id);

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
    static void afegir_unitats(const std::string& prod_id, const unsigned int& unitats=1);

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
    static void treure_unitats(const std::string& prod_id, const unsigned int& unitats=1);

    /**
     * @brief Consulta el nombre d'unitats del producte al magatzem
     *
     * @param prod_id Identificador del producte
     *
     * @return  Unitats del producte a l'Inventari
     */
    static unsigned int consultar_producte(const std::string& prod_id);

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
    static void mostra();
};
#endif /* ifndef INVENTARI_H */
