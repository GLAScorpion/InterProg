#ifndef ISBN_h
#define ISBN_h
#include <iostream>
class ISBN{
public:
//costruttori
    ISBN():x{'0'},digit{0,0,0}{}
    explicit ISBN(int n1, int n2 , int n3, char c);
    explicit ISBN(const std::string& s);
    int get_digit0()const{return digit[0];}
    int get_digit1()const{return digit[1];}
    int get_digit2()const{return digit[2];}
    char get_final()const{return x;}
private:
    int digit[3];
    char x;
};
bool operator==(ISBN a, ISBN b);
bool operator!=(ISBN a , ISBN b);
std::ostream& operator<<(std::ostream& os, ISBN a);
#endif