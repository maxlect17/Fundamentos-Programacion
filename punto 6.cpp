// punto 6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

int main()
{    
    int n;
    int contador = 0;
    int d = 2;
    cout << "coloque un numero mayor a 1" << "\n";
    cin >> n;
    if (n <= 1)
    {
        return 0;

    }
    cout << "la descomposicion completa con la notacion indicada, imprimiendo los factores de menor a mayor es: ";
            while (n > 1)
            {
                if (n % d == 0)
                {
                    n = n / d;
                    contador++;
                    cout << " " << d << " ";
                    if (n > 1)
                        cout << "x";
                }
                else
                {
                    d++;

                }


            }
            if (contador == 1)
            {
                cout << "\n" << "el numero es primo";
            }
            else
            {
                cout << "\n" << "el numero no es primo";
            }



            cout << "\n" << "el numero total de factores primos contando repeticiones es: " << contador;
        }


