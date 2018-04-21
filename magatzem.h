#ifndef MAGATZEM_H
#define MAGATZEM_H

#include "sala.h"

#include <map>
#include <list>
#include <vector>

class Magatzem {
    unsigned int n_sales;
    Sala *root;
    std::vector<Sala*> sala_map;

    std::list<Producte> productes;
    std::map<std::string, std::list<Producte>::iterator> prod_map;

    /**
     * @brief Metode per trobar el objecte Producte associat a un id
     *
     * @param prod_id id del producte a buscar
     *
     * @return punter al producte amd id == prod_id
     *
     * @throws std::out_of_range si no existeix un producte amb id == prod_id
     */
    Producte* str_to_prod(const std::string& prod_id) const;

    /**
     * @brief Llegeix per std_in un arbre binari en post ordre i l'associa a
     * pare
     *
     * @param pare node al que s'acopla l'arbre llegit
     *
     * @pre a std_in trobem un arbre binari en post ordre en els quals 0
     * marquen les fulles i els nodes son naturals entre 1 i n_sales inclos
     * sense repetir
     */
    void forma_arbre_post(Sala* pare);

    public:

    /**
     * @brief Llegeix per std_in tota la informació necessària per a formar
     * l'arbre de sales aixi com les seves estanteries
     *
     * @pre std_in te una entrada vàlida
     *
     * @post n_sales conte el nombre de sales, root apunta a un arbre que conte
     * l'informació entrada i sala_map conté les direccions en memòria de cada
     * sala de l'arbre indexades pel seu identificador
     */
    void inicialitza();

    /**
     * @brief Afegeix un producte a la llista de productes
     *
     * @param prod_id id del producte a afegir
     *
     * @throws error si el producte a afegir ja existeix
     */
    void poner_prod(const std::string& prod_id);

    /**
     * @brief Elimina un producte de la llista de productes
     *
     * @param prod_id id del producte a eliminar
     *
     * @throws error si el producte a eliminar no existeix
     */
    void quitar_prod(const std::string& prod_id);

    /**
     * @brief Afegeix una quantitat d'un producte a una sala
     *
     * @param sala_id identificador de la sala a afegir el producte
     * @param prod_id identificadoe del producte a afegir
     * @param cantidad quantitat d'unitats de producte a afegir
     *
     * @return unitats de producte que no s'han pogut afegir ja que la sala
     * s'ha omplert fins la seva maxima capacitat
     *
     * @throws error si no existeix el producte prod_id
     */
    unsigned int poner_items(const unsigned int& sala_id, const std::string& prod_id, const unsigned int& cantidad);

    /**
     * @brief Elimina una quantitat d'un producte a una sala
     *
     * @param sala_id identificador de la sala a eliminar el producte
     * @param prod_id identificadoe del producte a eliminar
     * @param cantidad quantitat d'unitats de producte a eliminar
     *
     * @return unitats de producte que no s'han pogut eliminar ja que no hi
     * havia prous unitats del producte a la sala.
     *
     * @throws error si no existeix el producte prod_id
     */
    unsigned int quitar_items(const unsigned int& sala_id, const std::string& prod_id, const unsigned int& cantidad);

    /**
     * @brief Distribueix una quantitat de producte pel magatzem
     *
     * @param prod_id identificador del producte a distribuir
     * @param cantidad quantitat de producte
     *
     * @return nombre d'unitats del producte que no s'han pogut distrbuir
     * seguint el procediment de distribució
     */
    unsigned int distribuir(const std::string& prod_id, const unsigned int& cantidad);

    /**
     * @brief Compacta l'estanteria de la sala identificada per l'id.
     *
     * @param sala_id identificador de la sala
     *
     * @post la estanteria de la sala esta compactada
     */
    void compactar(const unsigned int& sala_id);

    /**
     * @brief Reorganitza l'estanteria de la sala identificada per l'id
     *
     * @param sala_id identificador de la sala
     *
     * @post la estanteria de la sala esta ordenada
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
     * @throws error si les noves dimensions de l'estanteria no poden contenir
     * els productes que tenia anteriorment
     */
    void redimensionar(const unsigned int& sala_id, const unsigned int& f, const unsigned int& c);

    /**
     * @brief Mostra per std_out els identificadors de producte i el nombre
     * d'unitats al magatzem ordenats alfabeticament per identificador
     */
    void inventario();
    /**
     * @brief Mostra per std_out el contingut de l'estanteria de la sala
     *
     * @param sala_id identificador de la sala a mostrar
     */
    void escribir(const unsigned int& sala_id) const;

    /**
     * @brief Consulta el producte que es troba a la posicio f, c de la sala
     * sala_id
     *
     * @param sala_id identificador de la sala a consultar
     * @param f fila a consultar
     * @param c columna a consultar
     *
     * @return punter al producte que es troba a la posicio especificada del
     * magatzem, *nullptr* si la posicio es buida
     */
    Producte* consultar_pos(const unsigned int& sala_id, const unsigned int& f, const unsigned int& c) const;
    /**
     * @brief Consulta el nombre d'unitats d'un producte al magatzem
     *
     * @param prod_id identificador del producte a consultar
     *
     * @return nombre d'unitats del producte al magatzem
     *
     * @throws error si el producte no existeix
     */
    unsigned int consultar_prod(const std::string& prod_id) const;
};

#endif // ifndef MAGATZEM_H
