#include <iostream>
#include <cmath>

using namespace std;
int main(){
    cout << "I'm thinking of a number between 1 and 100 (including both).\nCan you guess what it is?\nType a number: ";
    int num;
    cin >> num;
    int random {rand() % 100 + 1};
    if (num==random)
        cout << "You guessed.";
    else
    {
        cout << "Your guess is: " << num << "\nThe numer I was thinking is: " << random<<"\nYou were off by: "<<abs(num-random);
    }
}