#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Calcula la suma de un arreglo de forma iterativa
int sum_itr(int *arr, int n)
{
    int sum{0};
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
//suma de un arreglo de forma recursiva
int sum_rec(int *arr, int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    return arr[n-1] + sum_rec(arr,n-1);
}

//Asigna valores aleatorios al arreglo de 1 a 1000
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


    //Se puede comentar estos paso si es que el tamano del arreglo es muy largo(1000000), con el proposito de no imprimir un monton de numeros
    cout << "ARREGLO:\n";
    print_array(array,n);

    //Suma iterativa
    cout << "Suma Iterativa del arreglo: ";
    cout << sum_itr(array,n) << endl;

    //Suma recursiva
    cout << "Suma Recursiva del arreglo: ";
    cout << sum_rec(array,n) << endl;


    return 0;
}