#include <iostream>
using namespace std;
float sumafi(float a, int b){
    return a + b;
}
double restalf(float a, double b){
    return a - b;
}
long multiplicaid(int a, long b){
    return a * b;
}
float funcion(float(*op)(float, int), float a, int b){
    return op(a, b);
}
double funcion(double(*op)(float, double), float a, double b){
    return op(a, b);
}
long funcion(long(*op)(int, long), int a, long b){
    return op(a, b);
}
int main(){
    float f1{3.434};
    int i1{23};
    long l1{1474838};
    double d1{3.1415};
    cout << funcion(sumafi, f1, i1)<<endl;
    cout << funcion(restalf, f1, d1) << endl;
    cout << funcion(multiplicaid, i1, l1) << endl;
    return 0;
}