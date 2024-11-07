# 23I-2578
# Haseeb Arshad
# DS-A


# Player Management System - README
This project implements a PlayerBST class-based program to manage a player database using a Binary Search Tree (BST). Each player has associated games, allowing you to manage both players and the games they have played. This README file covers the complete functionality of the code, including explanations of each class, method, and necessary files.

Table of Contents
Overview
Classes and Structs
GamesPlayed
Player
PlayerBST
Program Functions
ins_pl - Insert Player
sav_play - Save Players
show_playe - Show Players
del_pla - Delete Player
pl_det - Player Details
alr_play - Check If Game Played
top_N - Top N Players by Games Played
sh_n_lay - Show N Layers of Tree
s_path - Search Path
Helper Functions
ins_pl_rec - Recursive Insert
del_pla_rec - Recursive Delete
func_min - Find Minimum Player
find_play - Find Player by ID
pre_order_save - Preorder Save
alr_play_rec - Recursive Game Check
tot_games - Total Games Display
sh_n_lay_rec - Show N Layers Recursively
s_path_rec - Search Path Recursively
Main Program Execution
Files Used
Players.csv
PlayersData.csv
Compiling and Running the Program
Code Walkthrough

# 1. Overview
The program creates a database of players where each player has basic attributes, such as ID, Name, Phone Number, Email, and Password. A player can also have games they've played, with each game having attributes like gameid, Ach_un (achievements unlocked), and hrs_pla (hours played). The players are stored in a binary search tree (BST), allowing for efficient insertion, deletion, and retrieval of players based on their IDs.

# 2. Classes and Structs
GamesPlayed Struct
The GamesPlayed struct represents a game that a player has played, with attributes for:

gameid: A unique string representing the game ID.
Ach_un: The number of achievements unlocked in the game.
hrs_pla: The number of hours the player has spent in the game.
Player Struct
The Player struct represents a player with attributes including:

Player_ID: The player's unique ID.
Name: Player’s name.
Phone_Number: Contact number.
Email: Email address.
Password: Game account password.
Games_Played: Pointer to the root node of a BST containing the games played by this player.
PlayerBST Class
The PlayerBST class manages the collection of players in a binary search tree. Its primary functionality is to provide methods to add, delete, search, save, and display players and their associated games.

# 3. Program Functions
Each function in the PlayerBST class performs a specific role, allowing interaction with the player and game databases.

ins_pl(Player *temp)
Inserts a new player node into the BST using the private helper function ins_pl_rec. If the player already exists (determined by the Player_ID), it skips the insertion.

sav_play(const string &fl)
Saves all players in the BST to a specified file using pre-order traversal. The output file, PlayersData.csv, will store each player’s information in a comma-separated format.

show_playe(const string &fl, int s_c)
Reads players from the specified file (Players.csv), inserting them into the BST if they meet certain conditions (random number check). Each line in the file represents a player's details, split by commas.

del_pla(const string &id)
Deletes a player by their ID. It uses the recursive helper function del_pla_rec to navigate the BST and remove the target node.

pl_det(const string &id)
Displays detailed information about a specific player, including their associated games and total achievements. This method also uses tot_games to show the games a player has played.

alr_play(const string &id_2, const string &id)
Checks if a particular player has already played a specific game by calling alr_play_rec. Returns true if the player has played the game, otherwise false.

top_N(int klg)
Displays the top N players based on the number of games they have played. (Not fully implemented)

sh_n_lay(int klg)
Displays up to N layers of the BST, showing each player in the current layer. Uses sh_n_lay_rec to handle recursion.

s_path(const string &id)
Displays the path from the root to the specified player in the BST. If the player is found, it prints "Found!", otherwise it prints "NOT found."

# 4. Helper Functions
Several private helper functions are used to assist in performing recursive operations.

ins_pl_rec(Player *NN, Player *pls)
Recursively inserts a player into the BST based on their ID.

del_pla_rec(Player *NN, const string &id)
Recursively searches and deletes a player node from the BST. Handles three cases: leaf node, one child, or two children (replacing with the in-order successor).

func_min(Player *NN)
Finds and returns the minimum node in a BST, used for finding the in-order successor.

find_play(const string &id)
Finds a player node by their ID. Uses find_play_rec for recursion.

pre_order_save(Player *NN, ofstream &fl)
Saves the BST to a file in pre-order traversal, storing each player in a comma-separated format.

alr_play_rec(GamesPlayed *NN, const string &id)
Recursively checks if a player has already played a specified game.

tot_games(GamesPlayed *NN)
Displays all games played by a player, including hours played and achievements unlocked.

sh_n_lay_rec(Player *NN, int cl, int num)
Recursively displays layers of the BST, limited by the specified layer number.

s_path_rec(Player *NN, const string &id)
Recursively finds and prints the path to a specific player in the BST.

# 5. Main Program Execution
The main function interacts with the user and demonstrates the functionalities of the PlayerBST class:

Player Data Insertion: Inserts sample players with IDs and credentials.
Details Display: Shows details of specific players, including their associated games.
Layer Display: Shows a specified number of layers in the BST.
Path Search: Finds and displays the path to a specific player.
Game Check: Checks if a player has played a specified game.
Player Deletion: Deletes a player by ID.
Data Saving: Saves the current BST to a file in pre-order format.

# 6. Files Used
Players.csv
The input file containing player details. Each line is structured as follows:

csv
Copy code
PlayerID,Name,Phone,Email,Password
This file should be present in the same directory as the program.

PlayersData.csv
The output file where player details are saved in pre-order traversal. This file is generated after calling sav_play.

Enter your roll number when prompted to generate a unique random number for skipping lines during file processing.

# 7. Code Walkthrough
The program's design is modular, with distinct classes for handling players and games, and a BST structure that supports efficient management operations. Here’s a quick walkthrough of each section of code:

Initialization:
GamesPlayed and Player structs define the data for each game and player.
PlayerBST Class:
Methods for managing the BST, including insert, delete, search, and display functionalities.
Main Program:
Interactively demonstrates the methods in PlayerBST through sample players and operations.

# What the output looks like

![image](https://github.com/user-attachments/assets/53d098a5-821d-45f0-8326-7b117a370b3d)

