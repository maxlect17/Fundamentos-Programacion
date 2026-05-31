#include <iostream>;
using namespace std;
int main()
{
    long long n;
    int pasos = 0;
    cout << "coloque un numero positivo mayor que 1.\n";
    cin >> n;

    if (n <= 1)
    {
        cout << "ponga un numero correcto";
        return 0;
    }
    long long maximo = n;
    cout << n;

    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = n * 3 + 1;
        }
        pasos++;
        cout << " -> " << n;
        if (n > maximo)
        {
            maximo = n;
        }
        
    }
    cout << "\n" << "se dieron " << pasos << " pasos";
    cout << "\n" << "el numero maximo es: " << maximo;
}
