#include <iostream>
#include <string>
using namespace std;
char censurar(char c) {
c = tolower(c);
if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
{
    return '*';
}
return c;
}
int main()
{
    string frase;
    getline(cin, frase);

    string resultado = "";
    for (int i = 0; i < frase.length(); i++)
    {
        resultado += censurar(frase[i]);
    }
    cout << resultado;
}

