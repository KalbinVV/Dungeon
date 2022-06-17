#ifndef INVENTORYHOLDER_H_INCLUDED
#define INVENTORYHOLDER_H_INCLUDED

#include "Item.h"
#include <vector>

class InventoryHolder{
    virtual void addItem(Item* item) = 0;
    virtual void removeItem(Item* item) = 0;
    virtual std::vector<Item*> getInventory() = 0;
};

#endif // INVENTORYHOLDER_H_INCLUDED
