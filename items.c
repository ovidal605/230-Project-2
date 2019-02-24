#include "items.h"
struct Item *item(char *name, char *desc, struct Item *next)
{
  //copy name and description
  char *nameCopy = malloc(strlen(name));
  strcpy(nameCopy, name);
  char *discCopy = malloc(strlen(desc));
  strcpy(discCopy, desc);
  struct Item *newItem;
  newItem = (struct Item *)malloc(sizeof(struct Item));
  //assign the name, description, next to the item struct variables
  newItem->name = nameCopy;
  newItem->desc = discCopy;
  newItem->next = next;
  return newItem;
}
//returns the name of an item
char *item_name(struct Item *item)
{
  //check if the item is in the list
  //if it isn't return the null string
  if (item->name == NULL)
  {
    return "";
  }
  return item->name;
}
//returns the description of an item
char *item_description(struct Item *item)
{
  //check if the item has a given description
  //if it does'n return the null string
  if (item->desc == NULL)
  {
    return "";
  }

  return item->desc;
}
// Returns the next item in the list
struct Item *item_next(struct Item *item)
{
  return item->next;
}

//prints the item list
void item_print(struct Item *head)
{
  //do not print the head node
  if (head == NULL)
    return;
  //print the current node name and description
  printf("%s: %s\n", head->name, head->desc);
  //print the next node on the list
  item_print(head->next);
}
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