#ifndef Date_h
#define Date_h
#include <iostream>
#include <vector>

//enumerazione dei mesi
enum class Month{
        jan = 1, feb , mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date{
public:
//COSTRUTTORI
	//costruttore senza argomenti
    Date() : day{0},month{Month(1)},year{0}{}
    //costruttore default con interi
    Date(int d, int m, int y);
    
//MEMBER FUNCTION
	//ritorna il giorno
    int getDay() const {return day;}
    //ritorna il mese
	Month getMonth() const {return month;}
	//ritorna l'anno
    int getYear() const {return year;}
    
private:
    Month month;
    int day;
    int year;
};

//HELPER FUNCTION (in maniera tale da poter effettuare il controllo su una data anche senza un istanza di Date)
	//ritorna true se la data m-d-y è valida 
	bool isValid(int m, int d, int y);  
	//ritorna true se l'anno è bisestile
	bool isBisestile(int y);
	
//OPERATORI
	//insertion operator per month
	std::ostream& operator<<(std::ostream& os, Month m);
	//insertion operator per Date
	std::ostream& operator<<(std::ostream& os, Date d);
#endif