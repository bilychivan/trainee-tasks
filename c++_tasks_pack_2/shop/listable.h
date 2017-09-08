#ifndef LISTABLE_H
#define LISTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <climits>
#include "shopexception.h"

class Listable
{
    public:
        Listable(std::string argName);
        virtual ~Listable();

        virtual const std::string print() const = 0;

        const std::string& getName() const;

    protected:
        unsigned int getID();

    private:
        std::string name;

        static unsigned int idCounter;
};

template<class ListableTemplate>
class ListableT : public Listable
{
    public:
        static const unsigned int searchNotFound = INT_MAX;

        ListableT(std::string argName, Listable* listable) : Listable(argName)
        {
            if (search(listable) != searchNotFound)
            {
                throw ShopException("Failed to add duplicate to list");
            }

            list.emplace_back(listable);

            id = Listable::getID();
        }

        static std::vector<Listable*>* getListableList()
        {
            return &list;
        }

        static unsigned int search(Listable* listable)
        {
            unsigned int it;

            for (it = 0; it != list.size(); it++)
            {
                if (list[it] == listable)
                {
                    return it;
                }
            }

            return searchNotFound;
        }

        static const void printAll(std::ostream& stream)
        {
            for (auto it: list)
            {
                stream << it->print() << std::endl;
            }
        }

    protected:
        static void removeListable(unsigned int index)
        {
            list.erase(list.begin() + index);
        }

        static void removeListable(Listable* listable)
        {
            unsigned int searchResult = search(listable);

            if (searchResult != searchNotFound)
            {
                removeListable(searchResult);
            }
        }

        const unsigned int getID() const
        {
            return id;
        }

        const std::string getIDString() const
        {
            return ("(" + std::to_string(getID()) + ")");
        }

    private:
        static std::vector<Listable*> list;

        unsigned int id;
};

template<class ListableTemplate>
std::vector<Listable*> ListableT<ListableTemplate>::list = {};

template<class ListableTemplate> std::ostream& operator<<(std::ostream& stream, ListableT<ListableTemplate>& object)
{
    stream << object.print();

    return stream;
}

std::ostream& operator<<(std::ostream&, Listable&);

#endif // LISTABLE_H
