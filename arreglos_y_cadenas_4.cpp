#include <iostream>

using namespace std;

int size_itr(string cadena)
{
    int i;
    for (i = 0; cadena[i] != '\0';i++ ){}//itera hasta que un caracter sea '\0' que es el final de la cadena
    return i;
}

int size_rec(string cadena, int i = 0)
{
    if (cadena[i] == '\0') //si el caracter es '\0' significa que la cadena termino
    {
        return 0;
    }
    return 1 + size_rec(cadena,i+1); //llama de nuevo a la funcion para ver si el siguiente caracter es '\0'
}

int main()
{
    string cadena {"Hola mundo!"};
    cout << "La cadena es: " << cadena << endl;
    cout << "El tamano de la cadena, hallado de manera iterativa es de: " << size_itr(cadena) << endl;
    cout << "El tamano de la cadena, hallado de manera recursiva es de: " << size_rec(cadena) << endl;


    return 0;
}