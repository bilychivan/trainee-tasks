#ifndef BASE_CLASS_H
#define BASE_CLASS_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <set>
#include <list>

class BaseException : public std::runtime_error
{
public:
    explicit BaseException(const std::string& message)
        : std::runtime_error(message)
    {

    }
};

template <typename T>
class Base
{
public:
    explicit Base(const std::string& name)
        : mName(), mID()
    {
        if (categoryNames.find(name) != categoryNames.end())
        {
            throw BaseException("category already exists: " + name);
        }

        idCounter += 1u;
        categoryNames.insert(name);
        mName = name;
        mID = idCounter;

        std::cout << "Base constr | ";
    }

    virtual ~Base()
    {
        std::cout << "Base destr\n";
    }

    void setName(const std::string& name)
    {
        mName = name;
    }

    const std::string& getName() const
    {
        return mName;
    }

    unsigned int getID() const
    {
        return mID;
    }

    void displayID() const
    {
        std::cout << this << " ID: " << mID << std::endl;
    }

    static void reset()
    {
        categoryNames.clear();
        idCounter = defaultCounterValue;
    }

private:
    static std::set<std::string> categoryNames;
    static const unsigned int defaultCounterValue;
    static unsigned int idCounter;

    std::string mName;
    unsigned int mID;
};

template <typename T>
std::set<std::string> Base<T>::categoryNames{};

template <typename T>
const unsigned int Base<T>::defaultCounterValue{0u};

template <typename T>
unsigned int Base<T>::idCounter{defaultCounterValue};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Base<T>* base)
{
    std::cout << '\"' << base->getName() << '\"';
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T*>& container)
{
    if (container.empty())
    {
        os << "    empty\n";

        return os;
    }

    for (const T* element : container)
    {
        os << "    " << element << std::endl;
    }

    return os;
}

#endif