#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Revisa si un numero es primo
bool esPrimo(int num) {

    if (num < 2)
        return false;

    for (int i = 2; i <= sqrt(num); i++) {

        if (num % i == 0)
            return false;
    }

    return true;
}

int main() {

    int n;

    // Pide el tamaño de la matriz
    cout << "Ingrese el valor de n: ";
    cin >> n;

    // Crea la matriz cuadrada
    vector<vector<int>> matriz(n, vector<int>(n));

    srand(time(0));

    // Genera numeros aleatorios
    cout << "\nmatriz generada:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            matriz[i][j] = rand() % 51;
            cout << matriz[i][j] << "\t";
        }

        cout << endl;
    }

    int sumaPrincipal = 0;
    int sumaSecundaria = 0;

    // Muestra la diagonal principal
    cout << "\nDiagonal principal: ";

    for (int i = 0; i < n; i++) {

        cout << matriz[i][i] << " ";
        sumaPrincipal += matriz[i][i];
    }

    // Muestra la diagonal secundaria
    cout << "\nDiagonal secundaria: ";

    for (int i = 0; i < n; i++) {

        cout << matriz[i][n - 1 - i] << " ";
        sumaSecundaria += matriz[i][n - 1 - i];
    }

    // Muestra las sumas de diagonales
    cout << "\nSuma diagonal principal: " << sumaPrincipal;
    cout << "\nSuma diagonal secundaria: " << sumaSecundaria << endl;

    // Guarda la primera fila y la ultima columna
    vector<int> fila(n), columna(n), resultado(n);

    for (int i = 0; i < n; i++) {

        fila[i] = matriz[0][i];
        columna[i] = matriz[i][n - 1];
    }

    // Calcula cuadrados sumados
    cout << "\nVector resultado (cuadrados sumados): ";

    for (int i = 0; i < n; i++) {

        resultado[i] = pow(fila[i], 2) + pow(columna[i], 2);
        cout << resultado[i] << " ";
    }

    cout << endl;

    int contadorPrimos = 0;

    // Cuenta numeros primos
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (esPrimo(matriz[i][j])) {
                contadorPrimos++;
            }
        }
    }

    cout << "\nCantidad de numeros primos: " << contadorPrimos << endl;

    int pares = 0;
    int impares = 0;
    int divisibles3 = 0;

    // Cuenta pares, impares y divisibles por 3
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (matriz[i][j] % 2 == 0)
                pares++;
            else
                impares++;

            if (matriz[i][j] % 3 == 0)
                divisibles3++;
        }
    }

    // Muestra resultados
    cout << "\nCantidad de pares: " << pares;
    cout << "\nCantidad de impares: " << impares;
    cout << "\nCantidad divisibles por 3: " << divisibles3 << endl;

    vector<int> sumaColumnas(n);

    // Muestra tabla con seno
    cout << "\nTABLA:\n";
    cout << "X (Suma columna)\tY (Seno)\n";

    for (int j = 0; j < n; j++) {

        sumaColumnas[j] = 0;

        for (int i = 0; i < n; i++) {
            sumaColumnas[j] += matriz[i][j];
        }

        double radianes =
            sumaColumnas[j] * 3.141592653589793 / 180.0;

        double seno = sin(radianes);

        cout << sumaColumnas[j]
            << "\t\t\t"
            << seno << endl;
    }

    vector<double> vector1D;

    double sumaTotal = 0;

    // Guarda la matriz en un vector
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            vector1D.push_back(matriz[i][j]);
            sumaTotal += matriz[i][j];
        }
    }

    // Calcula el promedio
    double promedio = sumaTotal / (n * n);

    cout << "\nPromedio de los elementos: "
        << promedio << endl;

    // Divide el vector por el promedio
    cout << "\nVector dividido por el promedio:\n";

    for (int i = 0; i < vector1D.size(); i++) {

        vector1D[i] = vector1D[i] / promedio;

        cout << vector1D[i] << " ";
    }

    cout << endl;
}
