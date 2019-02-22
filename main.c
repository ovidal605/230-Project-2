#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Prototypes
struct Item *item(char *name, char *desc, struct Item *next);
char *item_name(struct Item *item);
char *item_description(struct Item *item);
struct Item *item_take(struct Item *item, char *itemName);
void item_print(struct Item *head);
struct Room *room(char *description, struct Item *items,
                  struct Room *north, struct Room *south,
                  struct Room *east, struct Room *west,
                  struct Room *up, struct Room *down);
void room_exit_north(struct Room *current, struct Room *other);
void room_exit_south(struct Room *current, struct Room *other);
// end Prototypes
//struct declarations
struct Item
{
  char *name;
  char *desc;
  struct Item *next;
};
struct Room
{
  char *description;
  struct Item *items;
  struct Room *north;
  struct Room *south;
  struct Room *east;
  struct Room *west;
  struct Room *up;
  struct Room *down;
};
int main(int argc, char *argv[])
{
  // Problem 1
  struct Item *head = item("-1", "-1",
                           item("Item 1", "Description 1",
                                item("Item 2", "Description 2", NULL)));
  item_print(head->next);
  printf("After deletion of Item 1\n");
  item_take(head, "Item 1");
  item_print(head->next);
  printf("After deletion of Item 2\n");
  item_take(head, "Item 2");
  item_print(head->next);
  // Problem 2
  struct Item *room1Items = item("-1", "-1",
                                 item("My Room1 Item 1", "Description 1",
                                      item("My Room1 Item 2", "Description 2", NULL)));

  struct Item *room2Items = item("-1", "-1",
                                 item("My Room2 Item 1", "Description 1",
                                      item("My Room2 Item 2", "Description 2", NULL)));
  struct Room *room1 = room("My room 1", room1Items, NULL, NULL, NULL, NULL, NULL, NULL);
  struct Room *north = room("My North Room", room2Items, NULL, NULL, NULL, NULL, NULL, NULL);
  room_exit_north(room1, north);
  room_exit_south(north, room1);

  printf("\n\n%s\n", room1->north->description);
  printf("%s", north->south->description);
  return 0;
}
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
// Creates a new Room structure
struct Room *room(char *description, struct Item *items,
                  struct Room *north, struct Room *south,
                  struct Room *east, struct Room *west,
                  struct Room *up, struct Room *down)
{
  // Allocate memory for a new room
  struct Room *newRoom;
  newRoom = (struct Room *)malloc(sizeof(struct Room));
  // Copy the description
  char *descCopy = malloc(strlen(description));
  strcpy(descCopy, description);

  // initialize variables
  newRoom->description = descCopy;

  newRoom->items = items;
  newRoom->north;
  newRoom->east;
  newRoom->up;
  newRoom->south;
  newRoom->west;
  newRoom->down;
}
//Set the north direction of a room
void room_exit_north(struct Room *current, struct Room *other)
{
  //set the current room's north direction to the other room
  current->north = other;
}
//Set the south direction of a room
void room_exit_south(struct Room *current, struct Room *other)
{
  //set the current room's south direction to the other room
  current->south = other;
}
