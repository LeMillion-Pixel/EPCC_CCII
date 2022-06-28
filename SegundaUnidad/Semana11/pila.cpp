#include <iostream>
#include <ctime>

using namespace std;
template <typename T>
class Nodo {
public:
    T data;
    Nodo* next;
};
template <typename T>
class Pila{
public:
    Pila(int tam) {
        head = NULL;
        this->tam = tam;
    };
    ~Pila(){
    };
    T top();
    void pop();
    void push(T);
    void clear();
    int size();
    bool full();
    bool empty();
    void print();
private:
    Nodo <T>* head;
    int tam;
};
//Devuelve ultimo elemento
template <typename T>
T Pila<T>::top(){
    if(empty()==true)
        return;
    Nodo<T> *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    return temp->data;
}
template <typename T>
void Pila<T>::pop(){
    if(head->next==NULL){
        head = NULL;
        cout << "Pila vacia\n";
        return;
    }
    Nodo<T> *temp = head;
    Nodo<T> *temp2;
    while (temp->next != NULL){
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = temp->next;
    delete temp;
}
template <typename T>
void Pila<T>::push(T val) {
    if (full()==true)
        return;
    Nodo <T>* NuevoN = new Nodo<T>();
    NuevoN->data = val;
    NuevoN->next = NULL;
    if (head == NULL) {
        head = NuevoN;
    }
    else {
        Nodo<T>* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = NuevoN; 
    }
}
//Falta definir
template <typename T>
void Pila<T>::clear(){
    if (empty()==true)
        return;
    else{
        while (empty()==false){
            pop();
        }
        return;
    }
}
template <typename T>
int Pila<T>::size(){
    int c = 0;
    if (head == NULL){
        return c;
    }
    else{
        c++;
        Nodo<T>* temp = head;
        while (temp->next != NULL) { 
            temp = temp->next;
            c++;
        }
        return c;
    }  
}
template <typename T>
bool Pila<T>::full(){
    if(size()==tam){
        return true;
    }
    return false;
}
template <typename T>
bool Pila<T>::empty(){
    if (head == NULL){
        return true;
    }
    return false;
}
template <typename T>
void Pila<T>::print() {
    if (head == NULL) {
        cout << "Pila vacia" << endl;
    }
    else {
        cout << "Pila -> ";
        Nodo<T>* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;

        }
        cout << "NULL \n";
    }
}

int main(){
    Pila <int> *PilaM = new Pila<int>(5);
    if(PilaM->empty()==true){
        cout << "Pila vacia\n";
    }
    PilaM->push(4);
    PilaM->push(6);
    PilaM->print();
    PilaM->push(-9);
    PilaM->push(23);
    PilaM->push(45);
    if(PilaM->full()==true){
        cout << "Pila llena\n";
    }
    PilaM->print();
    PilaM->pop();
    PilaM->print();
    PilaM->clear();
    if(PilaM->empty()==true){
        cout << "Pila vacia\n";
    }
    delete PilaM;
    system("pause");
    return 0;
}
