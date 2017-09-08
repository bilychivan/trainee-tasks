#include "base.h"

std::ostream& operator<<(std::ostream& os, const std::set<std::string>& container)
{
    if (container.empty())
    {
        os << "    empty\n";

        return os;
    }

    for (const std::string& element : container)
    {
        os << "    " << element << std::endl;
    }

    return os;
}