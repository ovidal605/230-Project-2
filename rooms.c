#include "rooms.h"

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

  if (items == NULL)
  {
    newRoom->items = item("HEAD", "HEAD", NULL);
  }
  else
  {
    newRoom->items = items;
  }

  for (int i = 0; i < 6; i++)
  {
    newRoom->rooms[i] = NULL;
    newRoom->locks[i] = NULL;
  }
}

void free_room(struct Room *room)
{
  free(room->description);
  free(room);
}

void set_room_exit_north(struct Room *current, struct Room *other)
{
  current->rooms[NORTH] = other;
}

void set_room_exit_south(struct Room *current, struct Room *other)
{
  current->rooms[SOUTH] = other;
}

void set_room_exit_east(struct Room *current, struct Room *other)
{
  current->rooms[EAST] = other;
}

void set_room_exit_west(struct Room *current, struct Room *other)
{
  current->rooms[WEST] = other;
}

void set_room_exit_up(struct Room *current, struct Room *other)
{
  current->rooms[UP] = other;
}

void set_room_exit_down(struct Room *current, struct Room *other)
{
  current->rooms[DOWN] = other;
}

void set_room_exit(struct Room *current, struct Room *other, enum dir direction)
{
  current->rooms[direction] = other;
}

struct Room *get_room_exit(struct Room *current, enum dir direction)
{
  return current->rooms[direction];
}

void room_lock_door(struct Room *current, enum dir direction, struct Item *item)
{
  current->locks[direction] = item_name(item);
}

_Bool room_use_item(struct Room *current, struct Item *item)
{
  _Bool unlocked_door = 0;

  for (int i = 0; i < 6; i++)
  {
    if (current->locks[i] != NULL && strcmp(current->locks[i], item_name(item)) == 0)
    {
      current->locks[i] = NULL;
      unlocked_door = 1;
    }
  }

  return unlocked_door;
}

_Bool room_is_door_locked(struct Room *current, enum dir direction)
{
  return current->locks[direction] != NULL;
}

char *get_room_description(struct Room *room)
{
  return room->description;
}

struct Item *get_room_items(struct Room *room)
{
  return room->items;
}
