#ifndef __INPUT_H
#define __INPUT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INPUT_CHAR '>'

// Enum  of the valid action types
enum ActionType
{
  ERR = -1,
  QUIT,
  HELP,
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

struct Action *get_action();
void free_action(struct Action *action);

enum ActionType get_action_type(struct Action *action);
char *get_action_arg(struct Action *action);

#endif