#include <iostream>
using namespace std;


bool esPerfecto(int n)
{
    int suma = 0;

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            suma += i;
        }
    }

    return suma == n;
}

int main()
{
    int num;

    while (true)
    {
        cin >> num;

        if (num == 0)
        {
            break;
        }

        if (num > 0)
        {
            if (esPerfecto(num))
            {
                cout << num << " es perfecto" << endl;
            }
            else
            {
                cout << num << " no es perfecto" << endl;
            }
        }
    }

    return 0;
}
