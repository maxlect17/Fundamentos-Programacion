#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Calcula el factorial de un numero
int factorial(int n) {

    int resultado = 1;

    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }

    return resultado;
}

int main() {

    int n;

    // Pide la cantidad de elementos
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    // Crea el vector
    vector<int> numeros(n);

    srand(time(0));

    // Genera numeros aleatorios
    cout << "\nNumeros generados:\n";

    for (int i = 0; i < n; i++) {
        numeros[i] = rand() % 11;
        cout << numeros[i] << " ";
    }

    // Muestra los factoriales
    cout << "\n\nFactoriales:\n";

    for (int i = 0; i < n; i++) {

        cout << numeros[i] << "! = "
            << factorial(numeros[i]) << endl;
    }
}