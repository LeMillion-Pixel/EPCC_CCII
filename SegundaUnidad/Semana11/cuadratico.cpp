#include <iostream>
#include <cmath>

using namespace std;

class cuadratica{
private:
    int a{0};
    int b{0};
    int c{0};
public:
    cuadratica(){};
    cuadratica(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    };
    cuadratica(const cuadratica& c1){
        this->a = c1.a;
        this->b = c1.b;
        this->c = c1.c;
    };
    void asignar(const int a1=0, const int b1=0, const int c1=0){
        a = a1;
        b = b1;
        c = c1;
    };
    void set_A(int a){
        this->a = a;
    };
    void set_B(int b){
        this->b = b;
    };
    void set_C(int c){
        this->c = c;
    };
    int resultado(int n){
        int resultado = (a * pow(n, 2)) + (b * n) + c;
        return resultado;
    };
    void print(){
        cout << a << ", " << b << ", " << c << endl;
    };
    friend ostream &operator<<(ostream &os, cuadratica &cu){
        os << "f(x) = " << cu.a << "x^2 + " << cu.b << "x + " << cu.c;
        return os;
    };
};
istream& operator>>(istream& is, cuadratica& cu) {
    cout << "Ingrese los valores de la funcion: a,b,c:\n > ";
    int a{0}, b{0}, c{0};
    char sep{'\0'}, sep2{'\0'};
    if (not (is >> a >> sep))
        is.setstate(std::ios::failbit);
    else if (sep != ',') {
        is.unget();
        cu.asignar(a);
    } if (not (is >> b >> sep2))
        is.setstate(std::ios::failbit);
    else if (sep2 != ',') {
        is.unget();
        cu.asignar(a,b);
    }
    else if(is>>c)
        cu.asignar(a,b,c);
    else
        is.setstate(std::ios::failbit);
    return is;
}
int main(){
    cuadratica c1(4, 3, 2);
    cout << c1<<"\nf(2) = "<<c1.resultado(2)<<endl;
    cuadratica c2(c1);
    cout << c2<<"\nf(2) = "<<c1.resultado(2)<<endl;
    cuadratica c3;
    cin >> c3;
    cout << c3<<"\nf(3) = "<<c3.resultado(3)<<endl;
    return 0;
}
