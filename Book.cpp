#include <iostream>
#include "Book.h"
std::ostream& operator<<(std::ostream& os, const Book& b ){
        os<<"Book name: "<<b.get_title()<<"\nAuth name: "<<b.get_name()<<" "<<b.get_surname()<<"\nISBN code: "<<b.get_isbn();
        if(b.get_date().get_year()!=0)os<<"\nCopyright date: "<<b.get_date();
        return os;
}
Book::Book()
:auth_name{""}, auth_surname{""}, title{""}, isbn_code(), copyright_date(), available{true}
{}
Book::Book(std::string name, std::string surname,std::string book_title,ISBN code , Date copyright, bool disponibile)
:auth_name{name}, auth_surname{surname}, title{book_title}, isbn_code{code}, copyright_date{copyright}, available{disponibile}
{
}
Book::Book(std::string name, std::string surname,std::string book_title, const std::string& code , Date copyright, bool disponibile)
:auth_name{name}, auth_surname{surname}, title{book_title}, isbn_code{code}, copyright_date{copyright}, available{disponibile}
{
}
void Book::borrow(){
        if(!available) throw std::invalid_argument("Book is not available");
        available = false;
}
void Book::give_back(){
        if(available) throw std::invalid_argument("Book is already available");
        available = true;
}
bool Book::operator==(const Book& b) const
{
        return isbn_code == b.isbn_code;
}
bool Book::operator!=(const Book& b) const
{
        return isbn_code != b.isbn_code;
}