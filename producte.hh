#ifndef PRODUCTE_H
#define PRODUCTE_H

#include<string>

/**
 * @brief Producte del magatzem
 */
class Producte {
    std::string id; ///< Identificador unic del producte

    unsigned int unitats; ///< Nombre d'unitats del producte al magatzem

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
     * @return @ref id
     */
    std::string consulta_id() const;

    /**
     * @return @ref unitats
     */
    unsigned int consulta_unitats() const;

    // Modificadors

    /**
     * @brief Incrementa el contador d'unitats en @p num
     *
     * @param num unitats a afegir
     *
     * @post @ref unitats = @ref unitats + @p num
     */
    void afegir(const unsigned int& num=1);

    /**
     * @brief Decrementa el contador d'unitats en @p num
     *
     * @param num unitats a disminuir
     *
     * @pre @p num <= @ref unitats
     *
     * @post @ref unitats = @ref unitats - @p num
     */
    void treure(const unsigned int& num=1);

    // IO

    /**
     * @brief Mostra per std_out l'@ref id i les @ref unitats separats per
     * un espai i seguits d'un salt de linea
     */
    void mostra() const;
};

#endif // ifndef PRODUCTE_H
