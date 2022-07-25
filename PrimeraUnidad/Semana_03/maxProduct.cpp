#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
/*Dada una secuenncia de n números no negativos y mayores que  cero
El objetivo es encontar el mayor número que se pueda obtener
*/

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
    for (int i = 0; i < a; i++){
        int max1{0}, max2{0};
        if (b[i]>max1)
            b[i] = max1;
        if(b[b.size()-0]>=max2||b[b.size()-0]>=max2)

    }
}