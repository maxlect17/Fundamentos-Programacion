#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, m;

    cout << "Ingrese el numero de estudiantes: ";
    cin >> n;

    cout << "Ingrese el numero de asignaturas: ";
    cin >> m;

    // matriz de calificaciones
    vector<vector<float>> notas(n, vector<float>(m));

    // los vectores de promedios
    vector<float> promedioEstudiantes(n);
    vector<float> promedioAsignaturas(m);

    cout << "\nIngrese las calificaciones:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            cin >> notas[i][j];


            while (notas[i][j] < 0.0 || notas[i][j] > 5.0) {
                cout << "Nota invalida. Ingrese nuevamente: ";
                cin >> notas[i][j];
            }
        }
    }

    // Calcula el promedio por estudiante
    for (int i = 0; i < n; i++) {

        float suma = 0;

        for (int j = 0; j < m; j++) {
            suma += notas[i][j];
        }

        promedioEstudiantes[i] = suma / m;
    }

    // Calcula el promedio por asignatura
    for (int j = 0; j < m; j++) {

        float suma = 0;

        for (int i = 0; i < n; i++) {
            suma += notas[i][j];
        }

        promedioAsignaturas[j] = suma / n;
    }

    // Muestra el promedio de los estudiantes
    cout << "\nPromedio de estudiantes:\n";

    for (int i = 0; i < n; i++) {
        cout << "Estudiante " << i + 1
            << ": " << promedioEstudiantes[i] << endl;
    }

    // Muestra el promedio de las asignaturas
    cout << "\nPromedio de asignaturas:\n";

    for (int j = 0; j < m; j++) {
        cout << "Asignatura " << j + 1
            << ": " << promedioAsignaturas[j] << endl;
    }

    // Busca el estudiante con mayor promedio
    float mayorProm = promedioEstudiantes[0];
    int indiceEst = 0;

    for (int i = 1; i < n; i++) {

        if (promedioEstudiantes[i] > mayorProm) {
            mayorProm = promedioEstudiantes[i];
            indiceEst = i;
        }
    }

    // Busca la asignatura con menor promedio
    float menorProm = promedioAsignaturas[0];
    int indiceAsig = 0;

    for (int j = 1; j < m; j++) {

        if (promedioAsignaturas[j] < menorProm) {
            menorProm = promedioAsignaturas[j];
            indiceAsig = j;
        }
    }

    // Muestra los resultados
    cout << "\nEstudiante con mayor promedio:\n";
    cout << "Estudiante " << indiceEst + 1
        << " con promedio " << mayorProm << endl;

    cout << "\nAsignatura con menor promedio:\n";
    cout << "Asignatura " << indiceAsig + 1
        << " con promedio " << menorProm << endl;

}
