#ifndef Book_h
#define Book_h
#include <iostream>
#include "Date.h"
#include "ISBN.h"
class Book{
public:
//constructors
    Book();
    Book(std::string name, std::string surname,std::string book_title, ISBN code , Date copyright = Date(), bool disponibile = true);
    Book(std::string name, std::string surname,std::string book_title, const std::string& code , Date copyright = Date(), bool disponibile = true);
//member functions
    ISBN get_isbn() const {return isbn_code;}
    Date get_date() const {return copyright_date;}
    bool isavailable() const {return available;}
    std::string get_name() const {return auth_name;}
    std::string get_surname() const {return auth_surname;}
    std::string get_title() const {return title;}
    //mette a false available, se lo e' gia' lancia un'eccezione
    void borrow();
    //mette a true available, se lo e' gia' lancia un'eccezione
    void give_back();
//operators
    bool operator==(const Book& b) const;
    bool operator!=(const Book& b) const;
private:
    std::string auth_name ;
    std::string auth_surname ;
    std::string title;
    ISBN isbn_code;
    Date copyright_date;
    bool available;
};
std::ostream& operator<<(std::ostream& os, const Book& b );
#endif