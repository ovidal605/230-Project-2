#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Prototypes

struct Room *room(char *description, struct Item *items,
                  struct Room *north, struct Room *south,
                  struct Room *east, struct Room *west,
                  struct Room *up, struct Room *down);
void room_exit_north(struct Room *current, struct Room *other);
void room_exit_south(struct Room *current, struct Room *other);
// end Prototypes
//struct declarations
struct Room
{
  char *description;
  struct Item *items;
  struct Room *north;
  struct Room *south;
  struct Room *east;
  struct Room *west;
  struct Room *up;
  struct Room *down;
};

int main(int argc, char *argv[])
{
 
}

// Creates a new Room structure
struct Room *room(char *description, struct Item *items,
                  struct Room *north, struct Room *south,
                  struct Room *east, struct Room *west,
                  struct Room *up, struct Room *down)
{
  // Allocate memory for a new room
  struct Room *newRoom;
  newRoom = (struct Room *)malloc(sizeof(struct Room));
  // Copy the description
  char *descCopy = malloc(strlen(description));
  strcpy(descCopy, description);

  // initialize variables
  newRoom->description = descCopy;

  newRoom->items = items;
  newRoom->north;
  newRoom->east;
  newRoom->up;
  newRoom->south;
  newRoom->west;
  newRoom->down;
}
//Set the north direction of a room
void room_exit_north(struct Room *current, struct Room *other)
{
  //set the current room's north direction to the other room
  current->north = other;
}
//Set the south direction of a room
void room_exit_south(struct Room *current, struct Room *other)
{
  //set the current room's south direction to the other room
  current->south = other;
}
