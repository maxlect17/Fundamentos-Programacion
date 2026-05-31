#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    int n;

    // Pide la cantidad de elementos
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    // Crea los vectores
    vector<int> numeros(n);
    vector<int> mayores;

    srand(time(0));

    cout << "\nNumeros generados:\n";

    int suma = 0;

    // Genera numeros aleatorios
    for (int i = 0; i < n; i++) {

        numeros[i] = rand() % 11;
        suma += numeros[i];

        cout << numeros[i] << " ";
    }

    // Calcula la media
    double media = (double)suma / n;

    // Guarda los numeros mayores que la media
    for (int i = 0; i < n; i++) {

        if (numeros[i] > media) {
            mayores.push_back(numeros[i]);
        }
    }

    // Muestra la media
    cout << "\n\nMedia = " << media;

    // Muestra los numeros mayores que la media
    cout << "\nElementos mayores que la media:\n";

    for (int i = 0; i < mayores.size(); i++) {
        cout << mayores[i] << " ";
    }

    cout << endl;
}
