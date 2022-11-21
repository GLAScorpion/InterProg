#include <iostream>
#include "Date.h"
#include <vector>

const std::vector<std::string> month_name = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

//COSTRUTTORI
	//costruttore di default
	Date::Date(int d, int m, int y)
	: month{Month(1)}, day{0}, year{0}
	{
	    if(!isValid(m, d, y)) throw std::invalid_argument("Invalid date");
	    month = Month(m);
	    year = y;
	    day = d;
	}

//HELPER FUNCTION
	//ritorna true se la data m-d-y è valida altrimenti false
	bool isValid(int m, int d, int y){
	    if((m < 0) or (m > 12) or (d < 0) or (y < 0) or (y > 2022)) return false;
	    
	    if(m == 2){
	        if(isBisestile(y)){
	            if(d > 29) return false;
	        }else{
	            if(d > 28) return false;
	        }
	    }    
	    
	    if((m == 4 or m == 6 or m == 9 or m == 11) and (d > 30)) return false;
	    
	    if(d > 31) return false;
	    
	    return true;
	}
	//ritorna true se l'anno inserito è bisestile altrimenti false
	bool isBisestile(int y){
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

//OPERATORI
	//insertion operator per Month
	std::ostream& operator<<(std::ostream& os, Month m){
	    return os<<month_name[(static_cast<int>(m))-1];
	}
	//insertion operator per Date
	std::ostream& operator<<(std::ostream& os, Date d){
		if(d.getDay() == 0 and d.getMonth() == Month(1) and d.getYear() == 0) os<<"Default: ";
	    return os<<d.getDay()<<" "<<d.getMonth()<<" "<<d.getYear();
	}