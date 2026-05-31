// punto 4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
int main()
{
	int n;
	int b[32];
	char h[32];
	int i = 0;
	int k = 0;
	cout << "meta un numero entre 1 y 255. \n";
	cin >> n;
	if (n < 1 || n > 255)
	{
		cout << "ponga un numero correcto";
		return 0;
	}
	int n2 = n;
	while (n > 0) {
		b[i] = n % 2;
		n = n / 2;
		i++;
	}
		while (n2 > 0) {
			int r = n2 % 16;

			if (r < 10)
				h[k] = r + '0';
			else
				h[k] = r - 10 + 'A';

			n2 = n2 / 16;
			k++;
		}
		cout << "numero en binario : ";
		for (int j = i - 1; j >= 0; j--)
		{
			cout << b[j];

		}
		cout <<" " << "Hexadecimal: ";
		for (int j = k - 1; j >= 0; j--) {
			cout << h[j];
	}
	
}
	
