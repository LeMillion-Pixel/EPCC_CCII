#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Ficha{
private:
    char letra;
    int val;
public:
    Ficha(char letra, int val){
        this->letra = letra;
        this->val = val;
    };
    ~Ficha(){};
    void imprimir(){
        cout<<"Ficha  "<<'"' <<letra<<'"'<<"\n Valor: "<<val<<endl;
    };
};
class Scrabble{
private:
    vector <Ficha> fichasJ;
    string name{""};
public:
    Scrabble(string n) { name = n; };
    ~Scrabble(){};
    void llenar(){
        string name{""};
        cout << "Ingrese su nombre:\n >";
        getline(cin, name);
        darFichas();
    };
    void darFichas(){
        for (int i = 0; i < 7;i++){
            
            char c='a' + rand() % 26;
            int num = rand() % 5 + 1;
            Ficha f(c, num);
            fichasJ.push_back(f);
        }
    };
    void print(){
        cout << name << " tiene: \n";
        for (auto p = fichasJ.begin(); p != fichasJ.end();p++){
            p->imprimir();
        }
        cout << endl;
    };
};
int main(){
    srand(time(NULL));

    Scrabble j1("Alejandro");
    Scrabble j2("Edu");
    Scrabble j3("Juana");
    Scrabble j4("Chacha");
    j1.darFichas();
    j1.print();
    j2.darFichas();
    j2.print();
    j3.darFichas();
    j3.print();
    j4.darFichas();
    j4.print();
}