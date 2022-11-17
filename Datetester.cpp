#include <iostream>
#include "Date.h"
using namespace std;
int main(){
    Date x = Date(12,10,1950);
    cout<<x.get_month()<<endl;
    Date b;
    cout << &x << " " <<&b<<endl;
    cout << x << " " <<b<<endl;
    Date a{29,2,2000};
    cout<<a<<endl;
    
}