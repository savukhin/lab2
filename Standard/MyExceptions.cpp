#ifndef MYEXCEPTIONS_CPP
#define MYEXCEPTIONS_CPP

namespace MyExceptions {
    class DialogueCallbackInconsistency : public std::exception {
    public:
        const char* what() const throw () {
            return "Messages and callback size not equal";
        }
    };
}

#include "MyExceptions.cpp"

#endif