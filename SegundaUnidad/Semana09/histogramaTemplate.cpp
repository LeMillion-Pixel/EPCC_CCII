#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
template <class P>
class histogram{
    private:
        vector<P> num;
    public:
        histogram(vector<P> h){
            num = h;
        };
        ~histogram(){};
        void add(P a) { num.push_back(a); };
        void printH(int n){
            vector<int> histo;
            sort(num.begin(),num.end());
            P a{((num.at(num.size()-1)-num.at(0))/n)+1};
            auto b = num.begin();
            P rang{num.at(0)};
            int pos{0};
            cout << endl;
            int c = 0;
            while(b!=num.end()){
                while(*b>=rang && *b<(rang+a)){
                    c++;
                    b++;
                }
                histo.push_back(c);
                rang += a;
                c = 0;
            }
            
            for (auto p = histo.begin(); p != histo.end();p++)
                cout << *p << " ";
            cout << '\n';
        }
};

int main(){
    vector<int> num = {10,2,9,7,5,6,1,8,8,4};
    histogram <int> h1 (num);
    h1.printH(5);
}