#include "linked_list/LinkedList.h"
#include <iostream>
#include <cmath>

using namespace std;
std::istream& operator>>(std::istream &is, LinkedList& cu){
    std::cout << "Cuantos valores ingresara?\n >";
    int a{0};
    if (not(is>>a)){
        is.setstate(std::ios::failbit);
        return is;
    }
    else{
        for (int i = 0; i < a;i++){
            int b{0};
            cout << "# " << i + 1 << " > ";
            cin >> b;
            if(!cin){
                cout << "No es un entero" << endl;
                cin.clear();
                cin.ignore();
            }
            else{
                cu.insert(b);
            }
        }
        return is;
    }
}
int main(){
    LinkedList l1(4);
    cin >> l1;
    cout << l1;
}