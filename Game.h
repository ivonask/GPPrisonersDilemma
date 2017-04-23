#ifndef game_h
#define game_h

#include "PlayingStrategy.h"
#include "PlayerMove.h"

class Game
{
public:
	Game(PlayingStrategy *ps) {
		strategy = ps;
	}
	~Game() {
	}

	virtual int play(int nMoves, TreeP tree, bool print) = 0;
	virtual int playMove(PlayerMove myMove, PlayerMove enemyMove)=0;

protected:
	PlayingStrategy *strategy;
};

#endif // !game_h