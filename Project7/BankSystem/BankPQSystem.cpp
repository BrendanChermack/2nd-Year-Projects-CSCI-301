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
#include "Event.h"
#include "SL_PriorityQueue.h"
#include "LinkedQueue.h"
#include <iostream>
#include <fstream>

using namespace std;
/*** handles arrival events
    * @param bankLine normal que DSA
    * @param eventLog prio que DSA
    * @param event event object
    * @param tellerStatus bool for if the teller can be seen (didnt want to use global variables)
    * @param currentTime used for avg wait time (didnt want to use global variables)
    * @param totalWaitTime used for avg wait time (didnt want to use global variables)
    * @pre None
    * @post adds to the bank queue or add to the evenlog if the bank is empty and teller can be seen*/
void arrivalEvent( LinkedQueue<Event>& bankLine, SL_PriorityQueue<Event>& eventLog, Event event, bool& tellerStatus, int& currentTime, float& totalWaitTime ) {
    eventLog.remove();//removes the event to be handled
    cout << "Processing an arrival event at time: " << event.getTime() << endl;
    if ( bankLine.isEmpty() && tellerStatus ) {
        int depart = currentTime + event.getLength();//calulates the departure time
        Event dEvent( 'D', depart, 0 );//makes a new obj
        eventLog.add( dEvent );//adds the event to the prio queue with the right order based on the depart time
        tellerStatus = false;//teller cant be seen
        totalWaitTime += currentTime;//needed for avg wait time
    }
    else {
        bankLine.enqueue( event );//adds the event to the bankLine
    }
}
/*** handles departure events
    * @param bankLine normal que DSA
    * @param eventLog prio que DSA
    * @param event event object
    * @param tellerStatus bool for if the teller can be seen (didnt want to use global variables)
    * @param currentTime used for avg wait time (didnt want to use global variables)
    * @param totalWaitTime used for avg wait time (didnt want to use global variables)
    * @pre None
    * @post if the bank queue is empty it makes the event a departure, removes from bankline then puts it in prio queue */
void departEvent( LinkedQueue<Event>& bankLine, SL_PriorityQueue<Event>& eventLog, Event event, bool& tellerStatus, int& currentTime, float& totalWaitTime ) {
    eventLog.remove();//removes the event to be handled
    cout << "Processing an departure event at time: " << event.getTime() << endl;
    if ( !bankLine.isEmpty() ) {//if the bank line has events in it
        Event customer = bankLine.peekFront();//gets the front event
        bankLine.dequeue();//removes the event
        int depart = currentTime + customer.getLength();//calc departure time
        totalWaitTime += currentTime;//needed for avg wait time
        customer.setTime( depart );//sets the depart time from the customer event
        customer.setType( 'D' );//sets it to departure type
        /*alternatively it could be done like this
        Event departureEvent('D', depart, customer.getLength());
        faster to overwrite the customer objec
        */
        eventLog.add( customer );//add to the prio
    }
    else {
        tellerStatus = true;//teller can be seen
    }
}
int main() {
    SL_PriorityQueue<Event> eventLog;//prio queue
    LinkedQueue<Event> bankLine;//normal queue
    bool tellerStatus = true;
    int tempTime, tempLength, total, currentTime;
    int totalArriveTime = 0;
    float avgWaitTime;
    float totalWaitTime;
    fstream infile;//defining infile
    infile.open( "iFile.txt" );//opens the text file we will read from
    while ( infile >> tempTime >> tempLength ) {//loops through the whole file grabbing 2 at once
        Event tempE( 'A', tempTime, tempLength );//creates a temp objc
        eventLog.add( tempE );//adds the objects to the prio queue
        total++;//needed for total events/customers served also to avoid another param/global variable
        totalArriveTime += tempE.getTime();//does what the variable name says also to avoid another param/global variable
    }
    infile.close();//closes the file
    while ( !eventLog.isEmpty() ) {//goes until the queue is empty
        Event curr = eventLog.peek();//current event
        currentTime = curr.getTime();//current time
        if ( curr.getType() == 'A' ) {//if the event is an arrival
            arrivalEvent( bankLine, eventLog, curr, tellerStatus, currentTime, totalWaitTime );//call arrival event
        }
        else if ( curr.getType() == 'D' ) {//if the event is an depart
            departEvent( bankLine, eventLog, curr, tellerStatus, currentTime, totalWaitTime );//calls the needed function
        }
    }
    //displays the final stats
    cout << "\nFinal Stats: \n" << "Total number of customers processed : " << total << endl;
    avgWaitTime = ( totalWaitTime - totalArriveTime ) / total;
    cout << "Average amount of time spent waiting: " << avgWaitTime << endl;
    return 0;
}