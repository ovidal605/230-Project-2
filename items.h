#ifndef __MOD_1_H
#define __MOD_1_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Item struct
struct Item
{
  char *name;
  char *desc;
  struct Item *next;
};

//Prototypes
struct Item *item(char *name, char *desc, struct Item *next);
struct Item *item_take(struct Item *item, char *itemName);

char *item_name(struct Item *item);
char *item_description(struct Item *item);

void item_add(struct Item *inventory, struct Item *item);
void item_print(struct Item *head);
#endif