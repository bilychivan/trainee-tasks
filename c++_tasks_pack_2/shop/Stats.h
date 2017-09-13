#ifndef STATS_H
#define STATS_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <iomanip>
#include "ShopException.h"

#define WIDTH_OF_ID 6
#define FILL_PADDING_OF_ID '0'

class Stats
{
protected:
    const int id;
    const std::string name;
    std::string desc;

public:
    Stats(int id);
    Stats(int id, std::string name, std::string desc);

    const std::string &getName() const;
    const std::string &getDesc() const;
    virtual const std::string &getSerial() const = 0;
    int getId() const;
};


#endif //STATS_H
