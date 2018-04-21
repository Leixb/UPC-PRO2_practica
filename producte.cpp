#include<string>
using std::string;

class Producte {
    string id;

    unsigned int unitats;

    public:

    Producte(string id): id(id), unitats(0) {}

    string consulta_id() const {
        return id;
    }
    unsigned int consulta_unitats() const {
        return unitats;
    }

    void afegir(const unsigned int& num=1) {
        unitats+=num;
    };

    void treure(const unsigned int& num=1) {
        if (unitats < num) throw "No es poden treure mes unitats";
        unitats-=num;
    }

    void mostra() const {
        cout << id << ' ' << unitats << endl;
    }
};
