#include "avatar.h"

struct Avatar *avatar(struct Room *startingRoom, struct Item *startingItems)
{
  struct Avatar *newAvatar;
  newAvatar = (struct Avatar *)malloc(sizeof(struct Avatar));

  set_current_room(avatar, startingRoom);
  set_items(avatar, startingItems);
}

void free_avatar(struct Avatar *avatar)
{
  free(avatar);
}

void set_current_room(struct Avatar *avatar, struct Room *room)
{
  avatar->currentRoom = room;
}

void set_items(struct Avatar *avatar, struct Item *items)
{
  avatar->items = items;
}