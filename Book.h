#ifndef Book_h
#define Book_h
#include <iostream>
#include "Date.h"
#include "ISBN.h"

class Book{
public:
//COSTRUTTORI
	//costruttore senza argomenti
    Book();
    //costruttore default con classe ISBN
	Book(std::string name, std::string surname,std::string bookTitle, ISBN code , Date copyright = Date(), bool disponibile = true);
	//costruttore default con stringa per ISBN
	Book(std::string name, std::string surname,std::string bookTitle, const std::string& code , Date copyright = Date(), bool disponibile = true);
	
//MEMBER FUNCTIONS
	//ritorna l'isbn
    ISBN getIsbn() const {return isbnCode;}
    //ritorna la data del copyright
    Date getDate() const {return copyrightDate;}
    //ritorna un boolean per la disponibilità 
    bool isAvailable() const {return available;}
    //ritorna il nome dell'autore
    std::string getName() const {return authName;}
    //ritorna il cognome dell'autore
    std::string getSurname() const {return authSurname;}
    //ritorna il titolo del libro
    std::string getTitle() const {return title;}
    //mette a false available, se lo e' gia' lancia un'eccezione
    void borrow();
    //mette a true available, se lo e' gia' lancia un'eccezione
    void giveBack();
    
private:
    std::string authName;
    std::string authSurname;
    std::string title;
    ISBN isbnCode;
    Date copyrightDate;
    bool available;
};

//OPERATORI
	//operatore di ugualianza
    bool operator==(const Book& a, const Book& b);
    //operatore "diverso da"
    bool operator!=(const Book& a, const Book& b);
    //insertion operator
	std::ostream& operator<<(std::ostream& os, const Book& b );
	//insertion operator
	std::ostream& operator<<(std::ostream& os, const Book& b );
#endif