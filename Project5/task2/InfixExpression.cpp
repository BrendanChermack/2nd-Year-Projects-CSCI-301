/*
Description of the problem to solve: The program is designed to solve postfix equations with checks for formatting
and allows the user to solve multiple equations.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on Oct 25, Thursday.
Instructor: Professor Meichsner
*/
#include "LinkedStack.h"
#include "InfixExpression.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

InfixExpression::InfixExpression() { }//default constructor
bool InfixExpression::wellFormed( string infixEq ) {
    LinkedStack<char> checker;//stack to check the equation
    if ( balBrackets( infixEq ) ) {//if the brackets arent balanced return false right away.
        for ( int i = 0; i < infixEq.length(); i++ ) {//loops through the string
            char ch = infixEq[ i ];//accesses each char
            if ( isdigit( ch ) ) {//if the char is a digit
                checker.push( ch );//put it on the stack
            }
            else if ( ch == '+' || ch == '-' || ch == '*' || ch == '/' ) {//if the char is an operator
                if ( checker.isEmpty() || !isdigit( checker.peek() ) ) {
                    return false;  // Operator must be before a digit
                }
            }
        }
        return true;
    }
    return false;
}
bool InfixExpression::balBrackets( string infixEq ) {//checks if the brackets are even
    LinkedStack<char> bal;//stack for the brackets
    for ( int i = 0; i < infixEq.length(); i++ ) {//loops the string
        char ch = infixEq[ i ];//accesses each char
        if ( ch == '(' ) {
            bal.push( ch );
        }
        else if ( ch == ')' ) {
            if ( ( bal.isEmpty() ) || ( bal.peek() != '(' ) ) {//if the the parentheses are () it is invalid
                return false;
            }
            bal.pop();//clears the stack
        }
    }
    return bal.isEmpty();//if the stack is empty then the brackets are good
}
string InfixExpression::infixToPostfix() {
    string postFix;//will become a postfix equation
    LinkedStack<char> operatorStack;//stack for the operators to reorder.
    for ( int i = 0; i < infix.length(); i++ ) {
        char ch = infix[ i ];
        if ( isdigit( ch ) ) {//checks if ch is a number
            postFix += ch;//adds it to the new string
        }
        else {//if it is not a number
            switch ( ch ) {
            case '(': // Save '(' on stack
                operatorStack.push( ch );
                break;
            case '+': case '-': case '*': case '/': // Process stack operators of greater precedence
                while ( !operatorStack.isEmpty() && operatorStack.peek() != '(' && precedence( ch ) <= precedence( operatorStack.peek() ) ) {
                    postFix += operatorStack.peek();
                    operatorStack.pop();
                }
                operatorStack.push( ch ); // Save the operator
                break;
            case ')': // Pop stack until matching '('
                while ( operatorStack.peek() != '(' ) {
                    postFix += operatorStack.peek(); //to the end of postfix
                    operatorStack.pop();
                }
                operatorStack.pop(); // Remove the open parenthesis
                break;
            }
        }
    }
    // Append to postfix the operators remaining in the stack
    while ( !operatorStack.isEmpty() ) {
        postFix += operatorStack.peek(); //to the end of postfix
        operatorStack.pop();
    }
    return postFix;
}
int InfixExpression::precedence( char op ) {//checks higher priority of operators and gives them a value
    if ( op == '+' || op == '-' ) {
        return 1;
    }
    else if ( op == '*' || op == '/' ) {
        return 2;
    }
    else
        return 0;
}
float InfixExpression::postFixEval( string postFix ) {
    LinkedStack<float> evaler;
    for ( int i = 0; i < postFix.length(); i++ ) {
        char ch = postFix[ i ];
        if ( isdigit( ch ) ) {
            evaler.push( ch - '0' );//converts char to a digit
        }

        else // ch is an operator named op
        {
            // Evaluate and push the result
            int operand2 = evaler.peek();
            evaler.pop();
            int operand1 = evaler.peek();
            evaler.pop();
            if ( ch == '+' ) {
                float result = operand1 + operand2;
                evaler.push( result );
            }
            else if ( ch == '-' ) {
                float result = operand1 - operand2;
                evaler.push( result );
            }
            else if ( ch == '*' ) {
                float result = operand1 * operand2;
                evaler.push( result );
            }
            else if ( ch == '/' ) {
                float result = operand1 / operand2;
                evaler.push( result );
            }
        }
    }
    return evaler.peek();//returns the final result
}
bool InfixExpression::setValidInfix( string infixEq ) {//checks the infix is valid and set to the objects infix
    if ( wellFormed( infixEq ) && balBrackets( infixEq ) ) {
        this->infix = infixEq;
        return true;
    }
    return false;
}
float InfixExpression::eval() {//evaluates the expression after converting it
    return postFixEval( infixToPostfix() );
}