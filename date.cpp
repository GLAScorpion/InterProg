#include <iostream>
#include "date.h"
#include <vector>

//CONSTRUCTORS

    Date::Date(int d, int m, int y)
        : month_{Month(1)},day_{0},year_{0}
    {
        if(!IsValid(m,d,y)) throw std::invalid_argument("Invalid date");
        month_ = Month(m);
        year_ = y;
        day_ = d;
    }

//MEMBER FUNCTIONS
    
    void Date::set_day(int val){
        if(!IsValid(static_cast<int>(month_),val,year_)) throw std::invalid_argument("Invalid date");
        day_ = val;
    }
    
    void Date::set_year(int val){
        if(!IsValid(static_cast<int>(month_),day_,val)) throw std::invalid_argument("Invalid date");
        year_ = val;
    }
    
    void Date::set_month(Month val){
        if(!IsValid(static_cast<int>(val),day_,year_)) throw std::invalid_argument("Invalid date");
        month_ = val;
    }

    void Date::set_month(int val){
        if(!IsValid(val,day_,year_)) throw std::invalid_argument("Invalid date");
        month_ = Month(val);
    }
    
//HELPER FUNCTIONS

    bool IsValid(int m, int d, int y){
        if((m<1)or(m>12)or(d<0)or(y<1)or(y>2022)) return false;
        //febbraio
        if(m == 2){
            if(IsBisestile(y)){
                if(d>29) return false;
            }else{
                if(d>28) return false;
            }
        } 
        //mesi con 30 giorni   
        if((m==4 or m==6 or m==9 or m==11)and(d>30)) return false;
        //mesi con 31 giorni
        if(d>31) return false;
        return true;
    }

    bool IsBisestile(int y){
        if(y%4 == 0){
            if(y%100 == 0){
                if(y%400 == 0){
                    return true;
                }
            }else{
                return true;
            }
        }
        return false;
    }

    std::ostream& operator<<(std::ostream& os, Month m){
        return os<<kMonthName[static_cast<int>(m)-1];
    }
    
    std::ostream& operator<<(std::ostream& os, Date d){
        return os<<d.get_day()<<" "<<d.get_month()<<" "<<d.get_year();
    }