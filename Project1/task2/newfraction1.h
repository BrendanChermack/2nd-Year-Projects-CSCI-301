/*
Description of the problem to solve: A header file for a fraction object with the following features:
numerator and denomitor, setting both of those to a new fraction, a default constructor, getter functions to
get the private variables and a display memember function. It also includes nonmember functions that are over
loaded to add, subtract, multiply and divide fractions.
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
private: //variables for the fractions numerator and denominator
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
    int getNumerator() const;
    /*** returns the denominator of the fraction
    * @pre None
    * @post the denominator of the fraction is returned*/
    int getDenominator() const;
    /*** Displays the fraction to the console
    * @param ostream& allows the output
    * @pre None
    * @post the fraction is displayed*/
    void display( ostream& );
};
            /*NON MEMBER FUNCTIONS*/
    /*** Overloaded non-member function that adds 2 fractions together
    * @param f1 a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @param f2  a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @pre None
    * @post returns a fractions with a common denominator and properally multiplyed and added numerators of the fractions*/
fraction operator+( const fraction& f1, const fraction& f2 );
    /*** Overloaded non-member function that subtracts 2 fractions 
    * @param f1 a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @param f2  a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @pre None
    * @post returns a fractions with a common denominator and properally multiplyed and subtracted numerators of the fractions*/
fraction operator-( const fraction& f1, const fraction& f2 );
    /*** Overloaded non-member function that multiplys 2 fractions 
    * @param f1 a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @param f2  a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @pre None
    * @post returns a fractions with multiplied numerators and denominators from f1 and f2*/
fraction operator*( const fraction& f1, const fraction& f2 );
    /*** Overloaded non-member function that multiplys f1 by the recipical of f2 
    * @param f1 a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @param f2  a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @pre None
    * @post returns a fractions that was multiplied from f1 to the recipical of f2 */
fraction operator/( const fraction& f1, const fraction& f2 );
#endif