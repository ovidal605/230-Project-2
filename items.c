#include "items.h"

// Removes an item from the list with a matching name itemName
struct Item *item_take(struct Item *item, char *itemName)
{
  // Get a referance to the next item in the list
  struct Item *next = item_next(item);

  // While there is a next item
  while (next != NULL)
  {

    // If found, remove it from the list
    if (strcmp(item_name(next), itemName) == 0)
    {
      item->next = item_next(next);
      return item;
    }

    // progress the current and next item by one index
    item = item_next(item);
    next = item_next(next);
  }
}