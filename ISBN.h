#ifndef ISBN_h
#define ISBN_h
#include <iostream>
class ISBN{
public:
//costruttori
    ISBN(int n1 = 0, int n2 =0, int n3 =0, char c ='0' );
    ISBN(std::string s= "000-000-000-0");
private:
    int n1;
    int n2;
    int n3;
    char x;
};
#endif