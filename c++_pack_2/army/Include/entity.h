#ifndef ENTITY_CLASS_H
#define ENTITY_CLASS_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

#include "category.h"

class Entity
{
public:
    enum ARMOR_TYPE
    {
        WEAK = 1,
        NORMAL = 2,
        STRONG = 3
    };

    using Ptr = std::unique_ptr<Entity>;

    Entity(int hitpoints, ARMOR_TYPE armor, int damage, bool resisted = true);
    virtual ~Entity();

    virtual void attack(Ptr& entity);
    void counterAttack(Entity* entity) const;

    virtual CATEGORY::ID getCategory() const = 0;

    void setDamage(int damage);
    int getDamage() const;

    void takeDamage(int damage);
    virtual void takeMagicDamage(int damage);
    void restore(int hitpoints);

    int getHitpoints() const;
    bool isDestroyed() const;

    int getArmor() const;

protected:
    virtual void intermediateAction(Ptr& entity);

    int mHitpoints;
    const int mMaxHitpoints;
    int mArmor;
    int mDamage;
    bool mResisted;
};

class EntityException : public std::runtime_error
{
public:
    explicit EntityException(const std::string& message);
};

#endif