/*
Description of the problem to solve:  database containing person’s name and birthday. Is is
 able to enter, remove, modify, or search from the database. The names are unique.
The program is able to save the data in a file for use later.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on December 8, Friday
Instructor: Professor Meichsner
*/
#ifndef PeopleH
#define PeopleH
#include <string>
#include "Date.h"
#include <iostream>
using namespace std;
class People: public Date {
private:
    string name;
    Date birthday;
public:
    People(): name( "" ), birthday( Date() ) { }//default constructor
    /**
     * Constructor for People class.
     *
     * @param name The name of the person.
     * @param birthday The birthday of the person as a Date object.
     * @pre None
     * @post A People object is created with the provided name and birthday.
     */
    People( string name, Date birthday ) {
        this->name = name;
        this->birthday = birthday;
    }
    /**
     * Retrieves the name of the person.
     *
     * @return A string representing the person's name.
     */
    string getName() const {
        return name;
    }
    /**
     * Retrieves the birthday of the person.
     *
     * @return A Date object representing the person's birthday.
     */
    Date getBirthday() {
        return birthday;
    }
    /**
     * Sets the name of the person.
     *
     * @param name A string representing the new name of the person.
     */
    void setName( string name ) {
        this->name = name;
    }
    /**
     * Sets the birthday of the person.
     *
     * @param birthday A Date object representing the new birthday of the person.
     */
    void setBirthday( Date birthday ) {
        this->birthday = birthday;
    }
    /**
     * Overloads the input stream operator for reading data into a People object.
     *
     * @param ins The input stream.
     * @param target The People object to read data into.
     * @return The input stream.
     */
    friend istream& operator >>( istream& ins, People& target ) {
        ins >> target.name >> target.birthday;
        return ins;
    }
    /**
     * Overloads the output stream operator for writing data from a People object.
     *
     * @param outs The output stream.
     * @param target The People object to write data from.
     * @return The output stream.
     */
    friend ostream& operator <<( ostream& outs, People& target ) {
        outs << target.name << " " << target.birthday;
        return outs;
    }
};

//nonmember functions
/**
 * Overloads the greater than operator for comparing two People objects based on their names.
 *
 * @param p1 The first People object.
 * @param p2 The second People object.
 * @return True if the name of p1 is greater than the name of p2.
 */
bool operator >( const People& p1, const People& p2 ) {
    return p1.getName() > p2.getName();
}
/**
 * Overloads the less than operator for comparing two People objects based on their names.
 *
 * @param p1 The first People object.
 * @param p2 The second People object.
 * @return True if the name of p1 is less than the name of p2.
 */
bool operator <( const People& p1, const People& p2 ) {
    return p1.getName() < p2.getName();
}
/**
 * Overloads the equality operator for comparing two People objects based on their names.
 *
 * @param p1 The first People object.
 * @param p2 The second People object.
 * @return True if the names of p1 and p2 are equal.
 */
bool operator ==( const People& p1, const People& p2 ) {
    return p1.getName() == p2.getName();
}
#endif