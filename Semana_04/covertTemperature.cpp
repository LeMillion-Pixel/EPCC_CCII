#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    float c, f{0.0};
    cout << "Enter a temperature in Celsius: \n";
    cin >> c;
    f= ((c*9)/5)+32;
    cout << fixed << setprecision(1) << c << " C = " << fixed << setprecision(1) << f<<" F\n";
}