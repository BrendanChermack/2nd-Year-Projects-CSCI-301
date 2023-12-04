/*
Description of the problem to solve: This is the fraction cpp file where all the details of
the member functions are found.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on September 5, Tuesday
Instructor: Professor Meichsner
*/
#include "fraction.h"//fraction's header file
#include <cstdlib>
using namespace std;
/*** Constructor;
* @param numerator the numerator of the fraction
* @param denominator the denominator of the fraction
* @pre None
* @post None*/
fraction::fraction( int numerator, int denominator ) {
    this->numerator = numerator;
    this->denominator = denominator;
}
/*** Sets the numerator to a new value
* @param numerator the numerator of the fraction
* @pre None
* @post the fraction this is called on set it to a new value*/
void fraction::setNumerator( int numerator ) {
    this->numerator = numerator;
}
/*** Sets the denominator to a new value
* @param denominator the denominator of the fraction
* @pre None
* @post the fraction this is called on set it to a new value*/
void fraction::setDenominator( int denominator ) {
    this->denominator = denominator;
}
/*** returns the numerator of the fraction
* @pre None
* @post the numerator of the fraction is returned*/
int fraction::getNumerator() {
    return numerator;
}
/*** returns the denominator of the fraction
* @pre None
* @post the denominator of the fraction is returned*/
int fraction::getDenominator() {
    return denominator;
}
/*** Displays the fraction to the console
* @param outfile allows the output
* @pre None
* @post the fraction is displayed*/
void fraction::display( ostream& outfile ) {
    outfile << numerator << "/" << denominator;
}