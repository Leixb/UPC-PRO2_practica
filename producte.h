#ifndef PRODUCTE_H
#define PRODUCTE_H

#include<string>
using std::string;

class Producte {
    string id;

    unsigned int unitats;

    public:

    Producte(string id);

    std::string consulta_id() const;
    unsigned int consulta_unitats() const;

    void afegir(const unsigned int& num=1);
    void treure(const unsigned int& num=1);

    void mostra() const;
};

#endif // ifndef PRODUCTE_H
