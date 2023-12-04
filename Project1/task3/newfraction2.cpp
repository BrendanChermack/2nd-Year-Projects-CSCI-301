/*
Description of the problem to solve: This is the fraction2 cpp file where all the details of
the member functions and non-member functions are found.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on September 5, Tuesday
Instructor: Professor Meichsner
*/
#include "newfraction2.h"//fraction2's header file
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
       /*MEMEBER FUNCTIONS*/
    /*** Overloaded member function that adds 2 fractions together
    * @param f a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @pre None
    * @post returns a new fractions that comes from the fraction that the member function is called on and the parameters fraction being added together*/
fraction fraction::operator+( const fraction& f ) {
    int cd = f.getDenominator() * denominator;
    int newNume = ( f.getDenominator() * numerator ) +
        ( f.getNumerator() * denominator );
    fraction newFrac( newNume, cd );
    return newFrac;
}
    /*** Overloaded member function that subtracts 2 fractions
    * @param f a const fraction(Won't be changed) and a reference to the orginal variable (most effiecnt way to do it)
    * @pre None
    * @post returns a new fractions that comes from the fraction that the member function is called on and the parameters fraction being subtracted */
fraction fraction::operator-( const fraction& f ) {
    int cd = f.getDenominator() * denominator;
    int newNume = ( f.getDenominator() * numerator ) -
        ( f.getNumerator() * denominator );
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
    return f1 * recpF2;
}
    	/**Nonmember function */
	/** reads the fractions numerator and denominators values from istream
	/* @param in is the istream
    /* @param f is the fraction
	/* @pre None
	/* @post The numerator and denominators values have been 
	/*  read from in. The return value is the istream in.*/
istream& operator>>(istream& in, fraction& f){
    in >> f.numerator >> f.denominator;
    return in;
}
    /** Overloaded non-member function writes the numerator and denominators values of a fraction to the ostream
    /* @param out is the ostream
    /* @param f is the fraction
    /* @pre None
    /* @post The numerator and denominators values have been 
	/*  written out from out. The return value is the ostream out.*/
ostream& operator<<(ostream& out, fraction& f){
    out << f.getNumerator() << "/"<< f.getDenominator();
    return out;
}