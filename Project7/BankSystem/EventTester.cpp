#include "Event.h"
#include <iostream>
using namespace std;

int main() {
    // Create Event objects
    Event event1( 'A', 10, 5 );
    Event event2( 'D', 20, 3 );
    Event event3( 'C', 40, 77 );

    // Test getters
    cout << "Event 1: " << event1 << endl;
    cout << "Event 2: "<< event2 << endl;

    cin >> event3;

    cout << "New values for Event 3: " << event3 << endl;

    // Test comparison operators
    cout << "Comparing Event 1 and Event 3:" << endl;
    cout << "Event 1 < Event 3: " << ( event1 < event3 ? "True" : "False" ) << endl;
    cout << "Event 1 > Event 3: " << ( event1 > event3 ? "True" : "False" ) << endl;
    cout << "Event 1 == Event 3: " << ( event1 == event3 ? "True" : "False" ) << endl;
    cout << "Event 1 != Event 3: " << ( event1 != event3 ? "True" : "False" ) << endl;

    return 0;
}