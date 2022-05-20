#include <vector>
#include "map"
#include <iostream>
#include <math.h>

using namespace std;

void fill(int hasta, map <int, bool> &primo)
{
    for (int i = 2; i <=hasta;  i++){
        primo.insert(pair<int, bool>(i, true));
        
    }
}
void sieve(int num, map <int,bool> &primo){
    int i = 0;
    auto iter = primo.begin();
    while (i!=num)
    { 
        if (iter->second==true){
            auto aux = iter;
            aux++;
            while ((aux)!=primo.end()){
                if (aux->first%iter->first==0)
                    aux->second = false;
                aux++;
            }
            iter++;
            i++;
        }
        else
            iter++;
    }
       
}

void imprimir(map<int, bool> primo)
{
    cout << "NUMBER\tBOOL VALUE\n";
    for (auto iter = primo.begin(); iter != primo.end();iter++)
        cout << iter->first << '\t' << iter->second<< '\n';
    cout << '\n';
}

int main()
{
    int hasta;
    cout << "Enter the number: \n>";
    cin >> hasta;
    map<int, bool> primo;
    int a = (int)(ceil(sqrt(hasta)));
    fill(hasta, primo);
    sieve(a, primo);
    imprimir(primo);
}