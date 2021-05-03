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

//Revierte un arreglo de enteros de forma recursiva
void rev_rec(int *arr, int n, int m)
{
    if (m/2 >= m-n)
    {
        int aux = arr[m-n];
        arr[m-n] = arr[n-1];
        arr[n-1] = aux;
        rev_rec(arr,n-1,m);
    }
}

//Revierte un arreglo de forma recursiva
void reverse_rec(int *arr, int n)
{
    if (n != 1)
    {
        int aux = arr[0];
        arr[0] = arr[n-1];
        arr[n-1] = aux;
        rev_rec(arr,n-1,n);
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
    print_array(array,n);

    cout << "Arreglo invertido de forma iterativa:\n";
    reverse_itr(array,n);
    print_array(array,n);

    cout << "Invirtiendo el arreglo invertido de forma recursiva:\n";
    reverse_rec(array,n);
    print_array(array,n);

    return 0;
}