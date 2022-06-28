#include <iostream>

using namespace std;

class tiempo{
public:
    tiempo(int h, int m, int s){
        if(s>=60){
            m += s / 60;
            s %= 60;
        }
        this->s = s;
        if(m>=60){
            h += m / 60;
            m %= 60;
        }
        this->m = m;
        if(h>=24){
            h %= 24;
        }
        this->h = h;
    };
    int seg() const{ return s; };
    int min() const{ return m; };
    int hor() const{ return h; };
    
    friend ostream &operator<<(ostream &, const tiempo &);

private:
    int h{0}, m{0}, s{0};
};
inline tiempo operator+(const tiempo&t1, const tiempo&t2){
    return tiempo(t1.hor() + t2.hor(), t1.min() + t2.min(), t1.seg() + t2.seg());
}
inline tiempo operator-(const tiempo&t1, const tiempo&t2){
    return tiempo(t1.hor() - t2.hor(), t1.min() - t2.min(), t1.seg() - t2.seg());
}
inline bool operator==(const tiempo&t1, const tiempo&t2){
    if(t1.hor()!=t2.hor())
        return false;
    else if(t1.min()!=t2.min())
        return false;
    else if(t1.seg()!=t2.seg())
        return false;
    else
        return true;
}
inline bool operator!=(const tiempo&t1, const tiempo&t2){
    if(t1==t2)
        return false;
    else
        return true;
}
inline bool operator<(const tiempo&t1, const tiempo&t2){
    if(t1.hor()>=t2.hor())
        return false;
    else if(t1.min()>=t2.min())
        return false;
    else if(t1.seg()>=t2.seg())
        return false;
    else
        return true;
}
inline bool operator>(const tiempo&t1, const tiempo&t2){
    if(t1<t2)
        return false;
    else
        return true;
}
inline bool operator<=(const tiempo&t1, const tiempo&t2){
    if(t1<t2 || t1==t2)
        return true;
    else
        return false;
}
inline bool operator>=(const tiempo&t1, const tiempo&t2){
    if(t1>t2 || t1==t2)
        return true;
    else
        return false;
}
ostream& operator<<(ostream&os, const tiempo&tp){
    if(tp.h>12){
        os << tp.h - 12 << " : " << tp.m << " : " << tp.s<<" p.m.";
        return os;
    }
    os << tp.h << " : " << tp.m << " : " << tp.s<<" a.m.";
    return os;
}
int main(){
    tiempo t1(13, 45, 12);
    cout << "Tiempo 1 = " << t1<<endl;
    tiempo t2(25, 60, 25);
    cout << "Tiempo 2 = " << t2<<endl;
    if(t1<=t2){
        cout << "Tiempo 1 es menor a Tiempo 2\n";
    }
    else
        cout << "Tiempo 1 es menor a Tiempo 2\n";
    tiempo t3 = t1 + t2;
    cout << "Tiempor 3 es igual a " << t3;
    return 0;
}
