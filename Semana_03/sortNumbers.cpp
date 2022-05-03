#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
//Ordenamiento BubbleSort
void bubble_sort(int a, int b[]){
    for (int i = 0; i < a;i++){
        for (int j = 0; j <(a-i-1) ;j++){
            if (b[j]>b[j+1]){
                int temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}

int main(){
    int a{0};
    cout << "Ingrese la cantidad de terminos";
    //Ingreso de caracteres 
    cin >> a;
    int b[a];
    //Llenar un array con los datos del usuario
    for (int i = 0; i < a; i++){
        cin >> b[i];
    }
    //Ordenar la lista con un void
    bubble_sort(a, b);
    //Imprimir  
    cout << b[a - 1] * b[a - 2];
}