#include "CppUTest/TestHarness.h"

#include "CodeRetreat.h"
#include "LifeGame.h"

TEST_GROUP(CodeRetreat)
{
	LifeGame *game;
	
	void setup()
	{
		game = new LifeGame( 3, 3 );
	}

	void teardown()
	{
		delete game;
	}
};

TEST(CodeRetreat, IsAliveFalse)
{
	CHECK_EQUAL( 0, game->isAlive( 1, 1 ) );
}

TEST(CodeRetreat, IsAliveTrue)
{
	game->setAlive( 1, 1, 1 );
	CHECK_EQUAL( 1, game->isAlive( 1, 1 ) );
}

TEST(CodeRetreat, CountAliveCellsAround0 )
{
	CHECK_EQUAL( 0, game->countAliveCellsAround( 1, 1 ) );
}

TEST(CodeRetreat, CountAliveCellsAround1 )
{
	game->setAlive( 0, 0, 1 );
	CHECK_EQUAL( 1, game->countAliveCellsAround( 1, 1 ) );
}

TEST(CodeRetreat, CountAliveCellsAround1_RightBottom )
{
	game->setAlive( 2, 2, 1 );
	CHECK_EQUAL( 1, game->countAliveCellsAround( 1, 1 ) );
}

TEST(CodeRetreat, CountAliveCellsAround9 )
{
	game->setAlive( 0, 0, 1 );
	game->setAlive( 0, 1, 1 );
	game->setAlive( 0, 2, 1 );
	game->setAlive( 1, 0, 1 );
	game->setAlive( 1, 1, 1 );
	game->setAlive( 1, 2, 1 );
	game->setAlive( 2, 0, 1 );
	game->setAlive( 2, 1, 1 );
	game->setAlive( 2, 2, 1 );
	CHECK_EQUAL( 9, game->countAliveCellsAround( 1, 1 ) );
}

TEST(CodeRetreat, DeadToAlive)
{
	game->setAlive( 0, 0, 1 );
	game->setAlive( 0, 1, 1 );
	game->setAlive( 1, 0, 1 );
	CHECK_EQUAL( 1, game->isAliveNext( 1, 1 ) );
}

TEST(CodeRetreat, AliveToAlive)
{
	game->setAlive( 1, 1, 1 );
	game->setAlive( 1, 2, 1 );
	game->setAlive( 2, 1, 1 );
	game->setAlive( 2, 2, 1 );
	CHECK_EQUAL( 1, game->isAliveNext( 1, 1 ) );
}

TEST(CodeRetreat, AliveToDead)
{
	game->setAlive( 1, 1, 1 );
	game->setAlive( 1, 2, 1 );
	CHECK_EQUAL( 0, game->isAliveNext( 1, 1 ) );
}

TEST(CodeRetreat, AliveToDeadTooMany)
{
	game->setAlive( 0, 0, 1 );
	game->setAlive( 0, 1, 1 );
	game->setAlive( 0, 2, 1 );
	game->setAlive( 1, 0, 1 );
	game->setAlive( 1, 1, 1 );
	CHECK_EQUAL( 0, game->isAliveNext( 1, 1 ) );
}

TEST(CodeRetreat, NextStatusDeadToAlive)
{
	game->setAlive( 0, 0, 1 );
	game->setAlive( 0, 1, 1 );
	game->setAlive( 1, 0, 1 );
	game->next();
	CHECK_EQUAL( 1, game->isAliveNext( 0, 0 ) );
	CHECK_EQUAL( 1, game->isAliveNext( 0, 1 ) );
	CHECK_EQUAL( 0, game->isAliveNext( 0, 2 ) );
	CHECK_EQUAL( 1, game->isAliveNext( 1, 0 ) );
	CHECK_EQUAL( 1, game->isAliveNext( 1, 1 ) );
	CHECK_EQUAL( 0, game->isAliveNext( 1, 2 ) );
	CHECK_EQUAL( 0, game->isAliveNext( 2, 0 ) );
	CHECK_EQUAL( 0, game->isAliveNext( 2, 1 ) );
	CHECK_EQUAL( 0, game->isAliveNext( 2, 2 ) );
}

