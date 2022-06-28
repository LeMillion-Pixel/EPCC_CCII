
#include <iostream>
int mcd(int a, int b){
  if (b == 0)
    return a;
  return mcd(b, a % b);
}
int mcm(int a, int b){
    return (a / mcd(a, b)) * b;
}
class Racional{
private:
    int x{0};
    int y{1};
public:
    Racional(){};
    Racional(int x, int y){
    this->x = x;
    this->y = y;
    };
    void set_X(int x){
        this->x = x;
    };
    void set_Y(int y){
        this->y = y;
    };
    int get_X() const{ return x; };
    int get_Y() const{ return y; };
    int Mcd(){
        return mcd(x, y);
    }
    Racional operator+(int num) const {
        return Racional(x + (y * num), y);

    };
    Racional operator-(int num) const {
        return Racional(x - (y * num), y);
    };
    Racional operator*(int num) const {
        return Racional(x * num, y);
    };
    Racional operator/(int num) const {
        return Racional(x, y*num);
    };
    Racional operator+=(int num){
        x += y * num;
    };
    Racional operator-=(int num){
        x -= y * num;
    };
    Racional operator*=(int num){
        x *= num;
    };
    Racional operator/=(int num){
        y /= num;
    };
    double aprox(){
        double a = x * 1.0 / y;
        return a;
    };

    friend std::ostream &operator<<(std::ostream &, const Racional &);
};
void simp(Racional *r1){
    int m = r1->Mcd();
    r1->set_X(r1->get_X() / m);
    r1->set_Y(r1->get_Y() / m);
}
double num(const Racional& c) {
    return c.get_X();
}
double deno(const Racional& c) {
    return c.get_Y();
}
inline Racional operator+( const Racional& c1, const Racional& c2) {
    int y = mcm(deno(c1), deno(c2));
    int x = ((y / deno(c1)) * num(c1)) + ((y / deno(c2)) * num(c2));
    Racional r1(x, y);
    simp(&r1);
    return r1;
}
inline Racional operator-( const Racional& c1, const Racional& c2) {
    int y = mcm(deno(c1), deno(c2));
    int x = ((y / deno(c1)) * num(c1)) - ((y / deno(c2)) * num(c2));
    Racional r1(x, y);
    simp(&r1);
    return r1;
}
inline Racional operator*( const Racional& c1, const Racional& c2) {
    Racional r1((num(c1)*num(c2)),(deno(c1)*deno(c2)));
    simp(&r1);
    return r1;
}
inline Racional operator/( const Racional& c1, const Racional& c2) {
    Racional r1((num(c1)*deno(c2)),(deno(c1)*num(c2)));
    simp(&r1);
    return r1;
}

std::ostream& operator<<(std::ostream& os, const Racional& r1)
{
    os << r1.x << "/" << r1.y;
    return os;
}

std::istream& operator>>(std::istream& is, Racional& c) {
    std::cout << "Ingrese un Racional en el formato: numerador/denominador:\n > ";
    int nu{0}, de{1};
    char sep{'\0'};
    if (not (is >> nu >> sep))
        is.setstate(std::ios::failbit);
    else if (sep != '/') {
        is.unget();
        c.set_X(nu);
    } else if (is >> de){
        while (de == 0){
            std::cout << "Ingrese un denomindador valido\n > ";
            is >> de;
        }
        c.set_X(nu);
        c.set_Y(de);
    }
    else
        is.setstate(std::ios::failbit);
    return is;
}
int main(){
    Racional r1(4,8);
    simp(&r1);
    std::cout << r1<<"-"<<r1.aprox();
    return 0;
}