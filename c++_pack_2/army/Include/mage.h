#ifndef MAGE_CLASS_H
#define MAGE_CLASS_H

#include "caster.h"

class Mage : public Caster
{
public:
    Mage(int hitpoints, int damage);

    virtual CATEGORY::ID getCategory() const override;

    void setBlastDamage(int blastDamage);
    int getBlastDamage() const;

private:
    static const int defaultBlastDamage;

    int mBlastDamage;
};

class MageException : public EntityException
{
public:
    explicit MageException(const std::string& message);
};

#endif