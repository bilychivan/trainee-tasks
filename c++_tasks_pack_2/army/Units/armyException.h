#ifndef ARMY_ARMYEXCEPTION_H
#define ARMY_ARMYEXCEPTION_H

#include <iostream>
#include <stdexcept>

class ArmyException : public std::logic_error
{
public:
    ArmyException(const char *error) : std::logic_error(error) {};
};

#endif //ARMY_ARMYEXCEPTION_H
