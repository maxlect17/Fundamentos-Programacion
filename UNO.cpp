#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Cada carta tiene color (0-3) y valor (0-12)
// Colores: 0=Rojo, 1=Verde, 2=Azul, 3=Amarillo
// Valores: 0-9=numeros, 10=Salta, 11=+2, 12=CambiaColor

int mazoColor[108];
int mazoValor[108];
int tamMazo = 0;

int jugadorColor[30];
int jugadorValor[30];
int tamJugador = 0;

int cpuColor[30];
int cpuValor[30];
int tamCPU = 0;

int topeColor;
int topeValor;
int colorActual;

void mostrarCarta(int color, int valor) {
    if (color == 0) cout << "Rojo ";
    if (color == 1) cout << "Verde ";
    if (color == 2) cout << "Azul ";
    if (color == 3) cout << "Amarillo ";
    if (color == 4) cout << "Comodin ";

    if (valor == 10) cout << "Salta";
    else if (valor == 11) cout << "+2";
    else if (valor == 12) cout << "CambiaColor";
    else cout << valor;
}

void crearMazo() {
    tamMazo = 0;
    for (int col = 0; col < 4; col++) {
        for (int num = 0; num <= 9; num++) {
            mazoColor[tamMazo] = col;
            mazoValor[tamMazo] = num;
            tamMazo++;
            if (num != 0) {
                mazoColor[tamMazo] = col;
                mazoValor[tamMazo] = num;
                tamMazo++;
            }
        }
        // Salta y +2, dos veces cada uno
        for (int rep = 0; rep < 2; rep++) {
            mazoColor[tamMazo] = col; mazoValor[tamMazo] = 10; tamMazo++;
            mazoColor[tamMazo] = col; mazoValor[tamMazo] = 11; tamMazo++;
        }
    }
    // 4 cartas CambiaColor
    for (int i = 0; i < 4; i++) {
        mazoColor[tamMazo] = 4;
        mazoValor[tamMazo] = 12;
        tamMazo++;
    }
}

void mezclarMazo() {
    for (int i = tamMazo - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tc = mazoColor[i]; mazoColor[i] = mazoColor[j]; mazoColor[j] = tc;
        int tv = mazoValor[i]; mazoValor[i] = mazoValor[j]; mazoValor[j] = tv;
    }
}

void robarUna(int colores[], int valores[], int& tam) {
    colores[tam] = mazoColor[tamMazo - 1];
    valores[tam] = mazoValor[tamMazo - 1];
    tamMazo--;
    tam++;
}

bool esJugable(int color, int valor) {
    if (color == 4) return true;
    if (color == colorActual) return true;
    if (valor == topeValor) return true;
    return false;
}

