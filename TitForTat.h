#include "PlayingStrategy.h"
#include "PlayerMove.h"

class TitForTat : public PlayingStrategy
{
public:
	virtual PlayerMove getNextMove(PlayerMove lastEnemyMove, int lastResult) {
		return lastEnemyMove;
	}
	virtual PlayerMove getFirstMove() {
		return PlayerMove::cooperation;
	}
	TitForTat() {
		name = "TitForTat";
	}
};

