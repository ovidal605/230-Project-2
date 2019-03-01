#include "adventure.h"

int main(void)
{
  // main game function
  play();

  return 0;
}

/*
 * Builds the entire level.
 *  Instantiates rooms
 *  Adds items, connects rooms
 * 
 * Returns the level as an array of rooms where index 0 is the starting room 
 */
struct Room **build_level()
{

  // keep the entire level in an array for later freeing
  struct Room **level = malloc(LEVEL_SIZE * sizeof(struct Room));

  // Creates the rooms in the level
  struct Room *startingRoom = room("You are in a dark, delapidated jail cell. To the north, a rusted jail cell door creeks open.", NULL);
  struct Room *vault = room("You are in a vault. To the south, is the hallway. There are doors leading in all directions", NULL);
  struct Room *room2 = room("You are in a dimly lit room. There are doors leading west, south, and east", NULL);
  struct Room *room3 = room("You are in a dimly lit room. The only only exit is back the way you came from.", NULL);
  struct Room *room4 = room("You are in a dimly lit room. There are doors leading north and east.", NULL);
  struct Room *room5 = room("You are in a dimly lit room. The only only exit is back the way you came from.", NULL);
  struct Room *room6 = room("You are in a dimly lit room. The only only exit is back the way you came from.", NULL);
  struct Room *room7 = room("You are in a bright room. There are stairs leading upwards.", NULL);
  struct Room *end = room("You take the stairs and upon exiting you. You are struck by the sun's warm rays. You have finally escaped your prison.", NULL);

  // Creates the hallays to walk through the rooms
  struct Room *hallway = room("You are in a hallway. To the south, is the jail cell. To the north is a vault with a tooth-shaped lock.", NULL);
  struct Room *hallway2 = room("You are in a hallway. To the west, is the vault. To the east, is a room with a foot-shaped lock.", NULL);
  struct Room *hallway3 = room("You are in a hallway. To the west, is the room with a foot-shaped lock. To the east, is room with a hand-shaped lock.", NULL);
  struct Room *hallway4 = room("You are in a hallway. To the north, is the room with a foot-shaped lock. To the south, is a room with a toe-shaped lock.", NULL);
  struct Room *hallway5 = room("You are in a hallway. To the west, is the room with a toe-shaped lock. To the east, is a room with a finger-shaped lock.", NULL);
  struct Room *hallway6 = room("You are in a hallway. To the west, is the room with an ear-shaped lock. To the east, is the vault.", NULL);
  struct Room *hallway7 = room("You are in a hallway. To the north, is the room with an eye-shaped lock. To the south, is the vault", NULL);

  // Add the rooms to the level array, (need an easy to use structure to free room memory)
  level[0] = startingRoom;
  level[1] = vault;
  level[2] = room2;
  level[3] = room3;
  level[4] = room4;
  level[5] = room5;
  level[6] = room6;
  level[7] = room7;
  level[8] = end;
  level[9] = hallway;
  level[10] = hallway2;
  level[11] = hallway3;
  level[12] = hallway4;
  level[13] = hallway5;
  level[14] = hallway6;
  level[15] = hallway7;

  // Creates the items of the game
  struct Item *tooth = item("tooth", "A tooth", NULL);
  struct Item *foot = item("foot", "A foot", NULL);
  struct Item *hand = item("hand", "A hand", NULL);
  struct Item *toe = item("toe", "A toe", NULL);
  struct Item *finger = item("finger", "A finger", NULL);
  struct Item *ear = item("ear", "An ear", NULL);
  struct Item *eye = item("eye", "An eye", NULL);

  // Places the correct item in each room.
  item_add(startingRoom->items, tooth);
  item_add(vault->items, foot);
  item_add(room2->items, hand);
  item_add(room3->items, toe);
  item_add(room4->items, finger);
  item_add(room5->items, ear);
  item_add(room6->items, eye);

  // Sets the entrance and exit of each room with the connected hallways
  set_room_exit(startingRoom, hallway, NORTH);
  set_room_exit(hallway, startingRoom, SOUTH);

  set_room_exit(hallway, vault, NORTH);
  set_room_exit(vault, hallway, SOUTH);

  set_room_exit(vault, hallway2, EAST);
  set_room_exit(hallway2, vault, WEST);

  set_room_exit(vault, hallway6, WEST);
  set_room_exit(hallway6, vault, EAST);

  set_room_exit(vault, hallway7, NORTH);
  set_room_exit(hallway7, vault, SOUTH);

  set_room_exit(hallway2, room2, EAST);
  set_room_exit(room2, hallway2, WEST);

  set_room_exit(room2, hallway3, EAST);
  set_room_exit(hallway3, room2, WEST);

  set_room_exit(hallway3, room3, EAST);
  set_room_exit(room3, hallway3, WEST);

