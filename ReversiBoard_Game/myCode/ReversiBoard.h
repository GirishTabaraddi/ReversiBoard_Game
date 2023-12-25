/**
 * ReversiBoard.h
 *
 *  Created on: 14-Nov-2023
 *      Author: Girish
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

#include "ErrorCode.h"

//! A ReversiBoard Class
/*!
 * A class which representing a board with it's field being filled either by player 1 or player 2 color.
 * Here 2 colors will be taken as Black, White, noPawn and option for the empty field.
 * These states are represented in the form of enumeration.
 * Also, the class has 2 methods which implement the logic of the game.
 */
class ReversiBoard
{
private:
	int m_rows;		//!< an integer type class attribute for storing rows value.
	int m_columns;	//!< an integer type class attribute for storing columns value.
	char* m_board;	//!< Assigning a board of char pointer
public:
	/**
	 * A default constructor of the class ReversiBoard.
	 * It initializes the 2 attributes of the class i.e., Rows and Columns.
	 */
	ReversiBoard(int rows, int columns);

	/**
	 * A destructor to de-allocate the memory assigned to the board in this class.
	 */
	virtual ~ReversiBoard();

	//! An Enum
	/*!
	 * A enumeration is defined to represent the states of the board.
	 * We consider Black, White and noPawn as three states in this enum.
	 * @see field_state_t
	 */
	typedef enum
	{
		noStone,	//! noStone represents empty space in the board and the value in enum is 0.
		Black,		//! Black represents Black pawn in the board and the value in enum is 1.
		White,		//! White represents White pawn in the board and the value in enum is 2.
		Option,		//! option represents the available and valid field states to place the pawn and the value in enum is 3.
		Error		//! Error doesn't represent anything on the board, it may be used if we get any errors and enum value is 4.
	}field_state_t;

	//! A QueryFieldState method.
	/*!
	 * A method for the class to check the field's state
	 * @see QueryFieldState
	 * @return returns enum type i.e., noPawn/Black/White/Option depending on the status of the board.
	 */
	field_state_t QueryFieldState(int rows, int columns);

	//! A SetFieldState method.
	/*!
	 * A method to set the field states of the board with Players color i.e., Black/White.
	 * For the given position (rows, columns) the method should validate it and then place the respective pawn in that position.
	 * @see SetFieldState
	 * @param [in] rows this integer type variable holds the value of the user entered row.
	 * @param [in] columns this integer type variable holds the value of the user entered column.
	 * @param [in] player holds the each players color pawn i.e., Black or White, it depends on whose turn it is.
	 * @param [in] availableStatesArray which has the valid positions where a player can place his stone.
	 * @return returns RC_t type.
	 */
	RC_t SetFieldState(char player, int rows, int columns, int* availableStatesArray);

	//! A AvailableFieldStates method.
	/*!
	 * A method that calculates the valid position that a player can place his stone and stores the indices in an integer array.
	 * @param [in] player holds the each players color pawn i.e., Black or White, it depends on whose turn it is.
	 * return [out] it returns the valid indices as an integer array, which will be used by SetFieldState for it's functionality.
	 */
	int* AvailableFieldStates(char player);
};

#endif /* REVERSIBOARD_H_ */
