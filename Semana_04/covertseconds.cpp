#include <iostream>

using namespace std;
int main(){
    int sec, min, hours;
    cout << "Enter a number the seconds to convert:\n";
    cin >> sec;
    cout << "\n"<< sec << " seconds = ";
    if (sec<60)
        cout << sec << " seconds";
    hours = sec / 3600;
    sec %= 3600;
    min = sec / 60;
    sec %= 60;
    if (hours>=1)
        cout << hours << "hours, ";
    if (min>=1)
        cout << min << " minutes";
    if (min>=1 && sec>=1)
        cout << ", "<< sec << "seconds";
        
}