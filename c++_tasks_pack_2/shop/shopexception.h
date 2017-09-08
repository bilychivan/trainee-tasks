#ifndef SHOPEXCEPTION_H
#define SHOPEXCEPTION_H

#include <iostream>

class ShopException : public std::logic_error
{
    public:
        ShopException(const char*);
};

#endif // SHOPEXCEPTION_H
