#ifndef __ROOMS_H
#define __ROOMS_H

#include "items.h"
#include <stdlib.h>
#include <string.h>

enum dir
{
  NORTH = 0,
  SOUTH,
  EAST,
  WEST,
  UP,
  DOWN
};

struct Room
{
  char *description;
  struct Item *items;
  struct Room *rooms[6];
  char *locks[6];
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
void set_room_exit(struct Room *current, struct Room *other, enum dir direction);

struct Room *get_room_exit(struct Room *current, enum dir direction);

void room_lock_door(struct Room *current, enum dir direction, struct Item *item);
_Bool room_use_item(struct Room *current, struct Item *item);
_Bool room_is_door_locked(struct Room *current, enum dir direction);

char *get_room_description(struct Room *room);
struct Item *get_room_items(struct Room *room);

#endif