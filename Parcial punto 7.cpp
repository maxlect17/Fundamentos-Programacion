#include <iostream>
#include <vector>

using namespace std;

// se suman los elementos de una filap
int sumaFila(vector<int> fila) {

    int suma = 0;

    for (int i = 0; i < fila.size(); i++) {
        suma += fila[i];
    }

    return suma;
}

int main() {

    int m, p, q;

    cout << "Ingrese filas de A: ";
    cin >> m;

    cout << "Ingrese columnas de A: ";
    cin >> p;

    int filasB;

    cout << "Ingrese filas de B: ";
    cin >> filasB;

    while (p != filasB) {

        cout << "\nError: columnas de A y filas de B deben ser iguales.\n";

        cout << "Ingrese nuevamente filas de B: ";
        cin >> filasB;
    }

    cout << "Ingrese columnas de B: ";
    cin >> q;

    vector<vector<int>> A(m, vector<int>(p));
    vector<vector<int>> B(filasB, vector<int>(q));
    vector<vector<int>> C(m, vector<int>(q, 0));

    cout << "\nIngrese elementos de la matriz A:\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cin >> A[i][j];
        }
    }

    cout << "\nIngrese elementos de la matriz B:\n";

    for (int i = 0; i < filasB; i++) {
        for (int j = 0; j < q; j++) {
            cin >> B[i][j];
        }
    }

    // aca es la parte de multiplicacion de matrices
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nMatriz A:\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatriz B:\n";

    for (int i = 0; i < filasB; i++) {
        for (int j = 0; j < q; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatriz C = A x B:\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nSuma de filas de la matriz C:\n";

    for (int i = 0; i < m; i++) {
        cout << "Fila " << i + 1 << ": "
            << sumaFila(C[i]) << endl;
    }


}
