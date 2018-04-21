#ifndef PRODUCTE_H
#define PRODUCTE_H

#include<string>

class Producte {
    std::string id;

    unsigned int unitats;

    public:

    Producte(std::string id);

    std::string consulta_id() const;
    unsigned int consulta_unitats() const;

    void afegir(const unsigned int& num=1);
    void treure(const unsigned int& num=1);

    void mostra() const;
};

#endif // ifndef PRODUCTE_H
