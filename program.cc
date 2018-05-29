/**
 * @file program.cc
 * @brief Programa principal (main)
 */

/**
 * @mainpage TreeKEA
 *
 * Aquest programa permet consultar i realitzar operacions sobre un magatzem
 * estructurat en un arbre tal com descriu l'enunciat de la pràctica.
 *
 * S'implementen 3 classes:
 * - Magatzem
 * - Sala
 * - Inventari
 */
#include "excepcions.hh"
#include "magatzem.hh"

#include <iostream>

using namespace std;

#define SPC "  "
#define OUTPUT(x)\
do {\
    const auto out = x;\
    cout << SPC << out << endl;\
} while(false)

int main() {
    ios_base::sync_with_stdio(false);

    Magatzem mag;

    mag.inicialitza();

    for (string operacio; cin >> operacio and operacio != "fin";) {
        cout << operacio;

        try {
            if (operacio == "poner_prod") {
                string prod_id;
                cin >> prod_id;
                cout << ' ' << prod_id << endl;

                mag.poner_prod(prod_id);
            } else if (operacio == "quitar_prod") {
                string prod_id;
                cin >> prod_id;

                cout << ' ' << prod_id << endl;

                mag.quitar_prod(prod_id);
            } else if (operacio == "poner_items") {
                string prod_id;
                int sala_id, cantidad;
                cin >> sala_id >> prod_id >> cantidad;

                cout << ' ' << sala_id << ' ' << prod_id << ' ' << cantidad << endl;
                OUTPUT(mag.poner_items(sala_id, prod_id, cantidad));

            } else if (operacio == "quitar_items") {
                string prod_id;
                int sala_id, cantidad;
                cin >> sala_id >> prod_id >> cantidad;

                cout << ' ' << sala_id << ' ' << prod_id << ' ' << cantidad << endl;

                OUTPUT(mag.quitar_items(sala_id, prod_id, cantidad));
            } else if (operacio == "distribuir") {
                string prod_id;
                int cantidad;
                cin >> prod_id >> cantidad;

                cout << ' ' << prod_id << ' ' << cantidad << endl;

                OUTPUT(mag.distribuir(prod_id, cantidad));
            } else if (operacio == "compactar") {
                int sala_id;
                cin >> sala_id;

                cout << ' ' << sala_id << endl;

                mag.compactar(sala_id);
            } else if (operacio == "reorganizar") {
                int sala_id;
                cin >> sala_id;

                cout << ' ' << sala_id << endl;

                mag.reorganizar(sala_id);
            } else if (operacio == "redimensionar") {
                int sala_id, f, c;
                cin >> sala_id >> f >> c;

                cout << ' ' << sala_id << ' ' << f << ' ' << c << endl;

                mag.redimensionar(sala_id, f, c);
            } else if (operacio == "inventario") {
                cout << endl;
                mag.inventario();
            } else if (operacio == "escribir") {
                int sala_id;
                cin >> sala_id;

                cout << ' ' << sala_id << endl;

                mag.escribir(sala_id);
            } else if (operacio == "consultar_pos") {
                int sala_id, f, c;
                cin >> sala_id >> f >> c;

                cout << ' ' << sala_id << ' ' << f << ' ' << c << endl;

                OUTPUT(mag.consultar_pos(sala_id, f, c));
            } else if (operacio == "consultar_prod") {
                string prod_id;
                cin >> prod_id;

                cout << ' ' << prod_id << endl;

                OUTPUT(mag.consultar_prod(prod_id));
            } else throw "invalid command";
        } catch (const ExpectedError& e) {
            OUTPUT("error");

            #ifdef DEBUG
                cerr << e.what() << endl;
            #endif //DEBUG

        }
    }
    cout << "fin" << endl;
}
