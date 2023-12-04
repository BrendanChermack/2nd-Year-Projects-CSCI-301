#include <fstream>
#include <iostream>
#include "fraction.h"
int main(){
    int n1, d1, n2, d2;
    cout << "Enter the first fraction: numerator denominator(press enter after each number)\n";
    cin >> n1;
    cin >> d1;
    cout << "Enter the second fraction: numerator denominator(press enter after each number)\n";
    cin >> n2;
    cin >> d2;
    
    fraction f1(n1,d1), f2(n2,d2), f3;
    cout << "The two fractions entered are\n";
    cout << "f1 = "; 
    f1.display(cout); 

    cout << "\nf1's numerator is "<< f1.getNumerator();
    cout << "\nf1's denominator is " << f1.getDenominator();
    
    cout << "\nf2 = "; 
    f2.display(cout);

    f1.setNumerator(91);
    f1.setDenominator(100);
    cout << "\nf1's new fraction is ";
    f1.display(cout);
}