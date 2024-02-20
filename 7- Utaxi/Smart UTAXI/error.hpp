#ifndef ERROR_HPP
#define ERROR_HPP

#include "const.hpp"

class Error
{
public:
    Error(string error)
    {
        error_description = error;
    }
    void print();

private:
    string error_description;
};

#endif