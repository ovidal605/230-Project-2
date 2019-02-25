#include <stdio.h>
#include <string.h>
#include "rooms.h"
#include "items.h"
#include "input.h"
#include "avatar.h"

void play(void);
void traverse(struct Avatar *avater, char *arg);
void print_help();

int main(void)
{

  play();

  return 0;
}

struct Room *build_level()
{

  struct Room *startingRoom = room("You are in a dark, delapidated jail cell. To the north, a rusted jail cell door creeks open.", NULL);
  struct Room *vault = room("You are in a vault. To the south, is the hallway.There are doors leading in all directions", NULL);
  struct Room *room2 = room("You are in a dimly lit room. There are doors leading west, south, and east", NULL);
  struct Room *room3 = room("You are in a dimly lit room. The only only exit is back the way you came from.", NULL);
  struct Room *room4 = room("You are in a dimly lit room. There are doors leading north and east.", NULL);
  struct Room *room5 = room("You are in a dimly lit room. The only only exit is back the way you came from.", NULL);
  struct Room *room6 = room("You are in a dimly lit room. The only only exit is back the way you came from.", NULL);
  struct Room *room7 = room("You are in a bright room. There are stairs leading upwards. You take the stairs and upon exiting you"\
  " You are struck by the sun's warm rays. You have finally escaped your prison.", NULL);

  struct Room *hallway = room("You are in a hallway. To the south, is the jail cell. To the north is a vault with a tooth-shaped lock.", NULL);
  struct Room *hallway2 = room("You are in a hallway. To the west, is the vault. To the east, is a room with a foot-shaped lock.", NULL);
  struct Room *hallway3 = room("You are in a hallway. To the west, is the room with a foot-shaped lock. To the east, is room with a hand-shaped lock.", NULL);
  struct Room *hallway4 = room("You are in a hallway. To the north, is the room with a foot-shaped lock. To the south, is a room with a toe-shaped lock.", NULL);
  struct Room *hallway5 = room("You are in a hallway. To the west, is the room with a toe-shaped lock. To the east, is a room with a finger-shaped lock.", NULL);
  struct Room *hallway6 = room("You are in a hallway. To the west, is the room with an ear-shaped lock. To the east, is the vault.", NULL);
  struct Room *hallway7 = room("You are in a hallway. To the north, is the room with an eye-shaped lock. To the south, is the vault", NULL);

  struct Item *tooth = item("tooth", "A tooth", NULL);
  struct Item *foot = item("foot", "A foot", NULL);
  struct Item *hand = item("hand", "A hand", NULL);
  struct Item *toe = item("toe", "A toe", NULL);
  struct Item *finger = item("finger", "A finger", NULL);
  struct Item *ear = item("ear", "An ear", NULL);
  struct Item *eye = item("eye", "An eye", NULL);

  item_add(startingRoom->items, tooth);
  item_add(vault->items, foot);
  item_add(room2->items, hand);
  item_add(room3->items, toe);
  item_add(room4->items, finger);
  item_add(room5->items, ear);
  item_add(room6->items, eye);

  set_room_exit_north(startingRoom, hallway);
  set_room_exit_south(hallway, startingRoom);

  set_room_exit_north(hallway, vault);
  set_room_exit_south(vault, hallway);
  
  set_room_exit_east(vault, hallway2);
  set_room_exit_west(hallway2, vault);

  set_room_exit_west(vault, hallway6);
  set_room_exit_east(hallway6, vault);

  set_room_exit_north(vault, hallway7);
  set_room_exit_south(hallway7, vault);

  set_room_exit_east(hallway2, room2);
  set_room_exit_west(room2, hallway2);  
  
  set_room_exit_east(room2, hallway3);
  set_room_exit_west(hallway3, room2);

  set_room_exit_east(hallway3, room3);
  set_room_exit_west(room3, hallway3);

  set_room_exit_south(room2, hallway4);
  set_room_exit_north(hallway4, room2);

  set_room_exit_south(hallway4, room4);
  set_room_exit_north(room4, hallway4);

  set_room_exit_east(room4, hallway5);
  set_room_exit_west(hallway5, room4);

  set_room_exit_east(hallway5, room5);
  set_room_exit_west(room5, hallway5);

  set_room_exit_west(hallway6, room6);
  set_room_exit_east(room6, hallway6);

  set_room_exit_north(hallway7, room7);
  set_room_exit_south(room7, hallway7);