  set_room_exit(room2, hallway4, SOUTH);
  set_room_exit(hallway4, room2, NORTH);

  set_room_exit(hallway4, room4, SOUTH);
  set_room_exit(room4, hallway4, NORTH);

  set_room_exit(room4, hallway5, EAST);
  set_room_exit(hallway5, room4, WEST);

  set_room_exit(hallway5, room5, EAST);
  set_room_exit(room5, hallway5, WEST);

  set_room_exit(hallway6, room6, WEST);
  set_room_exit(room6, hallway6, EAST);

  set_room_exit(hallway7, room7, NORTH);
  set_room_exit(room7, hallway7, SOUTH);

  set_room_exit(room7, end, UP);
  set_room_exit(end, room7, DOWN);

  // Sets the "key" that every room will need in order to be opened
  room_lock_door(hallway, NORTH, tooth);
  room_lock_door(hallway2, EAST, foot);
  room_lock_door(hallway3, EAST, hand);
  room_lock_door(hallway4, SOUTH, toe);
  room_lock_door(hallway5, EAST, finger);
  room_lock_door(hallway6, WEST, ear);
  room_lock_door(hallway7, NORTH, eye);

  return level;
}

/*
 * Frees the memory of the entire level and its items
 */
void level_free(struct Room **level, int room_size)
{
  for (int i = 0; i < room_size; ++i)
  {
    room_free(level[i]);
  }

  free(level);
}

/*
 *  The main game loop
 */
void play(void)
{
  // Creates the starting room along with the rest of the map
  struct Room **level = build_level();
  struct Room *startingRoom = level[0];

  // Creates the avatar to be used in the game and is tplaced in the starting room along with no initial items
  struct Avatar *myAvatar = avatar(startingRoom, NULL);

  // Prints the instructions and setting of the game
  printf("ESCAPE!!!!\n----------------------\n\n");
  printf("You awake in a strange room. \n%s\n", startingRoom->description);
  printf("\nType help at any time for controls.\n");
  printf("\nPress any key to start.\n");

  // Gets an action from the player
  struct Action *action = get_action();

  // While the player doesn't quit
  while (get_action_type(action) != QUIT)
  {
    // Get the current room of the player
    struct Room *currentRoom = get_avatar_current_room(myAvatar);

    // Get the action of the player and follow the corresponding instructions
    switch (get_action_type(action))
    {
    // If the action is "go"
    case GO:
      traverse(myAvatar, action->arg);
      break;
    // If the action is "look"
    case LOOK:
      look(myAvatar);
      break;
    // If the action is "take"
    case TAKE_ITEM:
      take(myAvatar, action->arg);
      break;
    // If the action is "drop"
    case DROP_ITEM:
      drop(myAvatar, action->arg);
      break;
    // If the action is "use"
    case USE_ITEM:
      use(myAvatar, action->arg);
      break;
    // If the action is "help"
    case HELP:
      print_help();
      break;
    }

    // Frees memory of the action
    free_action(action);
    // Get a new action
    action = get_action();
  }

  // The game is complete, free the level and avatar memory
  level_free(level, LEVEL_SIZE);
  avatar_free(myAvatar);
}

/*
 * Handles the look action
 *  
 * Prints room description, room inventory, and player inventory
 */
void look(struct Avatar *avatar)
{
  struct Room *currentRoom = get_avatar_current_room(avatar);

  // Print the room description, the items that are on the floor, and the items in the player's inventory
  printf("\n%s\n", get_room_description(currentRoom));
  printf("\nThe room contains:\n");
  item_print((get_room_items(currentRoom))->next);
  printf("\nIn your hands are:\n");
  item_print((get_avatar_items(avatar))->next);
}

/*
 * Handles the take action
 * 
 * checks if the item of the given name (itemName) is in the avatars current room
 * and adds it to the avatars inventory if it exist.
 */
void take(struct Avatar *avatar, char *itemName)
{

  struct Room *currentRoom = get_avatar_current_room(avatar);

  // Gets the item name entered from the room if it exists and removes it from the room
  struct Item *item = item_take(get_room_items(currentRoom), itemName);

  // If the item exists in the room
  if (item != NULL)
  {
    // Add the item into the players inventory and notify the player that the item has been added
    item_add(get_avatar_items(avatar), item);
    printf("\nYou pick up the %s.\n", item_name(item));
  }
  //Else notify the player that the item is not on the floor (doesn't exist)
  else
  {
    printf("That item is not on the floor.\n");
  }
}

/*
 * Handles the drop action
 * 
 * checks if the item of the given name (itemName) is in the avatars inventory
 * and adds it to the rooms inventory if it exist.
 */
