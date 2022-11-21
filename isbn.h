#ifndef isbn_h
#define isbn_h
#include <iostream>
class ISBN{
public:
//CONSTRUCTORS
    ISBN():x{'0'},digit{0,0,0}{}
    ISBN(int n1, int n2 , int n3, char c);
    explicit ISBN(const std::string& s);
//MEMBER FUNCTION
    int get_digit0()const{return digit[0];}
    int get_digit1()const{return digit[1];}
    int get_digit2()const{return digit[2];}
    char get_final()const{return x;}
//OPERATORS
    bool operator==(const ISBN& b) const;
    bool operator!=(const ISBN& b) const;
private:
    int digit[3];
    char x;
};
//HELPER FUNCTIONS
std::ostream& operator<<(std::ostream& os, const ISBN& a);
//non potendo usare math.h servivano alcune funzioni per formattare e acquisire i valori
int Pow(int b, int exp); //calcola b^exp
int Log10(int val); //calcola log in base dieci di val, per trovare decine, centinaia e unità
int ToInt(const char& c); //conversione di un char a int usando i valori ASCII
#endif