  room_lock_door(hallway, NORTH, tooth);
  room_lock_door(hallway2, EAST, foot);
  room_lock_door(hallway3, EAST, hand);
  room_lock_door(hallway4, SOUTH, toe);
  room_lock_door(hallway5, EAST, finger);
  room_lock_door(hallway6, WEST, ear);
  room_lock_door(hallway7, NORTH, eye);

  return startingRoom;
}

void play(void)
{
  struct Room *startingRoom = build_level();
  struct Avatar *myAvatar = avatar(startingRoom, NULL);

  printf("MY ADVENTURE\n----------------------\n\n");
  printf("You awake in a strange room. \n%s\n", startingRoom->description);
  printf("\nType help at any time for controls.\n");
  printf("\nPress any key to start.\n");
  struct Action *action = get_action();

  while (action->actionType != QUIT)
  {

    struct Item *item;
    struct Room *currentRoom = get_avatar_current_room(myAvatar);

    switch (action->actionType)
    {
    case GO:
      traverse(myAvatar, action->arg);
      break;
    case LOOK:
      printf("\n%s\n", get_room_description(currentRoom));
      printf("\nThe room contains:\n");
      item_print((get_room_items(currentRoom))->next);
      printf("\nIn your hands are:\n");
      item_print((get_avatar_items(myAvatar))->next);
      break;
    case TAKE_ITEM:

      item = item_take(get_room_items(currentRoom), action->arg);

      if (item != NULL)
      {
        item_add(get_avatar_items(myAvatar), item);
        printf("\nYou pick up the %s.\n", item_name(item));
      }
      else
      {
        printf("That item is not on the floor.\n");
      }

      break;
    case DROP_ITEM:

      item = item_take(get_room_items(currentRoom), action->arg);

      if (item != NULL)
      {
        item_add(get_room_items(currentRoom), item);
        printf("\nYou drop the %s.\n", item_name(item));
      }
      else
      {
        printf("That item is not in your hands.\n");
      }

      break;
    case USE_ITEM:
      item = item_take(get_avatar_items(myAvatar), action->arg);

      if (item != NULL)
      {
        if (room_use_item(currentRoom, item))
        {
          printf("\nYou use the %s to open the door\n", item_name(item));
        }
        else
        {
          printf("\n%s did nothing\n", item_name(item));
          item_add(get_avatar_items(myAvatar), item);
        }
      }
      else
      {
        printf("That item is not in your hands.\n");
      }
      break;
    case HELP:
      print_help();
      break;
    }

    free_action(action);
    action = get_action();
  }
}

void traverse(struct Avatar *myAvatar, char *arg)
{
  struct Room *currentRoom = get_avatar_current_room(myAvatar);
  struct Room *nextRoom = NULL;
  enum dir direction;

  if (strcmp("north", arg) == 0)
  {
    nextRoom = get_room_exit(currentRoom, NORTH);
    direction = NORTH;
  }
  else if (strcmp("south", arg) == 0)
  {
    nextRoom = get_room_exit(currentRoom, SOUTH);
    direction = SOUTH;
  }
  else if (strcmp("east", arg) == 0)
  {
    nextRoom = get_room_exit(currentRoom, EAST);
    direction = EAST;
  }
  else if (strcmp("west", arg) == 0)
  {
    nextRoom = get_room_exit(currentRoom, WEST);
    direction = WEST;
  }
  else if (strcmp("up", arg) == 0)
  {
    nextRoom = get_room_exit(currentRoom, UP);
    direction = UP;
  }
  else if (strcmp("down", arg) == 0)
  {
    nextRoom = get_room_exit(currentRoom, DOWN);
    direction = DOWN;
  }

  if (nextRoom == NULL)
  {
    printf("\nNo room in that direction.\n");
  }
  else if (room_is_door_locked(currentRoom, direction))
  {
    printf("\nThat door is locked.\n");
  }
  else
  {
    myAvatar->currentRoom = nextRoom;
    printf("\nYou walk in to the next room. \n%s\n", get_room_description(nextRoom));
  }
}

void print_help()
{
  printf("\nHelp\n");
  printf("quit: Exits the game.\n");
  printf("go: Traverses your avatar to other rooms. Usage go {north, south, east, west, up, down}\n");
  printf("look: Displays room description, items in room, and items in your inventory.\n");
  printf("take: Takes an item from the room. Usage take ITEMNAME\n");
  printf("drop: Drops an item from your inventory on the ground. Usage drop ITEMNAME \n");
  printf("use: uses an item in your inventory to interact with the room. Usage use ITEMNAME\n");
}
