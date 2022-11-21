#include <iostream>
#include "ISBN.h"
using namespace std;
int main(){
	//TEST della classe isbn
	std::cout<<"Test della classe ISBN:"<<std::endl;	
	//test dell costruttore con stringa
	std::cout<<std::endl<<"Test del costruttore con stringa (con argomento \"999-344-432-s\"):"<<std::endl;
	ISBN a{"999-344-432-s"};
	cout<<a<<endl;

    //test del costruttore con interi e valore alfanumerico
    std::cout<<std::endl<<"Test del costruttore con interi e valore alfanumerico(con argomenti: 123, 123, 123, \'a\'):"<<std::endl;
    ISBN b {123,123,123,'a'};
    cout<<b<<endl;
    
    //test del costruttore senza argomenti(valori default: 000-000-000-0)
    std::cout<<std::endl<<"Test del costruttore senza argomenti(valori default: 000-000-000-0):"<<std::endl;
    ISBN c;
    cout<<c<<endl;
    
    //test del costruttore con interi a 1 o 2 cifre
    std::cout<<std::endl<<"Test del costruttore con interi a 1 o 2 cifre: "<<std::endl;
	ISBN d {3,2,55,'d'};
    cout<<d<<endl;
}