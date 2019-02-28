Zachary Polwreck, Oscar Vidal Rubio
    
    For this project we made a prison escape game. A player starts in an abandoned prison and is locked inside. The player 
must find keys and manuever through the prison in order to escape. 

    The program itself is broken up into ten files: adventure.c, avatar.c, avatar.h, input.c, input.h, items.c, items.h,
Makefile, rooms.c, and rooms.h. The adventure.c file is the file that includes main and as the title suggests it is the
adventure. It includes the functions:
    1) play(): Creates the player and their inventory and is the function that essentially builds the game
    2) build_level(): builds all of the rooms along with the keys
    3) traverse(): Changes the room that the player is in when they choose to travel in a given direction
    4) print_help(): Prints an instruction menu to help the player when they get stuck
The avatar.c file includes the functions:
    1) avatar(): returns a poitner to an avatar struct 
    2) free_avatar(): frees the allocated memory of an avatar struct
    3) set_avatar_current_room(): Sets the current room of the avatar
    4) set_avatar_items(): Sets the avatar's inventory
    5) get_avatar_current_room(): Returns a pointer to the current room that the avatar is in
    6) get_avatar_items(): Returns a pointer to the avatar's inventory
The avatar.h file contaions the Avatar struct and the protoypes of the functions that the avatar.c file will use.
The input.c file contains the functions:
    1) get_action(): Creates an action stuct and returns a pointer to that struct.
    2) free_action(): Frees the memory allocated to an action struct.
    3) get_action_type(): Returns the action type of the action struct (go, look, help, drop, take, use, or quit).
    4) get_action_arg(): Returns a pointer to the player's second argument
The input.h file contains an enumeration for the action types, the Action struct, and the protoypes that input.c 
file will use.
The items.c file contains the functions:
    1) item(): Creates and resturns an item struct.
    2) item_name(): Returns a pointer of the name of a given item.
    3) item_description(): Returns a pointer of the description of a given item.
    4) item_next(): Returns a pointer to the next item in the player's inventory.
    5) item_print(): Iterates through the player's inventory and prints each item.
    6) item_take(): Removes a given item from the player's inventory.
    7) item_add(): Adds a given item to the player's inventory.
The items.h file contains the Item struct and the protoypes of the functions that the items.c file will use.
The Makefile compiles the files that will be used in the program.
The room.c file contains the functions:
    1) room(): Creates a room struct and returns a pointer to it.
    2) free_room(): Frees the allocated memory of a room struct.
    3) set_room_exit_north(): Sets the north exit of a room.
    4) set_room_exit_south(): Sets the south exit of a room.
    5) set_room_exit_east(): Sets the east exit of a room.
    6) set_room_exit_west(): Sets the west exit of a room.
    7) set_room_exit_up(): Sets the up exit of a room.
    8) set_room_exit_down(): Sets the down exit of a room.
    9) set_room_exit(): Sets the exit of a room in the correct direction.
    10) get_room_exit(): Returns a pointer to the exit of a room in a given direction.
    11) room_lock_door(): Sets the lock of a door.
    12) room_use_item(): Returns if the door is given the correct key.
    13) room_is_door_locked(): Returns if the door is locked.
    14) get_room_description(): Returns a pointer to a given room's description.
    15) get_room_items(): Returns a pointer to the room's items.
The rooms.h file contains an enumeration of the directions, the Room struct and the prototypes of the functions that 
the rooms.c file will use.

A more detailed view of the functions can be found in the comments within the program.

Video Link: 