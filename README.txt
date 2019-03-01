Zachary Polwrek, Oscar Vidal Rubio
    
    For this project we made a prison escape game. A player starts in an abandoned prison and is locked inside. The player 
must find keys and manuever through the prison in order to escape. 

Video Link: https://youtu.be/uufhvATD8Z0

*** Game Requirements ***
Your game must have at least 8 rooms.
    - adventure.c/.h -> build_level() -> The level has 16 rooms.

Your game must allow rooms to contain items.
    - room.c/.h -> The Room struct contains an items field which is a linked list of items

Your game must implement an avatar where the avatar has an inventory (a place to put items).
    - avatar.c/.h -> We have an avatar struct which holds an item feild which is a linked list of items
    - adventure.c/.h -> take() and drop() -> These functions allow interaction with the avatars inventory.

Your game must allow an avatar to “see” the room they are in with the command “look”.
    - adventure.c/.h -> look() -> Prints out an avatars current rooms items and description as well as the avatars inventory.
    
Your game must allow an avatar to move through each room using the command “go DIRECTION” where DIRECTION is a direction: north, south, east, west, up, down.
    - adventure.c/.h -> traverse() -> Allows the player to move a room from an other room taking consideration for locked doors.
    
Your game must allow an avatar to pick up items with the command “take ITEM” where ITEM is the name of an item in a room.
    - adventure.c/.h -> take() -> allows the player to take a item based on a string search through the current rooms inventory. Adds it to avatar inventory if it exists.
    
Your game must allow an avatar to use an item with the command “use ITEM” where ITEM is the name of an item in the avatars inventory. The effect of using an item depends on the room the avatar is in.
    - adventure.c/.h -> use() -> Checks if the player has the item they supplied. If they do, call room_use_item which unlocks any doors locked with that item. 
    - room.c/.h -> room_use_item() called when a player uses the use command and unlocks any doors that are locked with that item
    
You must implement at least one instance where an item alters the state of a room that the avatar is in.
    - adventure.c/.h -> Many of the rooms have lock doors that require an item to be used in a room to unlock it.
    - room.c/.h -> room_use_item() unlocks doors in the room its used in. If the item unlocked a door. The item is deleted.
                -> room_is_door_locked() checks if a door in a given room and direction is locked.
    
Your game must allow an avatar to drop an item with the command “drop ITEM” where ITEM is the name of an item in the avatars inventory.
    - adventure.c/.h -> drop() -> allows the player to drop an items based on a string search through the players inventory. Adds it to room inventory if it exists.

    
Your game must have a winning state (allowing the game to end).
    - adventure.c/.h -> play() -> when the end room is reached it exits the game loop and prints out the winning message. 
    
*** Code Requirements ***
You must use C structs in your code to represent various game objects.
    - Structs are used in many places 
        * avatar.h has an avatar struct with current room and inventory
        * rooms.h has a room struct with and inventory, description, and doors to other rooms
        * items.h has an item struct which contains item information an is also a linked list to support inventory.
        * input.h has a struct which contains the parsed user input data into easily useable format

    
You must use pointers in your code.
    - Pointers are used throughout and are in almost if not all functions.
    
You must use dynamic allocation in your code using malloc/calloc.
    - All of the structs mentioned above are dynamicly allocated when created with their "constructor" function
    
You must deallocate memory in your code using free.
    - adventure.c -> use() -> Item structs are deallocated when they are successfully used on a door
    - adventure.c -> play() -> Room, Avatar, and remaining Item structs are deallocated at the end of the game loop.