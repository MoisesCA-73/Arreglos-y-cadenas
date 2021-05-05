//Link del repositorio: https://github.com/MoisesCA-73/Arreglos-y-cadenas

#include <iostream>

using namespace std;

string palabras[30] = {"hola","pero","poder","como","sobre","ahora","despues","antes","estar","ser","cadenas","abrazo","cada","todos","mundo","gran","pais","segun"."aunque","hasta","vida","decir","tambien","tanto","tres","gobierno","durante","cuando","donde", "como","amigos"};

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

void sort_string(string* str, int n)
{
    int *arr = new int [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = str[i][0] - '0';
    }
    arr = merge_sort(arr,n);
    for (int i = 0; i < n; i++)
    {
        str[i] = arr[i] + '0';
    }
}

void asignar_randoms(string *arr, const int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = palabra[rand() % 30];

    }
}

int main()
{
    int n;
    cin >> n;
    string* cadenas = new string[n]; 

    cout << "La cadena original es: " << cadena << endl;
    sort_strings(cadena,n);
    cout << "La cadena ordenada lexicograficamente es: " << cadena << endl;

    return 0;
}
