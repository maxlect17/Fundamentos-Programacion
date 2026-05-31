#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string convertirMayusculaInicial(string palabra) {
    if (palabra.length() > 0) {
        palabra[0] = toupper(palabra[0]);
    }
    return palabra;
}

int main() {
    string frase;
    cout << "Ingrese una frase: ";
    getline(cin, frase);

    string palabra = "";
    string resultado = "";

    for (int i = 0; i < frase.length(); i++) {
        if (frase[i] != ' ') {
            palabra += frase[i];
        }
        else {
            resultado += convertirMayusculaInicial(palabra) + " ";
            palabra = "";
        }
    }
    if (!palabra.empty()) {
        resultado += convertirMayusculaInicial(palabra);
    }

    cout << "Frase convertida: " << resultado << endl;

    return 0;
}