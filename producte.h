#ifndef PRODUCTE_H
#define PRODUCTE_H

#include<string>

class Producte {
    /**
     * @brief Identificador unic del producte
     */
    std::string id;

    /**
     * @brief nombre d'unitats del producte al magatzem
     */
    unsigned int unitats;

    public:

    /**
     * @brief Constructor, crea un Objecte amb l'id associat.
     *
     * @param id id del producte creat.
     *
     * @pre id no comença amb un digit
     */
    Producte(std::string id);

    // Consultors

    /**
     * @return id de l'objecte.
     */
    std::string consulta_id() const;

    /**
     * @return nombre d'unitats de l'objecte al magatzem
     */
    unsigned int consulta_unitats() const;

    // Modificadors

    /**
     * @brief Incrementa el contador d'unitats en num
     *
     * @param num unitats a afegir
     *
     * @post unitats = unitats + num
     */
    void afegir(const unsigned int& num=1);

    /**
     * @brief Decrementa el contador d'unitats en num
     *
     * @param num unitats a disminuir
     *
     * @pre num <= unitats
     *
     * @post unitats = unitats - num
     */
    void treure(const unsigned int& num=1);

    // IO

    /**
     * @brief Mostra per std_out l'id i el nombre d'unitats separats per
     * un espai i seguits d'un salt de linea
     */
    void mostra() const;
};

#endif // ifndef PRODUCTE_H
