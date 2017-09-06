#ifndef HELPERS_H
#define HELPERS_H

#include "entity.h"
#include "caster.h"
#include "entity.h"
#include "skeleton.h"
#include "warrior.h"
#include "archer.h"
#include "mage.h"
#include "vampire.h"
#include "warlock.h"
#include "healer.h"
#include "helpers.h"

#include <vector>
#include <cassert>

void displayEntities(const std::vector<Entity::Ptr>& array);

void entitiesAttacks(Entity::Ptr& first, Entity::Ptr& second);

void entitiesCastSpells(const Entity::Ptr& first, Entity::Ptr& second);

void entitiesHeals(const Entity::Ptr& first, Entity::Ptr& second);

CATEGORY::ID getRandomGategory();

Entity::Ptr getEntity(CATEGORY::ID id, int hitpoints, int damage);

const char* getName(const Entity::Ptr& entity);

#endif