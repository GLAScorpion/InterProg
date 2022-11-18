#include <iostream>
#include "ISBN.h"
using namespace std;
int main(){
    ISBN a{"434-767-577-b"};
    cout<<a<<endl;
    ISBN b {123,123,123,'a'};
    cout<<b<<endl;
    ISBN c;
    cout<<c<<endl;
}