#include <iostream>
#include "Book.h"
#include "ISBN.h"
#include "Date.h"


//COSTRUTTORI
	//costruttore senza argomenti
	Book::Book()
	:authName{""}, authSurname{""}, title{""}, isbnCode(), copyrightDate(), available{true}
	{}
	//costruttore default con classe ISBN 
	Book::Book(std::string name, std::string surname,std::string bookTitle,ISBN code , Date copyright, bool disponibile)
	:authName{name}, authSurname{surname}, title{bookTitle}, isbnCode{code}, copyrightDate{copyright}, available{disponibile}
	{
	}
	//costruttore default con stringa per ISBN
	Book::Book(std::string name, std::string surname,std::string bookTitle, const std::string& code , Date copyright, bool disponibile)
	:authName{name}, authSurname{surname}, title{bookTitle}, isbnCode{code}, copyrightDate{copyright}, available{disponibile}
	{
	}
	
//MEMBER FUNCTIONS
	//mette a false available, se lo e' gia' lancia un'eccezione
	void Book::borrow(){
	        if(!available) throw std::invalid_argument("Book is not available");
	        available = false;
	}
	//mette a true available, se lo e' gia' lancia un'eccezione
	void Book::giveBack(){
	        if(available) throw std::invalid_argument("Book is already available");
	        available = true;
	}
	
//OPERATORI
	//operatore di ugualianza
	bool operator==(const Book& a, const Book& b){
	        return a.getIsbn() == b.getIsbn();
	}
	//operatore "diverso da"
	bool operator!=(const Book& a, const Book& b){
	        return a.getIsbn() != b.getIsbn();
	}
	//insertion operator
	std::ostream& operator<<(std::ostream& os, const Book& b){
        os<<"Book name: "<<b.getTitle()<<"\nAuth name: "<<b.getName()<<" "<<b.getSurname()<<"\nISBN code: "<<b.getIsbn();
        if(b.getDate().getYear()!=0)os<<"\nCopyright date: "<<b.getDate();
        return os;
	}