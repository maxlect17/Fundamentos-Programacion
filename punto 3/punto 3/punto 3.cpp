#include <cmath>
#include <iostream>
using namespace std;
int main() {
	int notas = 0;
	float n;
	float suma = 0;
	float max = -1, min = 6;
	int aprobados = 0, reprobados = 0;
	while (true)
	{
		cout << "ingrese el numero de notas (si ingresa -1 se acaba).\n"; 
		cin >> n;
		if (n == -1)
		
			break;
		
		if (n < 0 || n > 5) {
			cout << "numero invalido, ingrese nuevamente.\n";
			continue;
	}
		suma += n;
		if (n > max) max = n;
		if (n < min) min = n;

		if (n >= 3.0)
			aprobados++;
		else
			reprobados++;
		notas++;
	}

	if (notas == 0) {
		cout << "ingrese notas correctas plis. \n";
			return 0;
	}
	float promedio = suma / notas;

	cout << "Cantidad: " << notas << endl;
	cout << "Promedio: " << promedio << endl;
	cout << "Maxima: " << max << endl;
	cout << "Minima: " << min << endl;
	cout << "Aprobados: " << aprobados << endl;
	cout << "Reprobados: " << reprobados << endl;
}