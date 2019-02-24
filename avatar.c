#include "avatar.h"

struct Avatar *avatar(struct Room *startingRoom, struct Item *startingItems)
{
  struct Avatar *newAvatar;
  newAvatar = (struct Avatar *)malloc(sizeof(struct Avatar));

  set_avatar_current_room(newAvatar, startingRoom);

  if (startingItems == NULL)
  {
    set_avatar_items(newAvatar, item("HEAD", "HEAD", "HEAD", NULL));
  }
  else
  {
    set_avatar_items(newAvatar, startingItems);
  }

  return newAvatar;
}

void free_avatar(struct Avatar *avatar)
{
  free(avatar);
}

void set_avatar_current_room(struct Avatar *avatar, struct Room *room)
{
  avatar->currentRoom = room;
}

void set_avatar_items(struct Avatar *avatar, struct Item *items)
{
  avatar->items = items;
}