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

  newRoom->north = NULL;
  newRoom->east = NULL;
  newRoom->up = NULL;
  newRoom->south = NULL;
  newRoom->west = NULL;
  newRoom->down = NULL;
}

void free_room(struct Room *room)
{
  free(room->description);
  free(room);
}

void set_room_exit_north(struct Room *current, struct Room *other)
{
  current->north = other;
}

void set_room_exit_south(struct Room *current, struct Room *other)
{
  current->south = other;
}

void set_room_exit_east(struct Room *current, struct Room *other)
{
  current->east = other;
}

void set_room_exit_west(struct Room *current, struct Room *other)
{
  current->west = other;
}

void set_room_exit_up(struct Room *current, struct Room *other)
{
  current->up = other;
}

void set_room_exit_down(struct Room *current, struct Room *other)
{
  current->down = other;
}

/*
char *room_description(struct Room *room)
{
  return room->description;
}

struct Item *room_items(struct Room *room)
{
  return room->items;
}
*/