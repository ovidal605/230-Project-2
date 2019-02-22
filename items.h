#ifndef __MOD_1_H
#define __MOD_1_H

#include <stdlib.h>
#include <string.h>

struct Item
{
  char *name;
  char *desc;
  struct Item *next;
};

struct Item *item(char *name, char *desc, struct Item *next);
char *item_name(struct Item *item);
char *item_description(struct Item *item);
struct Item *item_take(struct Item *item, char *itemName);
void item_print(struct Item *head);

#endif