//Link del repositorio: https://github.com/MoisesCA-73/Arreglos-y-cadenas

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
    if(n == 1)  //cuando el tamano sea 1, ese valor unico sera la suma total
    {
        return arr[0];
    }
    int* new_arr = new int [n/2];
    for (int i = 0; i < n-1; i+=2)
    {
        new_arr[i/2] = arr[i] + arr[i+1]; 
    }
    if (n%2 != 0)
    {
        new_arr[n/2 - 1] += arr[n-1];
    }
    return sum_rec(new_arr,n/2);
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


    //Se puede comentar estos pasos si el tamano del arreglo es muy largo (1000000), con el proposito de no imprimir un monton de numeros y sobrecargar la terminal
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
