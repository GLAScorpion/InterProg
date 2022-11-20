#ifndef book_h
#define book_h
#include <iostream>
#include "date.h"
#include "isbn.h"
class Book{
public:
//constructors
    Book();
    Book(std::string name, std::string surname,std::string book_title, ISBN code , Date copyright = Date(), bool disponibile = true);
    Book(std::string name, std::string surname,std::string book_title, const std::string& code , Date copyright = Date(), bool disponibile = true);
//member functions
    ISBN get_isbn() const {return isbn_code;}
    Date get_date() const {return copyright_date;}
    bool is_available() const {return available;}
    std::string get_name() const {return auth_name;}
    std::string get_surname() const {return auth_surname;}
    std::string get_title() const {return title;}
    //mette a false available, se lo e' gia' lancia un'eccezione
    void Borrow(); //prestito del libro
    //mette a true available, se lo e' gia' lancia un'eccezione
    void GiveBack(); //restituzione del libro
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
//HELPER FUNCTIONS
std::ostream& operator<<(std::ostream& os, const Book& b );
#endif