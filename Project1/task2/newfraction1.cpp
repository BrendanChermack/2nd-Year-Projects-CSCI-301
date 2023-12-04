/*
Description of the problem to solve: This is the fraction1 cpp file where all the details of
the member functions and non-member functions are found.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on September 5, Tuesday
Instructor: Professor Meichsner
*/
#include "newfraction1.h"//fraction1's header file
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
int fraction::getNumerator() const {
    return numerator;
}
    /*** returns the denominator of the fraction
    * @pre None
    * @post the denominator of the fraction is returned*/
int fraction::getDenominator() const {
    return denominator;
}
    /*** Displays the fraction to the console
    * @param outfile allows the output
    * @pre None
    * @post the fraction is displayed*/
void fraction::display( ostream& outfile ) {
    outfile << numerator << "/" << denominator;
}
            /*NON MEMBER FUNCTIONS*/
    /*** Overloaded non-member function that adds 2 fractions together
    * @param f1 a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @param f2  a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @pre None
    * @post returns a fractions with a common denominator and properally multiplyed and added numerators of the fractions*/
fraction operator+( const fraction& f1, const fraction& f2 ) {
    int cd = f1.getDenominator() * f2.getDenominator();
    int newNume = ( f1.getDenominator() * f2.getNumerator() ) +
        ( f1.getNumerator() * f2.getDenominator() );
    fraction newFrac( newNume, cd );
    return newFrac;
}
    /*** Overloaded non-member function that subtracts 2 fractions 
    * @param f1 a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @param f2  a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @pre None
    * @post returns a fractions with a common denominator and properally multiplyed and subtracted numerators of the fractions*/
fraction operator-( const fraction& f1, const fraction& f2 ) {
    int cd = f1.getDenominator() * f2.getDenominator();
    int newNume = ( f1.getNumerator() * f2.getDenominator() ) -
        ( f1.getDenominator() * f2.getNumerator() );
    fraction newFrac( newNume, cd );
    return newFrac;
}
    /*** Overloaded non-member function that multiplys 2 fractions 
    * @param f1 a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @param f2  a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @pre None
    * @post returns a fractions with multiplied numerators and denominators from f1 and f2*/
fraction operator*( const fraction& f1, const fraction& f2 ) {
    int newNume = f2.getNumerator() * f1.getNumerator();
    int newDem = f2.getDenominator() * f1.getDenominator();
    fraction newFrac( newNume, newDem );
    return newFrac;
}
    /*** Overloaded non-member function that multiplys f1 by the recipical of f2 
    * @param f1 a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @param f2  a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @pre None
    * @post returns a fractions that was multiplied from f1 to the recipical of f2 */
fraction operator/( const fraction& f1, const fraction& f2 ) {
    fraction recpF2( f2.getDenominator(), f2.getNumerator() );
    return f1 * recpF2;//uses the previously overloaded * operator for convience
}