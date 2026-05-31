// punto 7.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
bool espalindromo(int n) {
	int orig = n;
	int invertido = 0;


	while (n > 0)
	{
		int digito = n % 10;
		invertido = invertido * 10 + digito;
		n = n / 10;

	}
	return invertido == orig;
}
int main() {
	int n1;
	cout << "ingresa un numero positivo: " << "\n";
	cin >> n1;
	if (n1 < 0)
	{
		cout << "ingrese correctamente un numero positivo";
		return 0;
	}
	if (espalindromo(n1))
	{
		cout << "el numero es un palindromo";
	}
	else {
		cout << "el numero no es un palindromo";
	}
}



