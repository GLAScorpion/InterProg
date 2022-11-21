#ifndef ISBN_h
#define ISBN_h
#include <iostream>
class ISBN{
public:
//COSTRUTTORI	
	//senza argomenti
    ISBN():x{'0'},digit{0,0,0}{}
    //con interi e char
    ISBN(int n1, int n2 , int n3, char c);
   	//con stringa
    explicit ISBN(const std::string& s);
    
//MEMEBER FUNCTION
	//ritorna le prime tre cifre numeriche dell'isbn
    int getDigit0()const{return digit[0];}
    //ritorna le tre cifre numeriche centrali dell'isbn
    int getDigit1()const{return digit[1];}
    //ritorna le ultime tre cifre numeriche dell'isbn
    int getDigit2()const{return digit[2];}
    //ritorna la componente alfanumerica dell'isbn
    char getFinal()const{return x;}

private:
    int digit[3];
    char x;
};
//OPERATORI
	//operatore di ugualianza
	bool operator==(const ISBN& a, const ISBN& b);
	//operatore "diverso da"
	bool operator!=(const ISBN& a, const ISBN& b);
	//insertion operator
	std::ostream& operator<<(std::ostream& os, const ISBN& a);
#endif