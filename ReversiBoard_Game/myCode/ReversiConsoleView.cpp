/*
 * ReversiConsoleView.cpp
 *
 *  Created on: 14-Nov-2023
 *      Author: giris
 */
#include <iostream>
#include "ReversiConsoleView.h"

using namespace std;

/**
 * A default constructor for initializing the private attributes of the class ReversiConsoleView.
 * Here we are passing the pointer of class ReversiBoard as instance to the constructor of this class as parameter.
 */
ReversiConsoleView::ReversiConsoleView(ReversiBoard *RBObj, int rows,
		int columns)
{
	this->m_rows = rows;
	this->m_columns = columns;
	this->m_board = RBObj;
}

/**
 * A method that uses the pointer to obtain the states of the created board and prints the output on the console.
 * if the field state is option - prints 'o', noPawn - '.', Black - 'B' and White - 'W'.
 * @return void type
 */
void ReversiConsoleView::PrintBoard()
{


	cout << "x 0 1 2 3 4 5 6 7" << endl;

	for(int i = 0; i < m_columns; i++)
	{
		cout << i << " ";
		for(int j = 0; j < m_columns; j++)
		{
			if(m_board->QueryFieldState(i,j) == ReversiBoard::noStone)
				cout << ". ";
			else if(m_board->QueryFieldState(i,j) == ReversiBoard::Option)
				cout << "o ";
			else if(m_board->QueryFieldState(i,j) == ReversiBoard::Black)
				cout << "B ";
			else if(m_board->QueryFieldState(i,j) == ReversiBoard::White)
				cout << "W ";
		}
		cout << endl;
	}
}
