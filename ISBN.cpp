#include <iostream>
#include "ISBN.h"

const int ISBN_length = 13;
const int max_n = 999;

//HELPER FUNCTION
	//calcola la potenza b^exp
	int pow(int b, int exp){
	    int res = 1;
	    for(int i = 0; i<exp;i++){
	        res = res*b;
	    }
	    return res;
	}
	//calcola il logaritmo in base 10 del valore intero val
	int log10(int val){
	    int res = 0;
	    while(val >= 10){
	        val = val/10;
	        res++;
	    }
	    return res;
	}
	//esegue una conversion a intero del char c
	int toInt(const char& c){
	    return ((static_cast<int>(c))-48);
	}
	//controlla che il valore char c sia alfanumerico (creato perchè isalnum() non funzionava correttamente)
	bool isAlphanum(const char& c){
	    int conv = static_cast<int>(c);
	    if((conv > 47 and conv < 58) or (conv > 64 and conv < 91) or (conv > 96 and conv < 123)) return true;
	    return false;
	}
	
//COSTRUTTORI
	//con stringa (abbiamo deciso che minuscole e maiuscole non sono codici differenti)
	ISBN::ISBN(const std::string& s)
	:digit{0,0,0}
	{
	    if(s.length() != ISBN_length) throw std::invalid_argument("Invalid ISBN format");
	    
	    for(int i = 0; i < (ISBN_length-1); i++){
	        if((i+1)%4 == 0){
	            if(s[i] != '-') throw std::invalid_argument("Invalid ISBN format");
	        }else{
	            if(isdigit(s[i]) == 0) throw std::invalid_argument("Invalid ISBN format");
	            digit[i/4] += (toInt(s[i])) * pow(10, (ISBN_length-i-3)%4);
	        }
	    }
	    
	    if(isalnum(s[ISBN_length-1] == 0)) throw std::invalid_argument("Invalid ISBN format");
	    
	    x = toupper(s[ISBN_length-1]);
	}
	//con interi e char
	ISBN::ISBN(int n1, int n2, int n3, char c )
	:digit{0,0,0}
	{
	    if(n1 < 0 or n2 < 0 or n3 < 0 or n1 > max_n or n2 > max_n or n3 > max_n or !isAlphanum(c)){
	        throw std::invalid_argument("Invalid ISBN format");
	    }
	    digit[0] = n1;
	    digit[1] = n2;
	    digit[2] = n3;
	    x = toupper(c);
	}

//OPERATORI
	//insertion operator 
	std::ostream& operator<<(std::ostream& os, const ISBN& a){
	    for(int i = 0;i < (2-log10(a.getDigit0())); i++){
	        os<<"0";
	    }
	    
	    os<<a.getDigit0()<<"-";
	    for(int i = 0; i < (2-log10(a.getDigit1())); i++){
	        os<<"0";
	    }
	    
	    os<<a.getDigit1()<<"-";
	    for(int i = 0; i < (2-log10(a.getDigit2())); i++){
	        os<<"0";
	    }
	    
	    os<<a.getDigit2()<<"-";
	    return os<<a.getFinal();
	}
	//operatore di ugualianza
	bool operator==(const ISBN& a, const ISBN& b){
	    if(a.getDigit0()!= b.getDigit0()) return false;
	    if(a.getDigit1()!= b.getDigit1()) return false;
	    if(a.getDigit2()!= b.getDigit2()) return false;
	    if(a.getFinal() != b.getFinal()) return false;
	    return true;
	}
	//operatore "diverso da"
	bool operator!=(const ISBN& a, const ISBN& b){
	    if(a.getDigit0() == b.getDigit0()) return false;
	    if(a.getDigit1() == b.getDigit1()) return false;
	    if(a.getDigit2() == b.getDigit2()) return false;
	    if(a.getFinal() == b.getFinal()) return false;
	    return true;
	}

