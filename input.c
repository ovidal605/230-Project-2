#include "input.h"

//Returns a pointer to an Action struct
struct Action *get_action()
{

  // Clear the input buffer
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }

  // Get user input
  char buffer[50] = {'\0'};
  printf("\n> ");
  scanf("%[^\n]s ", buffer);

  // Seperate user input by ' ' as a delimeter
  char delim[] = " ";
  char *actionstr = strtok(buffer, delim);
  char *arg = strtok(NULL, delim);

  //Allocate memory for an Action struct
  struct Action *action = (struct Action *)malloc(sizeof(struct Action));

  // Parse the first argument of user input and set the action type
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
  else if (strcmp("quit", actionstr) == 0)
  {
    action->actionType = QUIT;
  }
  else if (strcmp("help", actionstr) == 0)
  {
    action->actionType = HELP;
  }
  else
  {
    action->actionType = ERR;
  }

  //Allocate space and copy the second user argument
  if (arg != NULL)
  {
    action->arg = strdup(arg);
  }
  else
  {
    action->arg = NULL;
  }

  //Return the Action struct
  return action;
}

//Frees the action
void free_action(struct Action *action)
{
  //If the second user argument is not free then free it
  if (action->arg != NULL)
  {
    free(action->arg);
  }

  free(action);
}

//Returns the action type
enum ActionType get_action_type(struct Action *action)
{
  return action->actionType;
}

//Returns a pointer to player's second argument
char *get_action_arg(struct Action *action)
{
  return action->arg;
}
