#ifndef __INPUT_H
#define __INPUT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INPUT_CHAR '>'

//Enum the action type
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

//Action struct
struct Action
{
  enum ActionType actionType;
  char *arg;
};

//Prototypes
struct Action *get_action();

enum ActionType get_action_type(struct Action *action);

char *get_action_arg(struct Action *action);

void free_action(struct Action *action);
#endif