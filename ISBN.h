#ifndef ISBN_h
#define ISBN_h
#include <iostream>
class ISBN{
public:
//costruttori
    ISBN();
    explicit ISBN(int n1, int n2 , int n3, char c);
    explicit ISBN(std::string s);
    bool operator==(ISBN b);
    bool operator!=(ISBN b);
    int get_digit0(){return digit[0];}
    int get_digit1(){return digit[1];}
    int get_digit2(){return digit[2];}
    char get_final(){return x;}
private:
    int digit[3];
    char x;
};
std::ostream& operator<<(std::ostream& os, ISBN a);
#endif