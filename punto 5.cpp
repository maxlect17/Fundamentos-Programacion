#include <iostream>
using namespace std;

int main()
{
    int n;
    int d = 2;
    int contador = 0;
    cin >> n;
   
    if (n <= 1)
    {
        return 0;
    }
    while (n > 1)
    {
        if (n % d == 0) {

            cout << " " << d << " ";
            n = n / d;
            contador++;

            if (n > 1)
                cout << "x";
        }
            else
                d++;
        
}
    cout << contador;
}


