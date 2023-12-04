/*
Description of the problem to solve: The program is designed to solve postfix equations with checks for formatting
and allows the user to solve multiple equations.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on Oct 25, Thursday.
Instructor: Professor Meichsner
*/
#include "InfixExpression.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    InfixExpression infix;//object delcared
    string infixEq;
    int choice;
    cout << "Welcome to the Infix Calculator!" << endl;
    cout << "Enter your choice:" << endl;
    cout << "1: Infix equation to solve" << endl;
    cout << "2: Exit program." << endl;
    cin >> choice;
    while ( choice == 1 ) {//while the user want to solve infixs
        cout << "Enter a valid infix equation:" << endl;
        cin >> infixEq;
        if ( infix.setValidInfix( infixEq ) ) {//checks if the input equation is formtted right and the solves it if so
            cout << "The solved post fix version of your infix equation is: " << infix.eval() << endl;
            cout << "Enter your choice again:" << endl;
            cout << "1: Infix equation to solve" << endl;
            cout << "2: Exit program." << endl;
        }
        else {//invalid equations
            cout << "invalid infix eqaution." << endl;
            cout << "Enter your choice again:" << endl;
            cout << "1: Infix equation to solve" << endl;
            cout << "2: Exit program." << endl;
        }
        cin >> choice;//enter the choice again.
    }
    cout << "\nThanks for using the Infix Calculator." << endl;
}