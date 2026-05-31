#include <iostream>
using namespace std;
int main()
{
    long long n1;
    long long n2;
    long long r = -1;
    long long n3;
    long long n4;
    long long r2;
    long long mcm;

    cout << "ponga 2 numeros enteros positivos: ";
    cin >> n1;
    cin >> n2;
    n3 = n1;
    n4 = n2;
    if (n2 == 0){
        return 0;
    }

    if (n1 < 0 || n2 <0)
    {
        cout << "coloque correctamente los numeros";
        return 0;
    }
    while (n2 !=0)
    {
        r = n1 % n2;
            n1 = n2;
            n2 = r;
            
        }
    r2 = n3 * n4;
    mcm = r2 / n1;

    cout << "el Maximo Comun Divisor de los numeros, es: " << n1 << "\n";
    cout << "el Minimo Comun Multiplo, es: " << mcm;
    }

 



