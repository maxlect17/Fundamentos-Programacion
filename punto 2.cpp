#include <iostream>
using namespace std;

int main() {
    int acumulado = 0;
    int n;
    bool perdio = false;
    bool gano = false;

    while (true) {
        cout << "Ingrese un numero entre 0 y 6: ";
        cin >> n;

        if (n < 0 || n > 6) {
            cout << "Ingrese un numero valido.\n";
            continue;
        }

        if (n == 1) {
            cout << "Perdiste todos tus puntos.\n";
            acumulado = 0;
            perdio = true;
            break;
        }

        if (n == 0) {
            cout << "Fin del juego.\n";
            break;
        }

        acumulado += n;
        cout << "Acumulado: " << acumulado << endl;

        if (acumulado >= 30) {
            gano = true;
            break;
        }
    }

    if (perdio) {
        cout << "Resultado: PERDISTE. Puntaje final: 0\n";
    }
    if (gano) {
        cout << "Resultado: GANASTE. Puntaje final: " << acumulado << endl;
    }
    else {
        cout << "Resultado: TERMINASTE. Puntaje final: " << acumulado << endl;
    }

    return 0;
}
