#include <iostream>
#include "Book.h"
using namespace std;
int main(){
    Book a {"amogus" ,"sus","when the impostor is sus","999-344-432-s",Date(1,1,1970)};
    std::vector<Book> shelf(10);
    Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");
    Book trimone{"Big J","The Holy One","Once upon a time... The Bible","999-344-432-S"};
    cout<<a<<endl<<endl<<my_favourite_book<<endl<<endl<<trimone<<endl;
    cout<<boolalpha<<(a==trimone)<<" "<<boolalpha<<(a==my_favourite_book)<<endl;
}