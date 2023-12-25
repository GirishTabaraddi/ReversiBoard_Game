/**
 * ReversiBoard.cpp
 *
 *  Created on: 14-Nov-2023
 *      Author: Girish
 */
#include <iostream>
#include "ReversiBoard.h"

using namespace std;

ReversiBoard::ReversiBoard(int rows, int columns)
{
	this->m_rows = rows; 				//!< we are initializing the private attribute m_Rows with the value stored in rows.
	this->m_columns = columns; 			//!< we are initializing the private attribute m_Columns with the value stored in columns.
	m_board = new char[rows * columns]; //!< Initializing the board attribute of char type to have dynamically allocated memory of row*column size.

	//!< For all the fields of the board with size row*column, we are placing '.' in these fields.
	for(int i = 0; i < rows*columns; i++)
	{
		m_board[i] = '.';
	}

	//! As per the Reversi game rules, the middle 4 positions in the Board are added with 2 Black and White stones each.
	m_board[27]	=	'B';
	m_board[28]	=	'W';
	m_board[35]	=	'W';
	m_board[36]	=	'B';

//	m_board[21] = 'W';
//	m_board[29] = 'B';
//	m_board[34] = 'B';
//	m_board[42] = 'W';
//	m_board[43] = 'B';
}

ReversiBoard::~ReversiBoard()
{
	delete[] m_board;
}

ReversiBoard::field_state_t ReversiBoard::QueryFieldState(int rows, int columns)
{
	//!<The following logic calculates the index of the given rows, columns.
	int index = rows * m_columns + columns;

	if(m_board[index] == '.')
		return noStone;
	else if(m_board[index] == 'o')
		return Option;
	else if(m_board[index] == 'B')
		return Black;
	else if(m_board[index] == 'W')
		return White;
	else
		return Error;
}

RC_t ReversiBoard::SetFieldState(char player, int rows, int columns, int* availableStatesArray)
{
//	for(int i = 0; availableStatesArray[i] != 0; i++)
//	{
//		cout << "Available indices @ Start: " << availableStatesArray[i] << endl;
//	}
	RC_t ret;

	//! An array to store all the positions where I have to flip them to current player stone.
	int* flip_array = new int[m_rows * m_columns]();

	//! An int value as index to write the values into the array.
	int flip_array_index = 0;

	bool no_stones = true;

	//! Position where the stone has to be placed
	int entered_index = (rows * m_columns) + columns;

	//! For loop to check if the entered position is in availablStatesArray,
	//! If yes, then check for the opposite pawn in the adjacent positions and perform the reversi logic.

	for(int array_idx = 0; availableStatesArray[array_idx] != 0; array_idx++)
	{
		if(entered_index == availableStatesArray[array_idx])
		{
			for(int i = rows-1; i < rows+2; i++)
			{
				for(int j = columns-1; j < columns+2; j++)
				{
					if((QueryFieldState(i, j) == White && player == 'B') ||
					   (QueryFieldState(i, j) == Black && player == 'W'))
					{
						int opp_stone_idx = i * m_columns + j;
						flip_array[flip_array_index++] = opp_stone_idx;

						//cout << opp_stone_idx << endl;

						int dx = i - rows;
						int dy = j - columns;

						for (int m = i + dx, n = j + dy; (m >= 0 && m < 8) && (n >= 0 && n < 8); m = m + dx, n = n + dy)
						{
							//cout << "m,n: " << m << "," << n << endl;
							//cout << "i,j: " << i << "," << j << endl;
							if((QueryFieldState(m,n) == Black && player == 'B') ||
							   (QueryFieldState(m,n) == White && player == 'W'))
							{
								no_stones = false;

								m_board[entered_index] = player;

								//! flip array stores the positions of pawns
								for(int k = 0; flip_array[k] != 0; k++)
								{
//									cout << "flip these: " << flip_array[k] << endl;
									m_board[flip_array[k]] = player;
									flip_array[k] = 0;	//! Reset the flip array to 0, to not flip invalid stones.
								}
								flip_array_index = 0;	//! Set index back to =, so that next array item will written on 0th index
								break;
							}
							else if((QueryFieldState(m, n) == White && player == 'B') ||
									(QueryFieldState(m, n) == Black && player == 'W'))
							{
								opp_stone_idx = m * m_columns + n;
								flip_array[flip_array_index++] = opp_stone_idx;
								continue;
							}
							else if((QueryFieldState(m,n) == noStone && player == 'B') ||
									(QueryFieldState(m,n) == noStone && player == 'W') ||
									(QueryFieldState(m,n) == Option && player == 'B') ||
									(QueryFieldState(m,n) == Option && player == 'W'))
							{
								for(int k = 0; flip_array[k] != 0; k++)
								{
									//cout << "delete these: " << flip_array[k] << endl;
									flip_array[k] = 0;
								}
								flip_array_index = 0;
								break;
							}
							else
							{
								ret = RC_INVALID_MOVE;
							}
						}
					}
					else if(QueryFieldState(i, j) == noStone && no_stones == true)
					{
						ret = RC_NO_STONE;
						continue;
					}
				} //! end of for loop j
			} //! end of for loop i
			ret = RC_OK;
		}
		else
		{
			m_board[availableStatesArray[array_idx]] = '.'; //! Set the other indices in the array to noStone.
			ret = RC_STATE_UNAVAILABLE;
			continue;
		}
	}
	return ret;
}

