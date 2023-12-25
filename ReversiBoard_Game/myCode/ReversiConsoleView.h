/**
 * ReversiConsoleView.h
 *
 *  Created on: 14-Nov-2023
 *      Author: Girish
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"

//! A ReversiConsoleView Class
/*!
 * A class to print the board on the console.
 *
 */
class ReversiConsoleView
{
private:
	int m_rows;				//!< Declaring m_Rows attribute of type integer which will hold value of the entered rows.
	int m_columns;			//!< Declaring m_Columns attribute of type integer which will hold value of the entered columns.
	ReversiBoard* m_board;	//!< Declaring the attribute m_board as a pointer of the type ReversiBoard.
public:
	//! A ReversiConsoleView parameterized constructor.
	/*!
	 * A default constructor for initializing the private attributes of the class ReversiConsoleView.
	 * Here we are passing the pointer of class ReversiBoard as instance to the constructor of this class as parameter.
	 */
	ReversiConsoleView(ReversiBoard* RBObj, int rows, int columns);

	//! A PrintBoard method.
	/*!
	 * A method that uses the pointer to obtain the states of the created board and prints the output on the console.
	 * @return void type
	 */
	void PrintBoard();
};

#endif /* REVERSICONSOLEVIEW_H_ */
