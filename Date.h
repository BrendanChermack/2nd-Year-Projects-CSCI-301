/*
Description of the problem to solve:  database containing person’s name and birthday. Is is
 able to enter, remove, modify, or search from the database. The names are unique.
The program is able to save the data in a file for use later.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on December 8, Friday
Instructor: Professor Meichsner
*/
#ifndef DateH
#define DateH
#include <iostream>
using namespace std;
class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(): month(), day(), year() { };//default constructor
    /**
     * Constructor for the Date class.
     *
     * @param month The month of the date.
     * @param day The day of the date.
     * @param year The year of the date.
     * @pre None
     * @post A Date object is created with the provided month, day, and year.
     */
    Date( int month, int day, int year ) {
        this->month = month;
        this->day = day;
        this->year = year;
    }
    /**
     * Retrieves the day of the date.
     *
     * @return An integer representing the day.
     */
    int getDay() {
        return day;
    }
    /**
     * Retrieves the month of the date.
     *
     * @return An integer representing the month.
     */
    int getMonth() {
        return month;
    }
    /**
     * Retrieves the year of the date.
     *
     * @return An integer representing the year.
     */
    int getYear() {
        return year;
    }
    /**
     * Sets the day of the date.
     *
     * @param day An integer representing the new day of the date.
     */
    void setDay( int day ) {
        this->day = day;
    }
    /**
 * Sets the month of the date.
 *
 * @param month An integer representing the new month of the date.
 */
    void setMonth( int month ) {
        this->month = month;
    }
    /**
 * Sets the year of the date.
 *
 * @param year An integer representing the new year of the date.
 */
    void setYear( int year ) {
        this->year = year;
    }
    /**
     * Overloads the input stream operator for reading data into a Date object.
     *
     * @param ins The input stream.
     * @param target The Date object to read data into.
     * @return The input stream.
     */
    friend istream& operator >>( istream& ins, Date& target ) {
        ins >> target.month
            >> target.day
            >> target.year;
        return ins;
    }
    /**
     * Overloads the output stream operator for writing data from a Date object.
     *
     * @param outs The output stream.
     * @param target The Date object to write data from.
     * @return The output stream.
     */
    friend ostream& operator <<( ostream& outs, Date& target ) {
        outs << target.month << " " << target.day << " " << target.year;
        return outs;
    }
};
#endif