int* ReversiBoard::AvailableFieldStates(char player)
{
	int current_index = 0;

	//! Result array to store the indices that are valid positions to flip.
	int* result = new int[m_rows * m_columns]();

	//! resultIndex to hover over the array to write the values.
	int resultIndex = 0;

	for(int rows = 0; rows < m_rows; rows++)
	{
		for(int columns = 0; columns < m_columns; columns++)
		{
			//cout << rows << " " << columns << endl;

			if((QueryFieldState(rows, columns) == Black && player == 'B') ||
					(QueryFieldState(rows, columns) == White && player == 'W'))
			{
				int StonePos = (rows * m_columns) + columns;

				for(int i = -1; i < 2; i++)
				{
					for(int j = -1; j < 2; j++)
					{
						current_index = ((rows + i) * m_columns) + (columns + j);

						if(StonePos == current_index)
						{
							continue;
						}
						else
						{
							int idx1 = rows+i;
							int idx2 = columns+j;

							//cout << "here: " << idx1 << " " << idx2 << endl;

							if((QueryFieldState(idx1, idx2) == White && player == 'B') ||
									(QueryFieldState(idx1, idx2) == Black && player == 'W'))
							{
								//cout << index << endl;
								//cout << "i,j: " << i << " " << j << endl;
								//cout << "W pos: " << idx1 << " " << idx2 << endl;
								bool flag = false;

								for(int m = idx1 + i, n = idx2 + j; (m >= 0 && m < 8) && (n >= 0 && n < 8); m = m + i, n = n + j)
								{
									if((QueryFieldState(m, n) == noStone && flag == false))
									{
										//cout << idx1+i << " " << idx2+j << endl;
										int empty_pos = ((m) * m_columns) + (n);
										//cout << empty_pos << endl;
										if(m_board[empty_pos] == '.')
										{
											m_board[empty_pos] = 'o';

											result[resultIndex++] = empty_pos;
											flag = true;
										}

										continue;
									}
									else if((QueryFieldState(m, n) == White && player == 'W') ||
											(QueryFieldState(m, n) == Black && player == 'B'))
									{
										break;
									}
									else
									{
										continue;
									}
								}
							}
							else
							{
								continue;
							}
						}
					} //! end of for loop j
				} //! end of for loop i
			}
			else
			{
				continue;
			}
		} //! end of for loop columns
	} //! end of for loop rows
    result[resultIndex] = 0;

    return result;
}
