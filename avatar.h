#ifndef __AVATAR_H
#define __AVATAR_H

#include <stdlib.h>
#include "items.h"

//Avatar struct
struct Avatar
{
  struct Room *currentRoom;
  struct Item *items;
};

//Prototypes
struct Avatar *avatar(struct Room *startingRoom, struct Item *startingItems);
struct Room *get_avatar_current_room(struct Avatar *avatar);
struct Item *get_avatar_items(struct Avatar *avatar);

void free_avatar(struct Avatar *avatar);
void set_avatar_current_room(struct Avatar *avatar, struct Room *room);
void set_avatar_items(struct Avatar *avatar, struct Item *items);
#endif