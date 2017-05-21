#include "PlayingStrategy.h"
#include "PlayerMove.h"

class SuspiciousTitForTat : public PlayingStrategy
{
public:
	virtual PlayerMove getNextMove(PlayerMove lastEnemyMove, int lastResult) {
		return lastEnemyMove;
	}
	virtual PlayerMove getFirstMove() {
		return PlayerMove::treason;
	}
	SuspiciousTitForTat() {
		name = "SuspiciousTitForTat";
	}
};
