#include <iostream>
#include "book.h"
#include "isbn.h"
#include "date.h"

int main(){
	//TEST della class Book
	std::cout<<"Test della classe Book:"<<std::endl;
	
	//test del costruttore senza argomenti
	std::cout<<std::endl<<"Test del costruttore senza argomenti: "<<std::endl;
	Book empty{};
	std::cout<<empty<<std::endl;
	
	//test del costruttore default con classe ISBN
	std::cout<<std::endl<<"Test del costruttore di default con isbn: "<<std::endl;
	ISBN isbn1 {"123-123-123-a"};
	Book isbnBook {"Charles", "Dickens","Le avventure di Oliver Twist",isbn1};
	std::cout<<isbnBook<<std::endl;
	
	//test del costruttore default con stringa per ISBN
	std::cout<<std::endl<<"Test del costruttore di default con stringa per isbn: "<<std::endl;
	Date date1 {22,3,1865};
	Book strBook {"Fedor", "Dostoevskij","Ricordi dal sottosuolo","123-007-124-a",date1};
	std::cout<<strBook<<std::endl;
	
	//test dei memeber function borrow, give_back, isavailable, get_name, get_surname, get_title
	std::cout<<std::endl<<"Test di: member function borrow, give_back, isavailable, get_name, get_surname, get_title, get_date:"<<std::endl;
	strBook.Borrow();
	if(!strBook.is_available()){
		std::cout<<"The book written by: "<<strBook.get_name()<<" "<<strBook.get_surname()<<", named: \""<<strBook.get_title();
		std::cout<<"\", with copyright date: "<<strBook.get_date()<<", is not available!"<<std::endl;
		strBook.GiveBack();
		if(strBook.is_available()){
			std::cout<<"I gave back the book, so it is now available again!"<<std::endl;
		}
	}

	//test di default 
    std::cout<<std::endl<<"Test di default della classe Book:"<<std::endl;
    std::vector<Book> shelf(10);
    Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non faro mai piu", "887-521-837-4");
    std::cout<<my_favourite_book<<std::endl;
	
    return 0;
}