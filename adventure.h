#ifndef __ADVENTURE_H
#define __ADVENTURE_H

#include <stdio.h>
#include <string.h>
#include "rooms.h"
#include "items.h"
#include "input.h"
#include "avatar.h"

#define LEVEL_SIZE 16

struct Room **build_level();
void free_level(struct Room **level, int room_size);

// Starts the game
void play(void);

// Game actions
void traverse(struct Avatar *avatar, char *arg);
void look(struct Avatar *avatar);
void take(struct Avatar *avatar, char *itemName);
void drop(struct Avatar *avatar, char *itemName);
void use(struct Avatar *avater, char *itemName);
void print_help();

#endif