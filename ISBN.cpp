#include <iostream>
#include "ISBN.h"
const int ISBN_length = 13;
const int max_n = 999;
int pow(int b, int exp){
    int res = 1;
    for(int i = 0; i<exp;i++){
        res = res*b;
    }
    return res;
}
int log10(int val){
    int res = 0;
    while(val >= 10){
        val = val /10;
        res ++;
    }
    return res;
}
int to_int(const char& c){
    return static_cast<int>(c)-48;
}
bool is_alphanum(const char& c){// creato perchè isalnum() non funzionava correttamente
    int conv = static_cast<int>(c);
    if((conv >47 and conv <58)or(conv>64 and conv<91)or(conv>96 and conv<123)) return true;
    return false;
}
ISBN::ISBN(const std::string& s)
:digit{0,0,0}
{
    if(s.length()!=ISBN_length) throw std::invalid_argument("Invalid ISBN format");
    for(int i = 0; i<ISBN_length-1;i++){
        if((i+1)%4==0){
            if(s[i]!='-')throw std::invalid_argument("Invalid ISBN format");
        }else{
            if(isdigit(s[i])!=1)throw std::invalid_argument("Invalid ISBN format");
            digit[i/4]+=(to_int(s[i]))*pow(10,(ISBN_length-i-3)%4);
        }
    }
    if(!is_alphanum(s[ISBN_length-1]))throw std::invalid_argument("Invalid ISBN format");
    x = toupper(s[ISBN_length-1]);//abbiamo deciso che minuscole e maiuscole non sono codici differenti
}
ISBN::ISBN(int n1, int n2, int n3, char c )
:digit{0,0,0}
{
    if(n1<0 or n2<0 or n3<0 or n1>max_n or n2>max_n or n3>max_n or !is_alphanum(c)){
        throw std::invalid_argument("Invalid ISBN format");
    }
    digit[0] = n1;
    digit[1] = n2;
    digit[2] = n3;
    x = toupper(c);
}
std::ostream& operator<<(std::ostream& os, ISBN a){
    for(int i = 0;i <3-log10(a.get_digit0())-1;i++){
        os<<"0";
    }
    os<<a.get_digit0()<<"-";
    for(int i = 0;i<3-log10(a.get_digit1())-1;i++){
        os<<"0";
    }
    os<<a.get_digit1()<<"-";
    for(int i = 0;i<3-log10(a.get_digit2())-1;i++){
        os<<"0";
    }
    os<<a.get_digit2()<<"-";
    return os<<a.get_final();
}
bool operator==(ISBN a, ISBN b){
    if(a.get_digit0()!=b.get_digit0())return false;
    if(a.get_digit1()!=b.get_digit1())return false;
    if(a.get_digit2()!=b.get_digit2())return false;
    if(a.get_final()!=b.get_final())return false;
    return true;
}
bool operator!=(ISBN a, ISBN b){
    return !(a==b);
}