#ifndef Date_h
#define Date_h
#include <iostream>
#include <vector>
enum class Month{
        jan = 1, feb , mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

class Date{
    public:
    Date():day{0},month{Month(1)},year{0}{}
    Date(int d, int m, int y);
    int get_day() const{return day;}
    Month get_month() const{return month;}
    int get_year() const{return year;}
    private:
    bool is_valid(int m, int d, int y);
    bool is_bisestile(int y);
    Month month;
    int day;
    int year;
};
std::ostream& operator<<(std::ostream& os, Month m);
std::ostream& operator<<(std::ostream& os, Date d);
#endif