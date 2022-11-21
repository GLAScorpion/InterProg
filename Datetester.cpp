#include <iostream>
#include "Date.h"

int main(){
	//test della classe date
	std::cout<<"Test della classe Date:"<<std::endl;
	
	//test del costruttore senza argomenti
	std::cout<<std::endl<<"test del costruttore senza argomenti:"<<std::endl;
	Date date1 {};
	std::cout<<date1<<std::endl;
	
	//test del costruttore di default
	std::cout<<std::endl<<"Test del costruttore di default:"<<std::endl;
	Date date2 {1,2,1890};
	std::cout<<date2<<std::endl;
	
	//test delle Memeber function getMonth, getDay, getYear
	std::cout<<std::endl<<"Test delle Memeber function getMonth, getDay, getYear(con la data 1-1-1970):"<<std::endl;
	Date date3 {1,1,1970};
	std::cout<<"Il giorno: "<<date3.getDay()<<", il mese: "<<date3.getMonth()<<", l'anno: "<<date3.getYear()<<std::endl;
	
	//test della member functio isValid
	std::cout<<std::endl<<"Test della member function isValid(con la data 34-1-1970)"<<std::endl;
	try{
		Date date4{34,1,1970};
	}catch(const std::invalid_argument& i){
		std::cout<<"La creazione della data lancia un eccezione: "<<i.what()<<std::endl;
	}
	std::cout<<"Il controllo tramite isValid resituisce che: ";
	if(!isValid(34,1,1970)){
		std::cout<<"la data non e\' valida"<<std::endl;
	}else{
		std::cout<<"la data e\' valida"<<std::endl;
	}
	//test della member function isBisestile
	std::cout<<std::endl<<"test della member function isBisestile(con la data 1-2-1640):"<<std::endl;
	Date date5 {1,2,1640};
	if(isBisestile(date5.getYear())){
		std::cout<<"La data e\' bisestile"<<std::endl;
	}else{
		std::cout<<"La data non e\' bisestile"<<std::endl;
	}
	/*
    Date x = Date(12,10,1950);
    cout<<x.get_month()<<endl;
    Date b;
    cout << &x << " " <<&b<<endl;
    cout << x << " " <<b<<endl;
    Date a{29,2,2000};
    cout<<a<<endl;
    */
    return 0;
}