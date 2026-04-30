#include <iostream>
using namespace std;
char censurar(char c){

char lower = tolower (c);
if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u' )
{
    return '*';
}
 else {
    return c;
 }
    
}

int main (){

    string frase;
    cout << "ingrese una frase: ";
    getline (cin, frase);
    for ( int i = 0; i < frase.length(); i++)
    {
        cout << censurar(frase [i]);
        }
    
    }
    


