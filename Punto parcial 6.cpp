#include <iostream>
#include <vector>

using namespace std;

int main() {

    int filas, columnas;

    cout << "Ingrese el numero de filas: ";
    cin >> filas;

    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;

    vector<vector<int>> matriz(filas, vector<int>(columnas));

    cout << "\nIngrese los elementos de la matriz:\n";

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> matriz[i][j];
        }
    }

    int maximo = matriz[0][0];
    int minimo = matriz[0][0];

    int filaMax = 0, columnaMax = 0;
    int filaMin = 0, columnaMin = 0;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {

            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
                filaMax = i;
                columnaMax = j;
            }

            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
                filaMin = i;
                columnaMin = j;
            }
        }
    }

    cout << "\nMaximo: " << maximo
        << " en fila " << filaMax + 1
        << " columna " << columnaMax + 1;

    cout << "\nMinimo: " << minimo
        << " en fila " << filaMin + 1
        << " columna " << columnaMin + 1;

    // Intercambiar primera y última fila
    for (int j = 0; j < columnas; j++) {
        int aux = matriz[0][j];
        matriz[0][j] = matriz[filas - 1][j];
        matriz[filas - 1][j] = aux;
    }

    cout << "\n\nMatriz con filas intercambiadas:\n";

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatriz transpuesta:\n";

    for (int j = 0; j < columnas; j++) {
        for (int i = 0; i < filas; i++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
