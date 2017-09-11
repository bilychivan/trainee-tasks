#ifndef SKELETON_H
#define SKELETON_H

#include "unit.h"

#define SKELETON_ATT 10

class Skeleton : public Unit
{
private:
    const static std::string className;

public:
    Skeleton();
    const std::string &getClassName() const override;
};

#endif // SKELETON_H