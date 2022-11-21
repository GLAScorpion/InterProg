#include <iostream>
#include "date.h"

int main(){
	//test della classe date
	std::cout<<"Test della classe Date:"<<std::endl;
	
	//test del costruttore di default
	std::cout<<std::endl<<"Test del costruttore di default:"<<std::endl;
	Date date1 {};
	std::cout<<date1<<std::endl;
	
	//test del costruttore
	std::cout<<std::endl<<"Test del costruttore:"<<std::endl;
	Date date2 {1,2,1890};
	std::cout<<date2<<std::endl;
	
	//test delle member function get_month, get_day, get_year
	std::cout<<std::endl<<"Test delle member function get_month, get_day, get_year(con la data 25-9-2001):"<<std::endl;
	Date date3 {25,9,2001};
	std::cout<<"Il giorno: "<<date3.get_day()<<", il mese: "<<date3.get_month()<<", l'anno: "<<date3.get_year()<<std::endl;
	
	//test della member function IsValid
	std::cout<<std::endl<<"Test della member function IsValid(con la data 34-1-1970)"<<std::endl;

	try{
		Date date4{34,1,1970};
	}
    catch(const std::invalid_argument& i){
		std::cout<<"La creazione della data lancia un eccezione: "<<i.what()<<std::endl;
	}

	std::cout<<"Il controllo tramite IsValid resituisce che: ";
	if(!IsValid(34,1,1970)){
		std::cout<<"La data non e' valida"<<std::endl;
	}else{
		std::cout<<"La data e' valida"<<std::endl;
	}

	//test della member function IsBisestile
	std::cout<<std::endl<<"Test della member function IsBisestile (con la data 1-2-2020):"<<std::endl;
	Date date5 {1,2,2020};
	if(IsBisestile(date5.get_year())){
		std::cout<<"L'anno e' bisestile"<<std::endl;
	}else{
		std::cout<<"L'anno non e' bisestile"<<std::endl;
	}

    std::cout<<std::endl<<"Test della member function IsBisestile (con la data 1-2-2019):"<<std::endl;
	Date date6 {1,2,2019};
	if(IsBisestile(date6.get_year())){
		std::cout<<"L'anno e' bisestile"<<std::endl;
	}else{
		std::cout<<"L'anno non e' bisestile"<<std::endl;
	}

    return 0;
}