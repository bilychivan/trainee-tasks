#ifndef SHOP_EXCEPTION_H
#define SHOP_EXCEPTION_H

#include <iostream>
#include <stdexcept>

class ShopException : public std::logic_error
{
public:
    ShopException(const char *error) : std::logic_error(error) {};
};

#endif //SHOP_EXCEPTION_H