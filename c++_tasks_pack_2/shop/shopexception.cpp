#include "shopexception.h"

ShopException::ShopException(const char* str) : std::logic_error(str) {}