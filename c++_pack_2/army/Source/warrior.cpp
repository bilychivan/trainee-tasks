#include "warrior.h"

const int Warrior::defaultChance = 50;
const int Warrior::minChance = 0;
const int Warrior::maxChance = 100;

Warrior::Warrior(int hitpoints, int damage)
    : Entity(hitpoints, ARMOR_TYPE::STRONG, damage), mDoubleDamageChance(defaultChance)
{

}

CATEGORY::ID Warrior::getCategory() const
{
    return CATEGORY::WARRIOR;
}

void Warrior::intermediateAction(Ptr& entity)
{
    if (rand() % maxChance < mDoubleDamageChance)
    {
        entity->takeDamage(getDamage());
    }
}

void Warrior::setDoubleDamageChance(int chance)
{
    if (chance < minChance || chance > maxChance)
    {
        throw WarriorException("wrong double damage chance: " + std::to_string(chance));
    }
    mDoubleDamageChance = chance;
}

int Warrior::getDoubleDamageChance() const
{
    return mDoubleDamageChance;
}

WarriorException::WarriorException(const std::string& message)
    : EntityException(message)
{

}