#include <iostream>
#include "book.h"

//CONSTRUCTORS

        Book::Book()
        :auth_name_{""}, auth_surname_{""}, title_{""}, isbn_code_(), copyright_date_(), available_{true}
        {}

        Book::Book(std::string name, std::string surname,std::string book_title,ISBN code , Date copyright, bool disponibile)
        :auth_name_{name}, auth_surname_{surname}, title_{book_title}, isbn_code_{code}, copyright_date_{copyright}, available_{disponibile}
        {}

        Book::Book(std::string name, std::string surname,std::string book_title, const std::string& code , Date copyright, bool disponibile)
        :auth_name_{name}, auth_surname_{surname}, title_{book_title}, isbn_code_{code}, copyright_date_{copyright}, available_{disponibile}
        {}

//MEMBER FUNCTIONS

        void Book::Borrow(){
                if(!available_) throw std::logic_error("Book is not available_");
                available_ = false;
        }

        void Book::GiveBack(){
                if(available_) throw std::logic_error("Book is already available_");
                available_ = true;
        }

//OPERATORS

        bool Book::operator==(const Book& b) const
        {
                return isbn_code_ == b.isbn_code_;
        }

        bool Book::operator!=(const Book& b) const
        {
                return isbn_code_ != b.isbn_code_;
        }
//HELPER FUNCTIONS

        std::ostream& operator<<(std::ostream& os, const Book& b ){
                os<<"Book name: "<<b.get_title()<<"\nAuth name: "<<b.get_name()<<" "<<b.get_surname()<<"\nISBN code: "<<b.get_isbn();
                if(b.get_date().get_year()!=0)os<<"\nCopyright date: "<<b.get_date(); //stampare una data "non definita" non ha senso
                return os;
        }