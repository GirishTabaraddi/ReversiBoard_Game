//! Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>

using namespace std;

//! Add your project's header files here
#include "ReversiConsoleView.h"
#include "ErrorCode.h"

/*!
 * \fn RC_t ProcessPlayerMove(ReversiBoard& gameboard, ReversiConsoleView& displaygameboard, char player)
 * \brief ProcessPlayMove function takes objects of classes as input and player type to process the available states and setting the valid position.
 * \param [in] gameboard
 */
RC_t ProcessPlayerMove(ReversiBoard& gameboard, ReversiConsoleView& displaygameboard, char player);

// Main program
int main ()
{
	cout << "ReversiBoard_Game started." << endl << endl;

	//! Creating an object BoardGame for the class ReversiBoard and passing size for rows, columns. Here it is standard value 8.
	ReversiBoard GameBoard(8, 8);

	//! To the BoardGamePrint object of the ReversiConsoleview, we are passing the address of the BoardGame and the rows, columns.
	ReversiConsoleView DisplayGameBoard(&GameBoard, 8, 8);

	//! Declaring a ret variable which stores the error returned from the logic. It is used for error handling in this main function.
	RC_t ret = RC_INIT;

	//! Set the Initial Player1 with Black Pawn.
	char player = 'B';

	//! Set a flag to false. This is because when we have error, we need the same player to play again.
	bool play_again_flag = false;

	//! Set the Valid moves to 64, as this is 8x8 board game, there are only 64 valid moves.
	int Total_Valid_Moves = 60;

	//! Run the game until all the 64 fields of the board are filled by either White or Black.
	//! Count the no of pawns to display the winner with highest no of pawns on the board.
	do
	{
		//! Switch loop is used to toggle between the two players.
		switch (player)
		{
		case 'B':
		{
			ret = ProcessPlayerMove(GameBoard, DisplayGameBoard, player);
			break;
		}

		case 'W':
		{
			ret = ProcessPlayerMove(GameBoard, DisplayGameBoard, player);
			break;
		}
		default:
			break;
		}

		if(ret == RC_STONE_AVAILABLE)
		{
			cout << "STONE_AVAILABLE: Oops! Entered (row, column) already has a B/W Stone." << endl;
			play_again_flag = true;
		}
		else if(ret == RC_INVALID_MOVE)
		{
			cout << "INVALID_MOVE: Oops! Entered wrong (row, column)." << endl;
			play_again_flag = true;
		}
		else if(ret == RC_BADPARAM)
		{
			cout << "BADPARAM: You have entered a out of boundary (row, column)" << endl;
			play_again_flag = true;
		}

		//! Since the initial player is set to one color, the next round should be the opposite color.
		//! So, if player is B in the one loop, in the next player will be W.

		if (play_again_flag) {
		    //! If play_again_flag is true, keep the same player and reset the flag
		    play_again_flag = false;
		} else {
		    //! If play_again_flag is false, switch to the other player and decrement total valid moves
		    player = (player == 'B') ? 'W' : 'B';
		    Total_Valid_Moves -= 1;
		}

		cout << "valid moves remaining: " << Total_Valid_Moves << endl;
	}
	while(Total_Valid_Moves != 0);


	return 0;
}

RC_t ProcessPlayerMove(ReversiBoard& gameboard, ReversiConsoleView& displaygameboard, char player)
{
	RC_t ret = RC_INIT;

	int* available_states_array = gameboard.AvailableFieldStates(player);

	displaygameboard.PrintBoard();

	cout << "Player1: Enter the (row,column) to insert the Stone - "
			<< player << ":  " << endl;

	//! These are the local rows, columns that will be taken from the user.
	int rows = 0, columns = 0;

	cout << "enter b rows, b cols" <<endl;
	cin >> rows;
	cin >> columns;

	int entered_index = (rows * 8) + columns;

	bool valid_move = false;

	if((rows < 0 || rows > 8) || (columns < 0 || columns > 8))
	{
		ret = RC_BADPARAM;
	}
	else
	{
		for(int array_idx = 0; available_states_array[array_idx] != 0; array_idx++)
		{
			if(entered_index == available_states_array[array_idx])
			{
				valid_move = true;
				ret = gameboard.SetFieldState(player, rows, columns, available_states_array);
			}
			else if(valid_move == false)
			{
				ret = RC_INVALID_MOVE;
			}
		}
	}

	return ret;
}
