#include "rooms.h"

// Returns, Initializes, and allocates memory for a room struct
struct Room *room(char *description, struct Item *items)
{

  // Allocate memory for a new room
  struct Room *newRoom;
  newRoom = (struct Room *)malloc(sizeof(struct Room));
  // Copy the description
  char *descCopy = malloc(strlen(description));
  strcpy(descCopy, description);

  // Initialize variables
  newRoom->description = descCopy;

  // If there are no initial items set the room items to the NULL item
  if (items == NULL)
  {
    newRoom->items = item("HEAD", "HEAD", NULL);
  }
  // Else initialize the room items
  else
  {
    newRoom->items = items;
  }

  // Initialize the locks and connecting rooms
  for (int i = 0; i < 6; i++)
  {
    newRoom->rooms[i] = NULL;
    newRoom->locks[i] = NULL;
  }
}

// Frees the room struct and its inventory
void room_free(struct Room *room)
{
  free(get_room_description(room));
  item_free_inventory(get_room_items(room));
  free(room);
}

// Sets the exit of a room to a suppied room, direction
void set_room_exit(struct Room *current, struct Room *other, enum dir direction)
{
  current->rooms[direction] = other;
}

// Gets the room exit
struct Room *get_room_exit(struct Room *current, enum dir direction)
{
  return current->rooms[direction];
}

// Returns a pointer of the description of the room
char *get_room_description(struct Room *room)
{
  return room->description;
}

// Returns a pointer the room items
struct Item *get_room_items(struct Room *room)
{
  return room->items;
}

// Sets the lock of the door
void room_lock_door(struct Room *current, enum dir direction, struct Item *item)
{
  current->locks[direction] = item_name(item);
}

// Returns if the door is given the correct key
_Bool room_use_item(struct Room *current, struct Item *item)
{
  // Door is locked
  _Bool unlocked_door = 0;

  for (int i = 0; i < 6; i++)
  {
    // If the given item is the correct key then the door becomes unlocked
    if (current->locks[i] != NULL && strcmp(current->locks[i], item_name(item)) == 0)
    {
      current->locks[i] = NULL;
      unlocked_door = 1;
    }
  }

  // Return unlocked_door
  return unlocked_door;
}

//Returns if the door is locked
_Bool room_is_door_locked(struct Room *current, enum dir direction)
{
  return current->locks[direction] != NULL;
}
