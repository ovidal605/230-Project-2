#include "input.h"

struct Action *get_action()
{

  // Clear the input buffer
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }

  // Get user input
  char buffer[50] = {'\0'};
  scanf("%[^\n]s ", buffer);

  // Seperate user input by ' ' as a delimeter
  char delim[] = " ";
  char *actionstr = strtok(buffer, delim);
  char *arg = strtok(NULL, delim);

  struct Action *action = (struct Action *)malloc(sizeof(struct Action));

  // Parse the first argument of user input
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

  // Allcate space and copy the second user argument
  if (arg != NULL)
  {
    action->arg = strdup(arg);
  }
  else
  {
    action->arg = NULL;
  }

  return action;
}

void free_action(struct Action *action)
{
  if (action->arg != NULL)
  {
    free(action->arg);
  }

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
