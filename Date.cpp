#include <iostream>
#include "Date.h"
#include <vector>
Date::Date(int d, int m, int y)
: month{Month(1)},day{0},year{0}
{
    if(!is_valid(m,d,y)) throw std::invalid_argument("Invalid date");
    month = Month(m);
    year = y;
    day = d;
}
bool Date::is_valid(int m, int d, int y){
    if((m<0)or(m>12)or(d<0)or(y<0)or(y>2022)) return false;
    if(m == 2){
        if(is_bisestile(y)){
            if(d>29) return false;
        }else{
            if(d>28) return false;
        }
    }    
    if((m==4 or m==6 or m==9 or m==11)and(d>30)) return false;
    if(d>31) return false;
    return true;
}
bool Date::is_bisestile(int y){
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
std::vector<std::string> month_name = {"january","february","march","april","may","june","july","august","september","october","november","december"};
std::ostream& operator<<(std::ostream& os, Month m){
    return os<<month_name[static_cast<int>(m)-1];
}
std::ostream& operator<<(std::ostream& os, Date d){
    return os<<d.get_day()<<" "<<d.get_month()<<" "<<d.get_year();
}