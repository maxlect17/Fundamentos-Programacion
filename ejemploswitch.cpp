#include <iostream>

using namespace std;

int main()
{
    int i = -1;
    while (i != 0)
    {
        cout << "-- Menu de operaciones --" << "\n";
        cout << "1. Suma" << "\n";
        cout << "2. Resta" << "\n";
        cout << "3. Multiplicación" << "\n";
        cout << "4. División" << "\n";
        cout << "5. Potencia" << "\n";
        cout << "0. Salir" << "\n";
        cout << ": " << endl;
        cin >> i;
        switch (i) 
        {
            case 1 : 
            {
                cout << "Acá se sumó, acto de fe" << "\n";
                break;
            }
            case 2 : 
            {
                cout << "Acá se restó, acto de fe" << "\n";
                break;
            }
            case 3 : 
            {
                cout << "Acá se multiplicó, acto de fe" << "\n";
                break;
            }
            case 4 : 
            {
                cout << "Acá se dividió, acto de fe" << "\n";
                break;
            }
            case 5 : 
            {
                cout << "Acá se elevó a la potencia, acto de fe" << "\n";
                break;
            }
            case 0 :
            {
                cout << "bye, bye!" << endl;
                break;
            }
            default :
            {
                cout << "No es una operación" << "\n";
            }
        }
    }
}