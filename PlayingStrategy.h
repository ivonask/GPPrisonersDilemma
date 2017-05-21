#ifndef playing_strategy_h
#define playing_strategy_h

#include "PlayerMove.h"

class PlayingStrategy {
public:
	virtual PlayerMove getNextMove(PlayerMove lastEnemyMove, int lastResult) = 0;
	virtual PlayerMove getFirstMove() = 0;
	virtual char* getName() {
		return name;
	}
protected:
	char* name;
};

#endif // !player_move_h
