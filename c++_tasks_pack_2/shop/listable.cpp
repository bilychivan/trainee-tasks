#include "listable.h"

unsigned int Listable::idCounter = 1;

Listable::Listable(std::string argName) : name(argName)
{
}

Listable::~Listable()
{
}

const std::string& Listable::getName() const
{
    return name;
}

unsigned int Listable::getID()
{
    return idCounter++;
}

std::ostream& operator<<(std::ostream& stream, Listable& object)
{
    stream << object.getName() << ":" << std::endl;

    return stream;
}