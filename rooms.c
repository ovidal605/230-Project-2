#include "rooms.h"

//Returns a room struct
struct Room *room(char *description, struct Item *items)
{

  // Allocate memory for a new room
  struct Room *newRoom;
  newRoom = (struct Room *)malloc(sizeof(struct Room));
  // Copy the description
  char *descCopy = malloc(strlen(description));
  strcpy(descCopy, description);

  // initialize variables
  newRoom->description = descCopy;

  //If there are no itnitial items set the room items to the NULL item
  if (items == NULL)
  {
    newRoom->items = item("HEAD", "HEAD", NULL);
  }
  //Else initialize the room items
  else
  {
    newRoom->items = items;
  }

  //Initialize the locks and connecting rooms
  for (int i = 0; i < 6; i++)
  {
    newRoom->rooms[i] = NULL;
    newRoom->locks[i] = NULL;
  }
}

//Frees the room struct
void free_room(struct Room *room)
{
  free(room->description);
  free(room);
}

//Sets the north exit
void set_room_exit_north(struct Room *current, struct Room *other)
{
  current->rooms[NORTH] = other;
}

//Sets the south exit
void set_room_exit_south(struct Room *current, struct Room *other)
{
  current->rooms[SOUTH] = other;
}

//Sets the east exit
void set_room_exit_east(struct Room *current, struct Room *other)
{
  current->rooms[EAST] = other;
}

//Sets the west exit
void set_room_exit_west(struct Room *current, struct Room *other)
{
  current->rooms[WEST] = other;
}

//Sets the up exit
void set_room_exit_up(struct Room *current, struct Room *other)
{
  current->rooms[UP] = other;
}

//Setst the down exit
void set_room_exit_down(struct Room *current, struct Room *other)
{
  current->rooms[DOWN] = other;
}

//Sets the correct exit of a room in the correct direction
void set_room_exit(struct Room *current, struct Room *other, enum dir direction)
{
  current->rooms[direction] = other;
}

//Gets the room exit
struct Room *get_room_exit(struct Room *current, enum dir direction)
{
  return current->rooms[direction];
}

//sets the lock of the door
void room_lock_door(struct Room *current, enum dir direction, struct Item *item)
{
  current->locks[direction] = item_name(item);
}

//Returns if the door is given the correct key
_Bool room_use_item(struct Room *current, struct Item *item)
{
  //Door is locked
  _Bool unlocked_door = 0;

  for (int i = 0; i < 6; i++)
  {
    //If the given item is the correct key then the door becomes unlocked
    if (current->locks[i] != NULL && strcmp(current->locks[i], item_name(item)) == 0)
    {
      current->locks[i] = NULL;
      unlocked_door = 1;
    }
  }

  //Return unlocked_door
  return unlocked_door;
}

//Returns if the door is locked
_Bool room_is_door_locked(struct Room *current, enum dir direction)
{
  return current->locks[direction] != NULL;
}

//Returns a pointer of the description of the room
char *get_room_description(struct Room *room)
{
  return room->description;
}

//Returns a pointer the room items
struct Item *get_room_items(struct Room *room)
{
  return room->items;
}
