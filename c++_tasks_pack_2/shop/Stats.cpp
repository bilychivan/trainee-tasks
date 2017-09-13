#include "Stats.h"

Stats::Stats(int id) : id(id) {}

Stats::Stats(int id, std::string name, std::string desc) : id(id), name(name), desc(desc) {}

const std::string &Stats::getName() const
{
    return this->name;
}

const std::string &Stats::getDesc() const
{
    return this->desc;
}

int Stats::getId() const
{
    return this->id;
}