#ifndef date_h
#define date_h
#include <iostream>
#include <vector>
enum class Month{
        jan = 1, feb , mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
class Date{
    public:
    //CONSTRUCTORS
        //l'anno zero è l'anno che deifinisce una data "non specificata" per il copyright
        Date():day{0},month{Month(1)},year{0}{}
        Date(int d, int m, int y);
    //MEMBER FUNCTIONS
        int get_day() const{return day;}
        Month get_month() const{return month;}
        int get_year() const{return year;}
        void set_day(int val);
        void set_year(int val);
        void set_month(Month val);
        void set_month(int val);
    private:
        Month month;
        int day;
        int year;
};
//HELPER FUNCTIONS
//verifica la validità dei valori immessi per il formato data
bool IsValid(int m, int d, int y);  
//verifica dell'anno bisestile secondo il calendario gregoriano
bool IsBisestile(int y);
std::ostream& operator<<(std::ostream& os, Month m);
std::ostream& operator<<(std::ostream& os, Date d);
#endif