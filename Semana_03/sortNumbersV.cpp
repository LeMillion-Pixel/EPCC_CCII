#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
//Ordenamiento BubbleSort
void bubble_sort(vector <int> lista){
    for (int i = 0; i < lista.size();i++){
        for (int j = 0; j <(lista.size()-i-1) ;j++){
            if (lista.at(j)>lista.at(j+1)){
                int temp = lista.at(j);
                lista.at(j) = lista.at(j + 1);
                lista.at(j + 1)= temp;
            }
        }
    }
}

int main(){
    vector <int> lista;
    int a;
    cout << "Ingrese la cantidad de terminos";
    //Ingreso de caracteres 
    cin >> a;
   
    //Llenar un array con los datos del usuario
    for (int i = 0; i < a; i++){
        int x;
        cout << i + 1 << ") ";
        cin >> x;
        lista.at(i) = x;
    }
    //Ordenar la lista con un void
    bubble_sort(lista);
    //Imprimir  
    for (int numero:lista)
        cout << numero << 'n';
}