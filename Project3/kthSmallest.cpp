/*
Description of the problem to solve: Implementation of the kthSmall algorithm by
a function alongside a partition function that not only rearranges the array elements but gets
the pivots index. The end goal is to find the k-th smallest element in the array.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on September 27, Wednesday.
Instructor: Professor Meichsner
*/
#include <iostream>
using namespace std;
/***  The pivot is decided to be the index 0's value. We sort things less then it to the left and things greater than it to the right.
* Not caring about the exact order.
* @param dArr a pointer to what will be an array
* @param first the first index of the array
* @param last the last index of the array
* @pre None
* @post Returns the pivot index after partitioning*/
int partition( int* dArr, int first, int last ) {
    int pivot = dArr[ first ];
    int j = first;
    for ( int i = first + 1; i <= last; i++ ) {
        if ( dArr[ i ] < pivot ) {
            j++;
            swap( dArr[ i ], dArr[ j ] );
        }
    }
    swap( dArr[ first ], dArr[ j ] );
    return j;
}
/***  The pivot is decided to be the index 0's value. We sort things less then it to the left and things greater than it to the right.
* Not caring about the exact order.
* @param k the kth element of the array that we want
* @param dArr a pointer to what will be an array
* @param first the first index of the array
* @param last the last index of the array
* @pre None
* @post returns the k's value(base case)*/
int kthSmall( int k, int* dArr, int first, int last ) {
    if ( first <= last ) {
        int pivotIndex = partition( dArr, first, last );//calcs the pivot index while also partiotioning it for the first value of the array intiatially
        if ( k < pivotIndex - first + 1 ) {//If S1 contains k or more values, S1 contains the k smallest values of the array segment
            return kthSmall( k, dArr, first, pivotIndex - 1 );
        }
        else if ( k == pivotIndex - first + 1 ) {//If S1 contains k − 1 values, the kth smallest value must be the pivot p
            return dArr[ pivotIndex ];
        }
        else {//If S1 contains fewer than k − 1 values the kth smallest must be s2
            return kthSmall( k - ( pivotIndex - first + 1 ), dArr, pivotIndex + 1, last );
        }
    }
    return -1;
}
int main() {
    int arrSize;//varaible for the array size
    int k;//the kth element
    cout << "Enter what size you want the array to be: ";
    cin >> arrSize;
    int* dArr = new int[ arrSize ];//dynamic array that a user can decide

    cout << endl << "Enter the numbers you want in the array: ";
    for ( int i = 0; i < arrSize; i++ ) {//allows the user to input the numbers into the array
        cin >> dArr[ i ];
    }
    for ( int i = 0; i < arrSize; i++ )//prints the array
        cout << dArr[ i ] << " ";
    cout << "\nEnter the kth Smallest: ";//gets the kth element from the user
    cin >> k;
    if ( k > arrSize || k < 1) {//k needs to be a valid input for the array
        cout << "\nError k is invalid.";
        return 0;
    }
    
    int result = kthSmall( k, dArr, 0, arrSize - 1 );//calls the kthSmall function

    cout << "The kth smallest in the array: " << result << endl;
    
    for ( int i = 0; i < arrSize; i++ )//prints the new partiontioned 
        cout << dArr[ i ] << " ";
    cout << endl;
    delete[] dArr;
    return 0;
}