int main() {
    srand(time(0));

    crearMazo();
    mezclarMazo();

    // Repartir 7 cartas a cada uno
    for (int i = 0; i < 7; i++) robarUna(jugadorColor, jugadorValor, tamJugador);
    for (int i = 0; i < 7; i++) robarUna(cpuColor, cpuValor, tamCPU);

    // Carta inicial (que no sea comodin)
    do {
        topeColor = mazoColor[tamMazo - 1];
        topeValor = mazoValor[tamMazo - 1];
        tamMazo--;
    } while (topeColor == 4);
    colorActual = topeColor;

    cout << "UNO\n";
    cout << "Carta inicial: ";
    mostrarCarta(topeColor, topeValor);
    cout << "\n\n";

    bool turnoJugador = true;

    while (true) {

        if (turnoJugador) {
            cout << "Tu turno";
            cout << "Carta en mesa: ";
            mostrarCarta(topeColor, topeValor);
            cout << "  (color activo: ";
            if (colorActual == 0) cout << "Rojo";
            if (colorActual == 1) cout << "Verde";
            if (colorActual == 2) cout << "Azul";
            if (colorActual == 3) cout << "Amarillo";
            cout << ")\n";

            cout << "Tu mano:\n";
            for (int i = 0; i < tamJugador; i++) {
                cout << i + 1 << ". ";
                mostrarCarta(jugadorColor[i], jugadorValor[i]);
                cout << "\n";
            }

            // Ver si tiene carta jugable
            bool tieneJugable = false;
            for (int i = 0; i < tamJugador; i++)
                if (esJugable(jugadorColor[i], jugadorValor[i]))
                    tieneJugable = true;

            if (!tieneJugable) {
                cout << "No tienes cartas jugables. Robas una.\n";
                robarUna(jugadorColor, jugadorValor, tamJugador);
                turnoJugador = false;
                continue;
            }

            int op;
            cout << "Elige carta: ";
            cin >> op;
            op--;

            if (op < 0 || op >= tamJugador || !esJugable(jugadorColor[op], jugadorValor[op])) {
                cout << "Carta invalida, pierdes el turno.\n";
                turnoJugador = false;
                continue;
            }

            topeColor = jugadorColor[op];
            topeValor = jugadorValor[op];
            colorActual = topeColor;

            // Quitar carta de la mano
            for (int i = op; i < tamJugador - 1; i++) {
                jugadorColor[i] = jugadorColor[i + 1];
                jugadorValor[i] = jugadorValor[i + 1];
            }
            tamJugador--;

            cout << "Jugaste: ";
            mostrarCarta(topeColor, topeValor);
            cout << "\n";

            if (tamJugador == 0) {
                cout << "¡Ganaste!\n";
                return 0;
            }

            if (tamJugador == 1) cout << "¡UNO!\n";

            // Efectos
            if (topeColor == 4) {
                cout << "Elige color (0=Rojo 1=Verde 2=Azul 3=Amarillo): ";
                cin >> colorActual;
                turnoJugador = false;
                continue;
            }
            if (topeValor == 10) {
                cout << "Salta: CPU pierde turno.\n";
                turnoJugador = true;
                continue;
            }
            if (topeValor == 11) {
                cout << "+2: CPU roba 2 cartas.\n";
                robarUna(cpuColor, cpuValor, tamCPU);
                robarUna(cpuColor, cpuValor, tamCPU);
                turnoJugador = true;
                continue;
            }

            turnoJugador = false;

        }
        else {
            cout << "--- Turno CPU ---\n";

            // Buscar carta jugable
            int idx = -1;
            for (int i = 0; i < tamCPU; i++) {
                if (esJugable(cpuColor[i], cpuValor[i])) {
                    idx = i;
                    break;
                }
            }

            if (idx == -1) {
                cout << "CPU roba una carta y pasa.\n";
                robarUna(cpuColor, cpuValor, tamCPU);
                turnoJugador = true;
                continue;
            }

            topeColor = cpuColor[idx];
            topeValor = cpuValor[idx];
            colorActual = topeColor;

            for (int i = idx; i < tamCPU - 1; i++) {
                cpuColor[i] = cpuColor[i + 1];
                cpuValor[i] = cpuValor[i + 1];
            }
            tamCPU--;

            cout << "CPU jugo: ";
            mostrarCarta(topeColor, topeValor);
            cout << "\n";

            if (tamCPU == 0) {
                cout << "La CPU gano. Suerte la proxima.\n";
                return 0;
            }

            if (tamCPU == 1) cout << "¡La CPU grita UNO!\n";

            // Efectos
            if (topeColor == 4) {
                // CPU elige el color que mas tiene
                int conteo[4] = { 0, 0, 0, 0 };
                for (int i = 0; i < tamCPU; i++)
                    if (cpuColor[i] < 4) conteo[cpuColor[i]]++;
                int mejor = 0;
                for (int i = 1; i < 4; i++)
                    if (conteo[i] > conteo[mejor]) mejor = i;
                colorActual = mejor;
                cout << "CPU eligio color: ";
                if (colorActual == 0) cout << "Rojo";
                if (colorActual == 1) cout << "Verde";
                if (colorActual == 2) cout << "Azul";
                if (colorActual == 3) cout << "Amarillo";
                cout << "\n";
                turnoJugador = true;
                continue;
            }
            if (topeValor == 10) {
                cout << "Salta: pierdes tu turno.\n";
                turnoJugador = false;
                continue;
            }
            if (topeValor == 11) {
                cout << "+2: robas 2 cartas.\n";
                robarUna(jugadorColor, jugadorValor, tamJugador);
                robarUna(jugadorColor, jugadorValor, tamJugador);
                turnoJugador = false;
                continue;
            }

            turnoJugador = true;
        }
    }

    return 0;
}