void drop(struct Avatar *avatar, char *itemName)
{

  struct Room *currentRoom = get_avatar_current_room(avatar);

  // Take the given item name from the player's inventory
  struct Item *item = item_take(get_avatar_items(avatar), itemName);

  // If the item is found
  if (item != NULL)
  {
    // Place the item in the room and notify the player that the item has been dropped
    item_add(get_room_items(currentRoom), item);
    printf("\nYou drop the %s.\n", item_name(item));
  }
  // Else notify the player that the item was not found in the inventory
  else
  {
    printf("That item is not in your hands.\n");
  }
}

/*
 * Handles the take action
 * 
 * Checks if the item of the given name (itemName) is in the avatars inventory and is a valid key for the room.
 * If it is, it unlocks the door and deletes the item.
 * If it is not, it adds the item back into the players inventory.
 */
void use(struct Avatar *avatar, char *itemName)
{
  struct Room *currentRoom = get_avatar_current_room(avatar);

  // Get and remove the item from the players inventory
  struct Item *item = item_take(get_avatar_items(avatar), itemName);

  // If the item is found
  if (item != NULL)
  {
    // If the item matches the doors lock notify the palyer that the door is unlocked
    if (room_use_item(currentRoom, item))
    {
      printf("\nYou use the %s to open the door\n", item_name(item));

      // Free the items memory
      item_free(item);
    }
    // Else notify the player that the key is incorrect and add the item back into the player's inventory
    else
    {
      printf("\n%s did nothing\n", item_name(item));
      item_add(get_avatar_items(avatar), item);
    }
  }
  // Else if the item is not in the players inventory notify the player
  else
  {
    printf("That item is not in your hands.\n");
  }
}

/*
 * Handles the traverse
 * 
 * Checks if the players entered direction (arg) is a valid direction.
 *  If it is a valid direction and the room is unlocked and move the avatar
 */
void traverse(struct Avatar *myAvatar, char *arg)
{
  // Get the current room that the player is in
  struct Room *currentRoom = get_avatar_current_room(myAvatar);

  // Set the next room to null
  struct Room *nextRoom = NULL;

  // Declare the direction
  enum dir direction;

  // If the direction is "north"
  if (strcmp("north", arg) == 0)
  {
    // The next room is the room that is directly north
    nextRoom = get_room_exit(currentRoom, NORTH);
    // Set the direction
    direction = NORTH;
  }
  // If the direction is "south"
  else if (strcmp("south", arg) == 0)
  {
    // The next room is the room that is directly south
    nextRoom = get_room_exit(currentRoom, SOUTH);
    // Set the direction
    direction = SOUTH;
  }
  // If the direction is "east"
  else if (strcmp("east", arg) == 0)
  {
    // The next room is the room that is directly east
    nextRoom = get_room_exit(currentRoom, EAST);
    // Set the direction
    direction = EAST;
  }
  // If the direction is "west"
  else if (strcmp("west", arg) == 0)
  {
    // The next room is the room that is directly west
    nextRoom = get_room_exit(currentRoom, WEST);
    // Set the direction
    direction = WEST;
  }
  // If the direction is "up"
  else if (strcmp("up", arg) == 0)
  {
    // The next room is the room that is directly up
    nextRoom = get_room_exit(currentRoom, UP);
    // Set the direction
    direction = UP;
  }
  // If the direction is "down"
  else if (strcmp("down", arg) == 0)
  {
    // The next room is the room that is directly down
    nextRoom = get_room_exit(currentRoom, DOWN);
    // Set the direction
    direction = DOWN;
  }

  // If the next room has not been set
  if (nextRoom == NULL)
  {
    // Notify the player that there is no room in that direction
    printf("\nNo room in that direction.\n");
  }
  // Else if the door to the next room is locked
  else if (room_is_door_locked(currentRoom, direction))
  {
    // Notify the player that the room is locked
    printf("\nThat door is locked.\n");
  }
  // Else if the player is allowed to go in that direction
  else
  {
    // Set the players next room and notify them that the they reached the next room with the room description
    myAvatar->currentRoom = nextRoom;
    printf("\nYou walk in to the next room. \n%s\n", get_room_description(nextRoom));
  }
}

/*
 * Handles the help command
 * 
 * Prints valid commands and a description of them
 */
void print_help()
{
  // Prints the commands that the player can use throughout the game
  printf("\nHelp\n");
  printf("quit: Exits the game.\n");
  printf("go: Traverses your avatar to other rooms. Usage go {north, south, east, west, up, down}\n");
  printf("look: Displays room description, items in room, and items in your inventory.\n");
  printf("take: Takes an item from the room. Usage take ITEMNAME\n");
  printf("drop: Drops an item from your inventory on the ground. Usage drop ITEMNAME \n");
  printf("use: uses an item in your inventory to interact with the room. Usage use ITEMNAME\n");
}
