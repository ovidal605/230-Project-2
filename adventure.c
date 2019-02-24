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
  struct Room *hallway = room("You are in a hallway. To the south, is the jail cell. To the north is a vault with a tooth-shaped lock.", NULL);
  struct Room *vault = room("You are in a vault. To the south, is the hallway.", NULL);

  struct Item *tooth = item("tooth", "A tooth", NULL);

  item_add(startingRoom->items, tooth);

  set_room_exit_north(startingRoom, hallway);
  set_room_exit_south(hallway, startingRoom);

  set_room_exit_north(hallway, vault);
  set_room_exit_south(vault, hallway);
  room_lock_door(hallway, NORTH, tooth);

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

    switch (action->actionType)
    {
    case GO:
      traverse(myAvatar, action->arg);
      break;
    case LOOK:
      printf("\n%s\n", myAvatar->currentRoom->description);
      printf("\nThe room contains:\n");
      item_print(myAvatar->currentRoom->items->next);
      printf("\nIn your hands are:\n");
      item_print(myAvatar->items->next);
      break;
    case TAKE_ITEM:

      item = item_take(myAvatar->currentRoom->items, action->arg);

      if (item != NULL)
      {
        item_add(myAvatar->items, item);
        printf("\nYou pick up the %s.\n", item_name(item));
      }
      else
      {
        printf("That item is not on the floor.\n");
      }

      break;
    case DROP_ITEM:

      item = item_take(myAvatar->items, action->arg);

      if (item != NULL)
      {
        item_add(myAvatar->currentRoom->items, item);
        printf("\nYou drop the %s.\n", item_name(item));
      }
      else
      {
        printf("That item is not in your hands.\n");
      }

      break;
    case USE_ITEM:
      item = item_take(myAvatar->items, action->arg);

      if (item != NULL)
      {
        if (room_use_item(myAvatar->currentRoom, item))
        {
          printf("\nYou use the %s to open the door\n", item_name(item));
        }
        else
        {
          printf("\n%s did nothing\n", item_name(item));
          item_add(myAvatar->items, item);
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
  struct Room *nextRoom = NULL;
  enum dir direction;

  if (strcmp("north", arg) == 0)
  {
    nextRoom = get_room_exit(myAvatar->currentRoom, NORTH);
    direction = NORTH;
  }
  else if (strcmp("south", arg) == 0)
  {
    nextRoom = get_room_exit(myAvatar->currentRoom, SOUTH);
    direction = SOUTH;
  }
  else if (strcmp("east", arg) == 0)
  {
    nextRoom = get_room_exit(myAvatar->currentRoom, EAST);
    direction = EAST;
  }
  else if (strcmp("west", arg) == 0)
  {
    nextRoom = get_room_exit(myAvatar->currentRoom, WEST);
    direction = WEST;
  }
  else if (strcmp("up", arg) == 0)
  {
    nextRoom = get_room_exit(myAvatar->currentRoom, UP);
    direction = UP;
  }
  else if (strcmp("down", arg) == 0)
  {
    nextRoom = get_room_exit(myAvatar->currentRoom, DOWN);
    direction = DOWN;
  }

  if (nextRoom == NULL)
  {
    printf("\nNo room in that direction.\n");
  }
  else if (room_is_door_locked(myAvatar->currentRoom, direction))
  {
    printf("\nThat door is locked.\n");
  }
  else
  {
    myAvatar->currentRoom = nextRoom;
    printf("\nYou walk in to the next room. \n%s\n", nextRoom->description);
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
