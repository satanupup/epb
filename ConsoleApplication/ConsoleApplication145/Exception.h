#ifndef EXCEPTION
#define EXCEPTION

class Exception {
public:
    Exception() {
    }
 
    Exception(const char *message) : _message(message) {
    }
 
    virtual const char* message() {
        return _message;
    }
 
protected:
    const char *_message;
};

#endif