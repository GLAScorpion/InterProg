#ifndef Book_h
#define Book_h
#include <iostream>
#include "Date.h"
#include "ISBN.h"
class Book{
public:
//constructors
    Book();
    Book(std::string name, std::string surname,std::string book_title,ISBN code , Date copyright, bool available = true);
    //copy constructor
    Book(const Book& b);
    //move constructor
    Book(Book&& b);
//operators
    //copy assignment
    Book& operator=(const Book& b);
    //move assignment
    Book& operator=(Book&& b);
//member functions
    ISBN get_isbn() const;
    Date get_date() const;
    bool isavailable() const;
    std::string get_name() const;
    std::string get_surname() const;
    std::string get_title() const;
    //mette a false available, se lo e' gia' lancia un'eccezione
    void borrow();
    //mette a true available, se lo e' gia' lancia un'eccezione
    void give_back();
private:
    std::string auth_name = "";
    std::string auth_surname = "";
    std::string title = "";
    ISBN isbn_code;
    Date copyright_date;
    bool available;
};
bool operator==(const Book& a,const Book& b){return b.get_isbn() == a.get_isbn(); }
bool operator!=(const Book& a,const Book& b){return b.get_isbn() != a.get_isbn();}
std::ostream& operator<<(std::ostream& os, const Book& b );
#endif