#ifndef book_h
#define book_h
#include <iostream>
#include "date.h"
#include "isbn.h"
class Book{
public:
//constructors

    //costruttore di default: imposta stringe vuote e invoca costruttori di default di isbn e date
    Book();

    //crea un Book con tre stringhe nome e cognome autore, titolo, un oggetto isbn. è possibile specificare la data di copyright e se è available
    Book(std::string name, std::string surname,std::string book_title, ISBN code , Date copyright = Date(), bool disponibile = true);

    //come il costruttore precedente, ma con l'isbn in formato stringa
    Book(std::string name, std::string surname,std::string book_title, const std::string& code , Date copyright = Date(), bool disponibile = true);

//member functions

    ISBN get_isbn() const {return isbn_code_;}
    Date get_date() const {return copyright_date_;}
    bool is_available() const {return available_;}
    std::string get_name() const {return auth_name_;}
    std::string get_surname() const {return auth_surname_;}
    std::string get_title() const {return title_;}

    //mette a false available_, se lo e' gia' lancia un'eccezione
    void Borrow(); //prestito del libro

    //mette a true available_, se lo e' gia' lancia un'eccezione
    void GiveBack(); //restituzione del libro

//operators

    bool operator==(const Book& b) const;
    bool operator!=(const Book& b) const;

private:
    std::string auth_name_ ;
    std::string auth_surname_ ;
    std::string title_;
    ISBN isbn_code_;
    Date copyright_date_;
    bool available_;
};

//HELPER FUNCTIONS

std::ostream& operator<<(std::ostream& os, const Book& b );

#endif