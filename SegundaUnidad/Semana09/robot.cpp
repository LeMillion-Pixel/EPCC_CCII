#include <iostream>
#include <random>
#include <chrono>
#include <vector>

using namespace std;
class Robot{
private:
    string name;
public: 

    Robot(){
        name = "";
    };
    ~Robot(){};
    string dar_name(){    
        for (int i = 0; i < 2; i++){
            char c = 'A' + rand() % 26;
            name += c;
        }
        for (int i = 0; i < 3;i++){
            int n=rand()%10;
            name += to_string(n);
        }
        return name;
    };
    string give_name(){
        return name;
    }
    void encender(){
        name = dar_name();
    };
    void resetar(){
        name = "";
        name = dar_name();
    };
};

int main(){
    srand(time(NULL));
    vector<string> fabrica;
    Robot r;
    r.encender();
    for (int i = 0; i < 100;i++){
        cout << r.give_name()<<" "<<i<<endl;
        for(auto p=fabrica.begin();p!=fabrica.end();p++){
            if(*p==r.give_name()){
                while(*p==r.give_name()){
                    r.resetar();
                }
                fabrica.push_back(r.give_name());
            }
        }
        fabrica.push_back(r.give_name());
        r.resetar();
    }
    cout <<endl<<fabrica.at(0);
    int c = 0;
    for(auto p=fabrica.begin();p!=fabrica.end();p++){
        cout << "Robot #" << c + 1 << " -> ";
        cout << *p;
        cout << '\n';
        c++;
    }
    return 0;
}