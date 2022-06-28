#include <iostream>
#include <vector>

using namespace std;
typedef class Contador contador;
int cont{1};
class Contador{
private:
    int n {0};
    int val = cont;

public:
    Contador() { cont++; };
    Contador(int n){
        this->n = n;
        cont++;
    };
    ~Contador(){};
    int valor() { return n; };
    void operator+(int a){
        n += a;
    };
    void operator+=(int a){
        n += a;
    };
    void operator++(int a){
        n++;
    };
    friend ostream& operator<<(ostream& os, const Contador& dt);
};
 
ostream& operator<<(ostream& os, const Contador& dt)
{
    os << "Contador #" << dt.val<<"\nValor: "<<dt.n;
    return os;
}


int main(){
    Contador c1(5);
    contador c2;
    c1+ 5;
    cout << c1<<endl;
    c1 += 2;
    cout <<c1<<endl;
    c2++;
    cout <<c2<<endl;
    system("pause");
    return 0;
}
