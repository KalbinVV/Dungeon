#ifndef EQUIPMENTITEM_H_INCLUDED
#define EQUIPMENTITEM_H_INCLUDED

#include "Stats.h"

class EquipmentItem{
private:
    Stats stats;
public:
    void setStats(Stats stats);
    Stats getStats();
};

#endif // EQUIPMENTITEM_H_INCLUDED
