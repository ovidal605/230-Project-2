#ifndef __MOD_1_H
#define __MOD_1_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Item
{
  char *name;
  char *desc;
  struct Item *next;
};

struct Item *item(char *name, char *desc, struct Item *next);

void item_free(struct Item *item);
void item_free_inventory(struct Item *itemHead);

char *item_name(struct Item *item);
char *item_description(struct Item *item);
struct Item *item_next(struct Item *item);

void item_add(struct Item *inventory, struct Item *item);
void item_print(struct Item *head);
struct Item *item_take(struct Item *item, char *itemName);

#endif