#include <stdio.h>
#include <string.h>
#include "rooms.h"
#include "items.h"
#include "input.h"
#include "avatar.h"

void play(void);
void traverse(struct Avatar *avater, char *arg);

int main(void)
{

  play();

  return 0;
}

struct Room *build_level()
{

  struct Room *startingRoom = room("You are in a dark, delapidated jail cell. To the north, a rusted jail cell door creeks open.", NULL);
  struct Room *hallway = room("You are in a hallway. To the south, is the jail cell.", NULL);

  set_room_exit_north(startingRoom, hallway);
  set_room_exit_south(hallway, startingRoom);

  return startingRoom;
}

void play(void)
{

  struct Room *startingRoom = build_level();
  struct Avatar *myAvatar = avatar(startingRoom, NULL);

  struct Action *action = get_action();
  while (action->actionType != ERR)
  {

    switch (action->actionType)
    {
    case GO:
      traverse(myAvatar, action->arg);
      break;
    case LOOK:
      printf("%s", "The room contains:\n");
      item_print(myAvatar->currentRoom->items->next);
      printf("%s", "In your hands are:\n");
      item_print(myAvatar->items->next);
      break;
    case TAKE_ITEM:

      break;
    case DROP_ITEM:
      /* code */
      break;
    case USE_ITEM:
      /* code */
      break;
    }

    free_action(action);
    action = get_action();
  }
}

void traverse(struct Avatar *myAvatar, char *arg)
{
  /* code */
}
