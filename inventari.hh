#include<map>

class Inventari {
    std::map <std::string, unsigned int> contador;

    unsigned int& query(const std::string& prod_id);

    public:

    void afegir_prod(const std::string prod_id);

    void quitar_prod(const std::string prod_id);

    void afegir_unitats(const std::string& prod_id, const unsigned int& unitats=1);
    void treure_unitats(const std::string& prod_id, const unsigned int& unitats=1);

    unsigned int consultar_producte(const std::string& prod_id);

    void mostra() const;
};
