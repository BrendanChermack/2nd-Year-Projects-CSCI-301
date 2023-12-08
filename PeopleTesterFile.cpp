/*
Description of the problem to solve:  database containing person’s name and birthday. Is is
 able to enter, remove, modify, or search from the database. The names are unique.
The program is able to save the data in a file for use later.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on December 8, Friday
Instructor: Professor Meichsner
*/
#include <iostream>
#include "People.h" // Assuming the classes are defined in People.h and Date.h
//#include "Date.h"

using namespace std;

int main() {
    // Test Date class
    // Date d1( 12, 25, 2022 ); // Create a Date object
    // cout << "Testing Date class" << endl;
    // cout << "Date: " << d1 << endl; // Should display "12 25 2022"
    // d1.setDay( 26 );
    // d1.setMonth( 12 ); // Note: setMonth and setYear methods are missing the parameter in your class definition
    // d1.setYear( 2023 );
    // cout << "Updated Date: " << d1 << endl; // Should display "12 26 2023"

    // Test People class
    People p1( "Aohn", Date(10,10,1999) ); // Create a People object
    cout << "\nTesting People class" << endl;
    cout << "Person: " << p1 << endl; // Should display "John Doe 12 26 2023"

    People p2( "damina", Date( 10, 21, 2001 ) );
    cout << "Default Person: " << p2 << endl; // Should display " 1 1 0" (default Date values)

    // Testing input operator
    cout << "\nEnter a name and date (mm dd yyyy): ";
    cin >> p2; // User inputs data
    cout << "Entered Person: " << p2 << endl;

    // Testing comparison operators
    cout << "\nTesting comparison operators" << endl;
    if ( p1 > p2 )
        cout << p1.getName() << " is greater than " << p2.getName() << endl;
    if ( p1 < p2 )
        cout << p1.getName() << " is less than " << p2.getName() << endl;
    if ( p1 == p2 )
        cout << p1.getName() << " is equal to " << p2.getName() << endl;

    return 0;
}
