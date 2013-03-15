#include "Exception.h"
#include <string>
#include <sstream>
using namespace std;
class ArrayIndexOutOfBoundsException : public Exception {
public:
    ArrayIndexOutOfBoundsException(int);

    ArrayIndexOutOfBoundsException(const char *message) {
        _message = message;
    }

    virtual const char* message() {
        return _message;
    }
};