#ifndef __ROOMS_H
#define __ROOMS_H

#include "items.h"
#include <stdlib.h>
#include <string.h>

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

// Creates a new Room structure
struct Room *room(char *description, struct Item *items);

void free_room(struct Room *room);

void set_room_exit_north(struct Room *current, struct Room *other);
void set_room_exit_south(struct Room *current, struct Room *other);
void set_room_exit_east(struct Room *current, struct Room *other);
void set_room_exit_west(struct Room *current, struct Room *other);
void set_room_exit_up(struct Room *current, struct Room *other);
void set_room_exit_down(struct Room *current, struct Room *other);

/*
char *room_description(struct Room *room);
struct Item *room_items(struct Room *room);
*/

#endif