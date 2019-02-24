#include "input.h"

struct Action *get_action()
{
  char buffer[50];
  scanf("%[^\n]s ", buffer);

  char delim[] = " ";

  char *actionstr = strtok(buffer, delim);
  char *arg = strtok(NULL, delim);

  struct Action *action = (struct Action *)malloc(sizeof(struct Action));

  if (strcmp("go", actionstr) == 0)
  {
    action->actionType = GO;
  }
  else if (strcmp("look", actionstr) == 0)
  {
    action->actionType = LOOK;
  }
  else if (strcmp("take", actionstr) == 0)
  {
    action->actionType = TAKE_ITEM;
  }
  else if (strcmp("drop", actionstr) == 0)
  {
    action->actionType = DROP_ITEM;
  }
  else if (strcmp("use", actionstr) == 0)
  {
    action->actionType = USE_ITEM;
  }
  else
  {
    action->actionType = ERR;
  }

  action->arg = arg;

  return action;
}

void free_action(struct Action *action)
{
  free(action);
}

enum ActionType get_action_type(struct Action *action)
{
  return action->actionType;
}

char *get_action_arg(struct Action *action)
{
  return action->arg;
}
