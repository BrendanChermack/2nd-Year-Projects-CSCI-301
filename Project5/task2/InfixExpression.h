/*
Description of the problem to solve: The program is designed to solve postfix equations with checks for formatting
and allows the user to solve multiple equations.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on Oct 25, Thursday.
Instructor: Professor Meichsner
*/
#ifndef InfixExpressionH
#define InfixExpressionH
#include "LinkedStack.h"
#include <string>

using namespace std;

class InfixExpression {
private:
    string infix;//class variable for the infix equation
    /** Checks if the equation is valid
    @post validates the equation
    @param infix the equation to be checked
    @return True if the equation is valid or false if not. */
    bool wellFormed( string infix );
    /** Checks if the brackets is balanced
    @post validates the equation
    @param infix the equation to be checked
    @return True if the equation is balanced or false if not. */
    bool balBrackets( string infix );
    /** converts the infix to postfix
    @pre the equation is to be balanced and well formed
    @post the new equation is retuned
    @return postfix equation*/
    string infixToPostfix();
    /** gives precedence to the operators
    @param op char to be checked
    @post operations are given either 1 or 2
    @return int of 1 or 2*/
    int precedence( char op );
    /** evaluates the postfix equationa
    @pre precedence of the operators is needed
    @param postFix postfix equation
    @post the solved equation is returned
    @return the number from the solved equation is returned*/
    float postFixEval( string postFix );
public:
    //default constructor (does nothing but intialize the object)
    InfixExpression();
    /** sets the users infix to the objects infix if valid
    @pre well balanced and balanced brackets are need
    @param infix infix equation the user will input
    @post sets the objects infix to the users
    @return returns true if successful false if not*/
    bool setValidInfix( string infix );
    /** solves a postfix equation
    @pre first uses setValidInfix
    @post gives the solved number
    @return returns the solved number*/
    float eval();
};
#include "InfixExpression.cpp"
#endif