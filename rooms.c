#include "rooms.h"

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

void free_room(struct Room *room)
{
  free(room->description);
  free(room);
}

void room_exit_north(struct Room *current, struct Room *other)
{
  current->north = other;
}

void room_exit_south(struct Room *current, struct Room *other)
{
  current->south = other;
}

void room_exit_east(struct Room *current, struct Room *other)
{
  current->east = other;
}

void room_exit_west(struct Room *current, struct Room *other)
{
  current->west = other;
}

void room_exit_up(struct Room *current, struct Room *other)
{
  current->up = other;
}

void room_exit_down(struct Room *current, struct Room *other)
{
  current->down = other;
}

char *room_description(struct Room *room)
{
  return room->description;
}

struct Item *room_items(struct Room *room)
{
  return room->items;
}