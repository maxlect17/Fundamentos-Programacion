#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string nivelSeguridad(string pass)
{
    bool tieneMayus = false;
    bool tieneMinus = false;
    bool tieneDigito = false;

    for (int i = 0; i < pass.length(); i++)
    {
        if (isupper(pass[i])) tieneMayus = true;
        if (islower(pass[i])) tieneMinus = true;
        if (isdigit(pass[i])) tieneDigito = true;
    }
    int criterios = 0;

    if (pass.length() >= 8) criterios++;
    if (tieneMayus) criterios++;
    if (tieneMinus) criterios++;
    if (tieneDigito) criterios++;

    if (criterios == 4)
        return "Fuerte";
    else if (criterios >= 2)
        return "Media";
    else
        return "Debil";
}
int main()
{
    string pass;
    cout << "ingresa la contrasena: ";
    cin >> pass;

    cout << "Nivel: " << nivelSeguridad(pass);

    return 0;
}