#include "avatar.h"

//returns a pointer to an Avatar struct
struct Avatar *avatar(struct Room *startingRoom, struct Item *startingItems)
{
  //Create and allocate size of avatar struct
  struct Avatar *newAvatar;
  newAvatar = (struct Avatar *)malloc(sizeof(struct Avatar));

  //Set the surrent room of the player
  set_avatar_current_room(newAvatar, startingRoom);

  //If the player has no starting items then set the players inventory
  //with an initial NULL item
  if (startingItems == NULL)
  {
    set_avatar_items(newAvatar, item("HEAD", "HEAD", NULL));
  }
  //Else set the inventory with the players starting items
  else
  {
    set_avatar_items(newAvatar, startingItems);
  }

  //return the player
  return newAvatar;
}

//Frees the memory of an avatar struct
void free_avatar(struct Avatar *avatar)
{
  free(avatar);
}

//Sets the avatars current room
void set_avatar_current_room(struct Avatar *avatar, struct Room *room)
{
  avatar->currentRoom = room;
}

//Sets the avatar's inventory
void set_avatar_items(struct Avatar *avatar, struct Item *items)
{
  avatar->items = items;
}

//Gets the pointer to the avatar's current room 
struct Room *get_avatar_current_room(struct Avatar *avatar)
{
  return avatar->currentRoom;
}

//Gets the pointer to the avatar's inventory
struct Item *get_avatar_items(struct Avatar *avatar)
{
  return avatar->items;
}