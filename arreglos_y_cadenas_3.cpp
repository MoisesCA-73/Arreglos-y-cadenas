#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Merge Sort

//matriz con un elemento anadido
int* add(int *arr, int x, int &n)
{
    int *aux = new int[n+1];
    for (int  i = 0; i < n; i++)
    {
        aux[i] = arr[i];
    }
    aux[n] = x;
    n++;
    return aux;
}

//matriz con el primer elemento eliminado

int* remove(int *arr, int &n)
{
    int* aux = new int[n-1];
    for (int  i = 0; i < n-1; i++)
    {
        aux[i] = arr[i+1];
    }
    n--;
    return aux;
}

int* merge(int *arr1, int n1, int *arr2, int n2)
{
    int n3 = 0;
    int* arr3 = new int [n3];
    //hasta que algun array se quede sin elementos
    while(n1 > 0 && n2 > 0)
    {
        if(arr1[0] > arr2[0])
        {
            arr3 = add(arr3,arr2[0],n3);
            arr2 = remove(arr2,n2);
        }
        else
        {
            arr3 = add(arr3,arr1[0],n3);
            arr1 = remove(arr1,n1);
        }
    }
    //a este punto un arreglo ya esta vacio asi que se anaden los demas
    while(n1 > 0)
    {
        arr3 = add(arr3,arr1[0],n3);
        arr1 = remove(arr1,n1);
    }
    while(n2 > 0)
    {
        arr3 = add(arr3,arr2[0],n3);
        arr2 = remove(arr2,n2);
    }

    return arr3;
}

int* merge_sort(int *arr, int &n)
{
    if(n == 1)
    {
        return arr;
    }
    int n1, n2;
    n1 = n/2;
    if (n%2 == 0) 
    {  
        n2 = n/2;
    }
    else
    {
        n2 = (n/2)+1;
    }
    int* arr1 = new int [n1];
    int* arr2 = new int [n2];
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[i];
    }
    for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[i+n1];
    }

    arr1 = merge_sort(arr1,n1); //recursion para dividir los arrays
    arr2 = merge_sort(arr2,n2);

    return merge(arr1,n1,arr2,n2); // se comparan dos arrays entre si, se ordenan y se unen

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
    int n {m};

    int *array {new int [n]};
    asignar_randoms(array,n);

    cout << "Arreglo:\n";
    print_array(array,n);

    cout << "Arreglo ordenado de manera ascendente por algoritmo de merge sort:\n";
    array = merge_sort(array,n);
    print_array(array,n);

    return 0;
}