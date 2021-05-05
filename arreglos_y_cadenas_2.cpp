//Link del repositorio: https://github.com/MoisesCA-73/Arreglos-y-cadenas

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Revierte un arreglo de enteros de forma iterativa
void reverse_itr(int *arr, int n)
{
    int aux;
    for (int i = 0; i < n; i++)
    {
        aux = arr[i];
        arr[i] = arr[n-1];
        arr[n-1] = aux;
        n--;
    }
}

void reverse_rec(int *arr, int n, int m = 0)
{
    if (n/2 <= n-m)     //comprueba si aun no llego a la mitad para terminar
    {
        int aux = arr[m];
        arr[m] = arr[n-m-1];
        arr[n-m-1] = aux;
        reverse_rec(arr,n,m+1);    //swapea los numeros adyacentes
    }
}

void asignar_randoms(int *arr, const int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }
}

//imprime un arreglo de enteros
void print_array(int* arr, const int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

int main()
{
    int m;
    cout << "Digite el numero de elementos del arreglo: ";
    cin >> m;
    const int n {m};

    int *array {new int [n]};
    asignar_randoms(array,n);

    cout << "Arreglo:\n";
    cout << array[0] << endl;
    cout << array[n-1] << endl;
    print_array(array,n);

    cout << "Arreglo invertido de forma iterativa:\n";
    reverse_itr(array,n);
    cout << array[0] << endl;
    cout << array[n-1] << endl;
    print_array(array,n);

    cout << "Invirtiendo el arreglo invertido de forma recursiva:\n";
    reverse_rec(array,n);
    cout << array[0] << endl;
    cout << array[n-1] << endl;
    print_array(array,n);

    return 0;
}
