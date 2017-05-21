#include "PlayingStrategy.h"
#include "PlayerMove.h"

class TitForTatRPS : public PlayingStrategy
{
public:
	virtual PlayerMove getNextMove(PlayerMove lastEnemyMove, int lastResult) {
		return lastEnemyMove;
	}
	virtual PlayerMove getFirstMove() {
		return PlayerMove::rock;
	}
	TitForTatRPS() {
		name = "TitForTat";
	}
};


