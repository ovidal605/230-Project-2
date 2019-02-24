#ifndef __INPUT_H
#define __INPUT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INPUT_CHAR '>'

enum ActionType
{
  ERR = -1,
  GO,
  LOOK,
  TAKE_ITEM,
  DROP_ITEM,
  USE_ITEM
};

struct Action
{
  enum ActionType actionType;
  char *arg;
};

// Returns an action from user input
struct Action *get_action();
void free_action(struct Action *action);

enum ActionType get_action_type(struct Action *action);
char *get_action_arg(struct Action *action);

#endif