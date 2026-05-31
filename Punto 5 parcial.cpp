#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;

    // Muestra el tamaño de la matriz, nosirve la ñ
    cout << "Ingrese el tamaño de la matriz: "; 
    cin >> n;

    // Crea la matriz cuadrada
    vector<vector<int>> matriz(n, vector<int>(n));

    // Lee los numeros de la matriz
    cout << "\nIngrese los elementos de la matriz:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    // Guarda el tipo de matriz
    bool superior = true;
    bool inferior = true;
    bool diagonal = true;

    // Revisa los numeros de la matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // Revisa si es triangular superior
            if (i > j && matriz[i][j] != 0) {
                superior = false;
            }

            // Revisa si es triangular inferior
            if (i < j && matriz[i][j] != 0) {
                inferior = false;
            }

            // Revisa si es diagonal
            if (i != j && matriz[i][j] != 0) {
                diagonal = false;
            }
        }
    }

    // Muestra el resultado
    cout << endl;

    if (diagonal) {
        cout << "La matriz es diagonal";
    }
    else if (superior) {
        cout << "La matriz es triangular superior";
    }
    else if (inferior) {
        cout << "La matriz es triangular inferior";
    }
    else {
        cout << "La matriz no es triangular";
    }
}