#ifndef _NOT_FOUND_EXCEPTION
#define _NOT_FOUND_EXCEPTION
#include <stdexcept>
#include <string>
using namespace std;
class NotFoundException: public logic_error {
public:
    NotFoundException( const string& message = "" );
}; // end NotFoundException 
#include "NotFoundException.cpp"
#endif