#ifndef __MOD_1_H
#define __MOD_1_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Item
{
  char *name;
  char *desc;
  char *use;
  struct Item *next;
};

struct Item *item(char *name, char *desc, char *use, struct Item *next);
char *item_name(struct Item *item);
char *item_description(struct Item *item);
struct Item *item_take(struct Item *item, char *itemName);
void item_add(struct Item *inventory, struct Item *item);
void item_print(struct Item *head);
void item_use(struct Item *inventory, char *item);
struct Item *item_find(struct Item *inventory, char *itemName);

#endif