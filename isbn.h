#ifndef isbn_h
#define isbn_h
#include <iostream>
class ISBN{
public:
//CONSTRUCTORS
    //imposta 000-000-000-0 come isbn di default
    ISBN():x_{'0'},digit_{0,0,0}{}
    //costruttore con i seguenti controlli: lunghezza stringa, trattini, numeri e carattere alfanumerico nelle giuste posizioni
    //lancia eccezione se uno dei controlli sopra descritti fallisce
    explicit ISBN(const std::string& s);
    //costruttore che controlla validità dei numeri e del carattere
    //lancia eccezione se tali controlli falliscono
    ISBN(int n1, int n2 , int n3, char c);
    
//MEMBER FUNCTION
    int get_digit0()const{return digit_[0];}
    int get_digit1()const{return digit_[1];}
    int get_digit2()const{return digit_[2];}
    char get_final()const{return x_;}
//OPERATORS
    bool operator==(const ISBN& b) const;
    bool operator!=(const ISBN& b) const;
private:
    int digit_[3];
    char x_;
};
//HELPER FUNCTIONS
    std::ostream& operator<<(std::ostream& os, const ISBN& a);

    //non potendo usare math.h servivano alcune funzioni per formattare e acquisire i valori
        //calcola b^exp
        int Pow(int b, int exp);
        //calcola log in base dieci di val, per trovare decine, centinaia e unità
        int Log10(int val); 
        //conversione di un char a int usando i valori ASCII
        int ToInt(const char& c); 
        
#endif