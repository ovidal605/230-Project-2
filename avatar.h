#ifndef __MOD_1_H
#define __MOD_1_H

struct Avatar
{
  struct Room *currentRoom;
  struct Item *items;
};

struct Avatar *avatar(struct Room *startingRoom, struct Item *startingItems);
void free_avatar(struct Avatar *avatar);

void set_current_room(struct Avatar *avatar, struct Room *room);
void set_items(struct Avatar *avatar, struct Item *items);

#endif