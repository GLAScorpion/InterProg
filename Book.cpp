#include <iostream>
#include "Book.h"
std::ostream& operator<<(std::ostream& os, const Book& b ){
        os<<"Book name: "<<b.get_title()<<", Auth name: "<<b.get_name()<<" "<<b.get_surname()<<", ISBN code: "<<b.get_isbn()<<", Copyright date: "<<b.get_date()<<", Available: "<<std::boolalpha<<b.isavailable();
        return os;
}
Book::Book()
:auth_name{""},auth_surname{""},title{""},isbn_code(),copyright_date(),available{true}
{}
Book::Book(std::string name, std::string surname,std::string book_title,const std::string& code , Date copyright = Date(), bool disponibile = true)
:auth_name{name},auth_surname{surname},title{book_title},copyright_date{copyright},available{disponibile}
{
   isbn_code = ISBN(code);
}