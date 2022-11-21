#ifndef date_h
#define date_h
#include <iostream>
#include <vector>
//associa il numero al nome del mese
enum class Month{
        jan = 1, feb , mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

//associa il numero del mese alla sua stringa 
const std::vector<std::string> kMonthName {"January","February","March","April","May","June","July","August","September","October","November","December"};

class Date{
    public:
    //CONSTRUCTORS

        //l'anno zero è l'anno che deifinisce una data "non specificata" per il copyright
        Date():day_{0},month_{Month(1)},year_{0}{}

        //costruttore che imposta i valori di day, month e year con verifica della validità
        Date(int d, int m, int y);

    //MEMBER FUNCTIONS

        int get_day() const{return day_;}
        Month get_month() const{return month_;}
        int get_year() const{return year_;}
        void set_day(int val);
        void set_year(int val);
        void set_month(Month val);
        void set_month(int val);
        
    private:
        Month month_;
        int day_;
        int year_;
};

//HELPER FUNCTIONS

    //verifica la validità della data, controllando se il mese è compreso tra 1 e 12 e se il giorno appartiene o meno al mese
    bool IsValid(int m, int d, int y);  

    //controllo mese bisestile secondo calendario gregoriano
    bool IsBisestile(int y);

    std::ostream& operator<<(std::ostream& os, Month m);
    std::ostream& operator<<(std::ostream& os, Date d);
    
    #endif