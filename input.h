#ifndef __MOD_1_H
#define __MOD_1_H

#include <stdio.h>

enum ActionType
{
  GO,
  LOOK,
  TAKE_ITEM,
  DROP_ITEM,
  USE_ITEM
};

struct Action
{
  ActionType actionType;
  char **args;
};

// Returns an action from user input
struct Action *get_action();

void free_action();

#endif