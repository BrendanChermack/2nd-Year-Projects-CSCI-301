/*
Description of the problem to solve: This program is a bank simulation, a priority queue tracks
customer arrivals and departures based on a text file listing their arrival and
transaction times. The program's goal is to list arrival and departures, count the total number of
customers and calculate their average waiting time. This simulation processes events
in the order they occur, as indicated by the arrival times.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on Nov 17, Friday
Instructor: Professor Meichsner
*/
#ifndef EventH
#define EventH
#include <iostream>//needed for overloading
using namespace std;
class Event {
private:
    char type;
    int time;
    int length;//transaction length
public:

    Event() { }//default constructor
    /*** Constructor;
    * @param type arrival or departure
    * @param time time of transaction
    * @param length transaction length
    * @pre None
    * @post creates the event obj*/
    Event( char type, int time, int length ) {
        this->type = type;
        this->time = time;
        this->length = length;
    }
    /*** sets type to a new value
    * @param type arrival or departure
    * @pre None
    * @post sets the type for an obj*/
    void setType( char type ) {
        this->type = type;
    }
    /*** sets time to a new value
    * @param time arrival time
    * @pre None
    * @post sets the time for an obj*/
    void setTime( int time ) {
        this->time = time;
    }
    /*** sets length to a new value
    * @param length trans time
    * @pre None
    * @post sets the length for an obj*/
    void setLength( int length ) {
        this->length = length;
    }
    /*** gets the type
    * @post returns the type*/
    char getType() {
        return type;
    }
    /*** gets the time
    * @post returns the time*/
    int getTime() {
        return time;
    }
    /*** gets the length
    * @post returns the length*/
    int getLength() {
        return length;
    }
    /*** cin overload
    * @param in istream
    * @param inEvent event object
    * @pre None
    * @post allows the use of cin for this object*/
    friend istream& operator >> ( istream& in, Event& inEvent ) {
        in >> inEvent.type >> inEvent.time >> inEvent.length;
        return in;
    }
    /*** out overload
    * @param out ostream
    * @param outEvent event object
    * @pre None
    * @post displays the objects vars to the console*/
    friend ostream& operator << ( ostream& out, Event outEvent ) {
        out << outEvent.type << " " << outEvent.time << " " << outEvent.length;
        return out;
    }
};
//Nonmember :)
/*** greater than overload operator
    * @param e1 event object
    * @param e2 event object
    * @pre None
    * @post makes the lower time the higher priority needed for insertSorted*/
bool operator >( Event e1, Event e2 ) {
    if ( e1.getTime() < e2.getTime() ) {
        return true;
    }
    return false;
}
/*** less than overload operator
    * @param e1 event object
    * @param e2 event object
    * @pre None
    * @post makes the lower time the higher priority*/
bool operator <( Event e1, Event e2 ) {
    if ( e1.getTime() > e2.getTime() ) {
        return true;
    }
    return false;
}
/*** == operator overloaded
    * @param e1 event object
    * @param e2 event object
    * @pre None
    * @post sees if 2 objects times are the same*/
bool operator ==( Event e1, Event e2 ) {
    if ( e1.getTime() == e2.getTime() ) {
        return true;
    }
    return false;
}
/*** != operator overloaded
    * @param e1 event object
    * @param e2 event object
    * @pre None
    * @post sees if 2 objects times are not the same*/
bool operator != ( Event e1, Event e2 ) {
    if ( e1.getTime() != e2.getTime() ) {
        return true;
    }
    return false;
}
#endif