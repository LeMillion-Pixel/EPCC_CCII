#include <vector>
#include <iostream>
using namespace std;

class Robot{
private:
    int x{0};
    int y{0};
    char dire;
    int pos{0};
    vector <char> dir {'N', 'O', 'S', 'E'};
public:
    Robot(){
        x = rand() % 10 + 1;
        y = rand() % 10 + 1;
        pos = rand() % 4;
        dire = dir.at(pos);
    };
    Robot(int x, int y, char dire){
        this -> x = x;
        this-> y = y;
        this->dire = dire;
        if(dire=='N')
            pos = 0;
        if(dire=='S')
            pos = 2;
        if(dire=='O')
            pos = 1;
        if(dire=='E')
            pos = 3;
    };
    void ordenes(string direc){
        for (auto p = direc.begin(); p != direc.end();p++){
            if(*p=='A'){
                if(dire=='N'){
                    y++;
                }
                if(dire=='S'){
                    y--;
                }
                if(dire=='O'){
                    x++;
                }
                if(dire=='E'){
                    x--;
                }
   
            }
            if(*p=='D'){
                pos++;
                if(pos>=0)
                    pos=pos%4;
                else{
                    pos = pos % 4;
                    pos = pos+4;
                }
                cout << pos << endl;
                dire = dir.at(pos);
            }if (*p == 'I'){
                pos--;
                if(pos>=0)
                    pos=pos%4;
                else{
                    pos = pos % 4;
                    pos = pos+4;
                }
                dire = dir.at(pos);
            }
        }
    };
    void mostrar(){
        cout << "El robot esta en la (" << x << ", " << y << ") mirando al ";
        if(dire=='N')
            cout << "norte\n";
        if(dire=='S')
            cout << "sur\n";
        if(dire=='O')
            cout << "oeste\n";
        if(dire=='E')
            cout << "este\n";
    };
};

int main(){
    Robot r1(7, 3, 'N');
    r1.ordenes("DAAIAI");
    r1.mostrar();
    return 0;
}
