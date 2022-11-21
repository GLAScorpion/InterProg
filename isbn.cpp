#include <iostream>
#include "isbn.h"
const int kIsbnLength = 13; //lunghezza della stringa
const int kMaxN = 999;
//CONSTRUCTORS
ISBN::ISBN(const std::string& s)
:digit{0,0,0}
{
    if(s.length()!=kIsbnLength) throw std::invalid_argument("Invalid ISBN format");
    for(int i = 0; i<kIsbnLength-1;i++){
        if((i+1)%4==0){
            if(s[i]!='-')throw std::invalid_argument("Invalid ISBN format");
        }else{
            if(isdigit(s[i])==0)throw std::invalid_argument("Invalid ISBN format");
            digit[i/4]+=(ToInt(s[i]))*Pow(10,(kIsbnLength-i-3)%4);
        }
    }
    if(isalnum(s[kIsbnLength-1]==0))throw std::invalid_argument("Invalid ISBN format");
    x = toupper(s[kIsbnLength-1]);//abbiamo deciso che minuscole e maiuscole non sono codici differenti
}
ISBN::ISBN(int n1, int n2, int n3, char c )
:digit{0,0,0}
{
    if(n1<0 or n2<0 or n3<0 or n1>kMaxN or n2>kMaxN or n3>kMaxN or isalnum(c)==0){
        throw std::invalid_argument("Invalid ISBN format");
    }
    digit[0] = n1;
    digit[1] = n2;
    digit[2] = n3;
    x = toupper(c);
}
//OPERATORS
bool ISBN::operator==(const ISBN& b) const
{
    if(digit[0]!=b.digit[0])return false;
    if(digit[1]!=b.digit[1])return false;
    if(digit[2]!=b.digit[2])return false;
    if(x!=b.x)return false;
    return true;
}
bool ISBN::operator!=(const ISBN& b) const
{
    return !(*this==b);
}
//HELPER FUNCTIONS
std::ostream& operator<<(std::ostream& os, const ISBN& a){
    for(int i = 0;i <3-Log10(a.get_digit0())-1;i++){
        os<<"0";
    }
    os<<a.get_digit0()<<"-";
    for(int i = 0;i<3-Log10(a.get_digit1())-1;i++){
        os<<"0";
    }
    os<<a.get_digit1()<<"-";
    for(int i = 0;i<3-Log10(a.get_digit2())-1;i++){
        os<<"0";
    }
    os<<a.get_digit2()<<"-";
    return os<<a.get_final();
}
int Pow(int b, int exp){ 
    int res = 1;
    for(int i = 0; i<exp;i++){
        res = res*b;
    }
    return res;
}
int Log10(int val){ 
    int res = 0;
    while(val >= 10){
        val = val /10;
        res ++;
    }
    return res;
}
int ToInt(const char& c){ 
    return static_cast<int>(c)-static_cast<int>('0');
}