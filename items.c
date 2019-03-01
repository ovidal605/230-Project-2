#include "items.h"

//Returns an Item struct
struct Item *item(char *name, char *desc, struct Item *next)
{
  //copy name and description
  char *nameCopy = malloc(strlen(name));
  strcpy(nameCopy, name);

  char *discCopy = malloc(strlen(desc));
  strcpy(discCopy, desc);

  //Create an Item struct and allocate memory for it
  struct Item *newItem;
  newItem = (struct Item *)malloc(sizeof(struct Item));

  //assign the name, description, next to the item struct variables
  newItem->name = nameCopy;
  newItem->desc = discCopy;
  newItem->next = next;
  return newItem;
}

void item_free(struct Item *item)
{
  free(item_name(item));
  free(item_description(item));
  free(item);
}

void item_free_inventory(struct Item *itemHead)
{
  if (itemHead != NULL)
  {
    struct Item *next = item_next(itemHead);
    item_free_inventory(next);

    item_free(itemHead);
  }
}

//Returns the name of an item
char *item_name(struct Item *item)
{
  return item->name;
}

//Returns the description of an item
char *item_description(struct Item *item)
{
  return item->desc;
}

//Returns the next item in the list
struct Item *item_next(struct Item *item)
{
  return item->next;
}

//Prints the item list
void item_print(struct Item *head)
{
  //Do not print the head node
  if (head == NULL)
    return;

  //Print the current node name and description
  printf("%s: %s\n", head->name, head->desc);
  //Print the next node on the list
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
    // If found, remove it from the list and return the item
    if (strcmp(item_name(next), itemName) == 0)
    {
      item->next = item_next(next);
      return next;
    }

    //Progress the current and next item by one index
    item = item_next(item);
    next = item_next(next);
  }
  //Return NULL
  return NULL;
}

//Adds an item to the player's inventory
void item_add(struct Item *inventory, struct Item *item)
{
  //Creates an temp item and connects it to the last item in the player's inventory
  struct Item *temp = inventory->next;
  inventory->next = item;
  item->next = temp;
}