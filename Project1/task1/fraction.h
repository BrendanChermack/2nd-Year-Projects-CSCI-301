/*
Description of the problem to solve: A header file for a fraction object with the following features:
numerator and denomitor, setting both of those to a new fraction, a default constructor, getter functions to
get the private variables and a display memember function.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on September 5, Tuesday
Instructor: Professor Meichsner
*/
#ifndef fractionH
#define fractionH
#include <iostream> //provides the ostream used in display
using namespace std;
class fraction {
private:
    //variables for the fractions numerator and denominator
    int numerator, denominator;
public:
    /*** Constructor;
    * @param numerator the numerator of the fraction
    * @param denominator the denominator of the fraction
    * @pre None
    * @post sets the numerator to 0 and denominator to 1*/
    fraction( int numerator = 0, int denominator = 1 );
    /*** Sets the numerator to a new value
    * @param numerator the numerator of the fraction
    * @pre None
    * @post the fraction this is called on set it to a new value*/
    void setNumerator( int numerator );
    /*** Sets the denominator to a new value
    * @param denominator the denominator of the fraction
    * @pre None
    * @post the fraction this is called on set it to a new value*/
    void setDenominator( int denominator );
    /*** returns the numerator of the fraction
    * @pre None
    * @post the numerator of the fraction is returned*/
    int getNumerator();
    /*** returns the denominator of the fraction
    * @pre None
    * @post the denominator of the fraction is returned*/
    int getDenominator();
    /*** Displays the fraction to the console
    * @param ostream& allows the output
    * @pre None
    * @post the fraction is displayed*/
    void display( ostream& );
};
#endif