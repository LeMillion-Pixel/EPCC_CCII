#include <iostream>
#include <vector>

using namespace std;

template<size_t alto, size_t ancho, size_t largo>
void multiplicar(int (&x)[alto][ancho][largo],int n){
    //int a = sizeof(x) / sizeof(x[0]);// primera dimension
    //int b = sizeof(x[0]) / sizeof(x[0][0]);// segunda dimension
    //int c = sizeof(x[0][0]) / sizeof(x[0][0][0]); // tercera dimension
    int *d = &x[0][0][0];
    for (size_t i = 0; i<alto*ancho*largo;i++,d++)
        *d = *d * n;
}
template<size_t alto, size_t ancho, size_t largo>
void print(int (&x)[alto][ancho][largo]){
    int *d = &x[0][0][0];
    for (size_t i = 0; i<alto;i++){
        cout << "{";
        for (size_t j = 0; j<ancho;j++){
            cout << "[";
            for (size_t k = 0; k<largo;k++){
                cout << *d<<',';
                d++;
            }
            cout << "] ";}
        cout << "}\n";}
}
int main(){
    int x[3][4][2]={{{1,2},{4,5},{7,8},{1,2}},
                   {{10,11},{13,14},{16,17},{1,2}},
                   {{19,20},{22,23},{25,26},{1,2}}};
    cout << "--PRIMERA MATRIZ--\n";
    print(x);
    multiplicar(x, 4);
    cout << "\n\n--SEGUNDA MATRIZ--\n";
    print(x);
    system("pause");
    return 0;
}