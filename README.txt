    For this project we made a prison escape game. A player starts in an abandoned prison and is locked inside. The player 
must find keys and manuever through the prison in order to escape. 

    The program itself is broken up into ten files: adventure.c, avatar.c, avatar.h, input.c, input.h, items.c, items.h,
Makefile, rooms.c, and rooms.h. The adventure file is the file that includes main and as the title suggests it is the
adventure. It includes the functions:
    1) play(): Creates the player and their inventory and is the function that essentially builds the game
    2) build_level(): builds all of the rooms along with the keys
    3) traverse(): Changes the room that the player is in when they choose to travel in a given direction
    4) print_help(): Prints an instruction menu to help the player when they get stuck
The avatar file includes the functions:
    1) avatar(): returns a poitner to an avatar struct 
    2) free_avatar(): frees the allocated memory of an avatar struct
    3) set_avatar_current_room(): Sets the current room of the avatar
    4) set_avatar_items(): Sets the avatar's inventory
    5) get_avatar_current_room(): Returns a pointer to the current room that the avatar is in
    6) get_avatar_items(): Returns a pointer to the avatar's inventory
