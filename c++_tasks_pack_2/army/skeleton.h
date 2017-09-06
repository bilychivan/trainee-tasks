#ifndef SKELETON_H
#define SKELETON_H

#include <iostream>
#include <string>
#include "creature.h"

class Skeleton : public Creature
{
    public:
        Skeleton(std::string argName);

        virtual const std::string getClassName() const override {return "Skeleton";}
};

std::ostream& operator<<(std::ostream&, Skeleton&);

#endif // SKELETON_H
