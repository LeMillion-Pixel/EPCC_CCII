#include <iostream>
#include <vector>

using namespace std;
template <typename T>
// No hallaba la forma de immplementarlo con arrays :/ array<T,?> no era reconocido el tamaño
T rango(vector<T> &a1, int inicio, int fin, const T val = 0)
{
    T a = val;
    for (int i = inicio-1; i <= fin-1;i++){
        a += a1.at(i);
    }
    return a;
}

//Posiciones de acuerdo al punto del usuario
int main(){
    vector<double> a1{4.5, 2.2, 45, 2.7, 4, 5.6};
    double n = rango<double>(a1, 2, 4,5);
    cout << n;
}