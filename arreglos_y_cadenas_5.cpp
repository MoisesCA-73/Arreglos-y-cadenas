#include <iostream>

using namespace std;

//Concatena la cadena a, a la cadena b
void concatenate(string a, string &b)
{
    string c = b + a;
    b = c;
}

int main()
{
    string cadena1 {" mas importante del Peru."};
    string cadena2 {"Arequipa es la segunda ciudad"};
    
    cout << "La cadena A es: " << cadena1 << endl;
    cout << "La cadena B es: " << cadena2 << endl;

    concatenate(cadena1,cadena2);

    cout << "La nueva cadena B concatenada es: " << cadena2 << endl;
    
    return 0;
}