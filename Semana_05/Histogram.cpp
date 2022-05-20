#include <iostream>
#include <map>
#include <string>

using namespace std;

void Upper(string phrase){

}

int main(){
    string phrase;
    cout << "Entre the phrase to count words\n >";
    getline(cin, phrase);
    for (int i = 0; i < phrase.length();i++){
        phrase[i]=toupper(phrase[i]);
    }
    map<char, int> count;
    for (int i = 0; i < phrase.length();i++){
        char letter = phrase[i];
        if (count.find(letter)==count.end())
            count[letter] = 0;
        count[letter]++;
    }
    for (auto iter = count.begin(); iter != count.end();iter++){
        cout << iter->first << ":";
        for (int i = 0; i < iter->second;i++){
            cout << " * ";
        }
        cout << '\n';
    }
}