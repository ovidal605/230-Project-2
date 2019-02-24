#ifndef __AVATAR_H
#define __AVATAR_H

#include <stdlib.h>
#include "items.h"

struct Avatar
{
  struct Room *currentRoom;
  struct Item *items;
};

struct Avatar *avatar(struct Room *startingRoom, struct Item *startingItems);
void free_avatar(struct Avatar *avatar);

void set_avatar_current_room(struct Avatar *avatar, struct Room *room);
void set_avatar_items(struct Avatar *avatar, struct Item *items);

#endif