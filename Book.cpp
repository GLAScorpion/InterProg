#include <iostream>
#include "book.h"
//CONSTRUCTORS
Book::Book()
:auth_name{""}, auth_surname{""}, title{""}, isbn_code(), copyright_date(), available{true}
{}
Book::Book(std::string name, std::string surname,std::string book_title,ISBN code , Date copyright, bool disponibile)
:auth_name{name}, auth_surname{surname}, title{book_title}, isbn_code{code}, copyright_date{copyright}, available{disponibile}
{}
Book::Book(std::string name, std::string surname,std::string book_title, const std::string& code , Date copyright, bool disponibile)
:auth_name{name}, auth_surname{surname}, title{book_title}, isbn_code{code}, copyright_date{copyright}, available{disponibile}
{}
//MEMBER FUNCTIONS
void Book::Borrow(){
        if(!available) throw std::logic_error("Book is not available");
        available = false;
}
void Book::GiveBack(){
        if(available) throw std::logic_error("Book is already available");
        available = true;
}
//OPERATORS
bool Book::operator==(const Book& b) const
{
        return isbn_code == b.isbn_code;
}
bool Book::operator!=(const Book& b) const
{
        return isbn_code != b.isbn_code;
}
//HELPER FUNCTIONS
std::ostream& operator<<(std::ostream& os, const Book& b ){
        os<<"Book name: "<<b.get_title()<<"\nAuth name: "<<b.get_name()<<" "<<b.get_surname()<<"\nISBN code: "<<b.get_isbn();
        if(b.get_date().get_year()!=0)os<<"\nCopyright date: "<<b.get_date(); //stampare una data "non definita" non ha senso
        return os;
}