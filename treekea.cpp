#include "magatzem.h"

#include <iostream>
using namespace std;

#define SPC "  "
#define coutS cout << SPC

int main() {
    Magatzem mag;

    mag.inicialitza();

    for (string operacio; cin >> operacio and operacio != "fin";) {
        cout << operacio << endl;

        try {
            if (operacio == "poner_prod") {
                string prod_id;
                cin >> prod_id;
                mag.poner_prod(prod_id);
            } else if (operacio == "quitar_prod") {
                string prod_id;
                cin >> prod_id;
                mag.quitar_prod(prod_id);
            } else if (operacio == "poner_items") {
                string prod_id;
                int sala_id, cantidad;
                cin >> sala_id >> prod_id >> cantidad;
                coutS << mag.poner_items(sala_id, prod_id, cantidad) << endl;
            } else if (operacio == "quitar_items") {
                string prod_id;
                int sala_id, cantidad;
                cin >> sala_id >> prod_id >> cantidad;
                coutS << mag.quitar_items(sala_id, prod_id, cantidad) << endl;
            } else if (operacio == "distribuir") {
                string prod_id;
                int cantidad;
                cin >> prod_id >> cantidad;
                coutS << mag.distribuir(prod_id, cantidad) << endl;
            } else if (operacio == "compactar") {
                int sala_id;
                cin >> sala_id;
                mag.compactar(sala_id);
            } else if (operacio == "reorganizar") {
                int sala_id;
                cin >> sala_id;
                mag.reorganizar(sala_id);
            } else if (operacio == "redimensionar") {
                int sala_id, f, c;
                cin >> sala_id >> f >> c;
                mag.redimensionar(sala_id, f, c);
            } else if (operacio == "inventario") {
                mag.inventario();
            } else if (operacio == "escribir") {
                int sala_id;
                cin >> sala_id;
                mag.escribir(sala_id);
            } else if (operacio == "consultar_pos") {
                int sala_id, f, c;
                cin >> sala_id >> f >> c;
                coutS << mag.consultar_pos(sala_id, f, c)->consulta_id() << endl;
            } else if (operacio == "consultar_prod") {
                string prod_id;
                cin >> prod_id;
                coutS << mag.consultar_prod(prod_id) << endl;
            } else throw "invalid command";
        } catch (...) {
            coutS << "error" << endl;
        }

    }
    cout << "fin" << endl;
}
