#include <vector>
#include <iostream>

using namespace std;

bool areFactors(int n, vector <int> factors){
    for (auto iter = factors.begin(); iter != factors.end();iter++){
        if (n%*iter!=0)
            return false;
    }
    return true;
}

int main(){
    int n;
    int a;
    vector<int> factors;
    cout << "Enter the number\n >";
    cin >> n;
    cout << "Enter the factors\n >";
    while (cin>>a)
        factors.push_back(a);
    if (areFactors(n, factors)==true)
        cout<<"True";
    else
        cout << "False";
}

