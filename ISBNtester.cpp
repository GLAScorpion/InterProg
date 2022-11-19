#include <iostream>
#include "ISBN.h"
using namespace std;
int main(){
    ISBN a{"999-344-432-s"};
    cout<<a<<endl;
    ISBN b {123,123,123,'a'};
    cout<<b<<endl;
    ISBN c;
    cout<<c<<endl;
    ISBN d {3,2,55,'d'};
    cout<<d<<endl;
}