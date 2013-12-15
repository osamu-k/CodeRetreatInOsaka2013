#ifndef _LIFE_GAME_H_
#define _LIFE_GAME_H_

#include <map>

class LifeGame
{
public:
	LifeGame( int row, int col );
	~LifeGame();
	int isAlive( int row, int col );
	void setAlive( int row, int col, int value );
	int countAliveCellsAround( int row, int col );
	int isAliveNext( int row, int col );
	void next();
private:
	int _row;
	int _col;
	std::map<int, std::map<int, int> > _cells;
};

#endif

