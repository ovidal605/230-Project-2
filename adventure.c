#include <stdio.h>
#include "rooms.h"
#include "items.h"
#include "input.h"

int main(void)
{
  struct Action *a = get_action();

  if (a->actionType == GO)
  {
    printf("%s", "GOING");
  }

  return 0;
}