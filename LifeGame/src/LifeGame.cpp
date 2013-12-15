#include "LifeGame.h"

LifeGame::LifeGame( int row, int col )
: _row( row )
, _col( col )
{
	(void)_row;
	(void)_col;
}

LifeGame::~LifeGame()
{
}

int LifeGame::isAlive( int row, int col )
{
	return _cells[row][col];
}

void LifeGame::setAlive( int row, int col, int value )
{
	_cells[row][col] = value;
}

int LifeGame::countAliveCellsAround( int row, int col )
{
	int count = 0;
	for( int r = row - 1; r <= row + 1; r++ ){
		for( int c = col - 1; c <= col + 1; c++ ){
			count += isAlive( r, c );
		}
	}
	return count;
}

int LifeGame::isAliveNext( int row, int col )
{
	static int nextStatus[] = { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 };
	int count = countAliveCellsAround( row, col );
	return nextStatus[count];
}

void LifeGame::next()
{
	std::map<int, std::map<int, int> > nextCells;
	for( int r = 0; r < _row; r ++ ){
		for( int c = 0; c < _col; c ++ ){
			nextCells[r][c] = isAliveNext( r, c );
		}
	}
	_cells = nextCells;
}

