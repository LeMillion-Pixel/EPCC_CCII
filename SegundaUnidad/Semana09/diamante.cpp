#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Diamante{
private:
    char b;
    string final;
    ostringstream o;

public:
    Diamante(char a){
        tolower(a);
        this -> b = a;
    };
    Diamante(){
        cout << "Enter a letter:\n >";
        char a;
        cin >> a;
        this->b = a;
    }
    void hacerD(){
        int pos = b-'A';
        int b1{0};
        for (int i = 0; i <=pos;i++){
            for (int j = pos-i; j > 0;j--){
                o << "*";
            }
            char p = 'A' + i;
            o << p;
            if(b1>0){
                for (int y = 0; y < (i * 2 - 1);y++)
                    o << "*";
                o << p;
            }
            else{
                b1++;
            }
            for (int j = pos-i; j > 0;j--){
                o << "*";
            }
        o << '\n';
        }
        string aux = o.str();
        int t = pos * 2 + 4;
        for (auto y = (aux.end()-t);y!=aux.begin();y--){
            o << *y;
        }
    }
    void mostrar(){
        final = o.str();
        cout << final;
    }
};
int main(){
    Diamante d1('D');
    d1.hacerD();
    d1.mostrar();
}
