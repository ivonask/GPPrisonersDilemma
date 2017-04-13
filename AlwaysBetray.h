#include "PlayingStrategy.h"
#include "PlayerMove.h"

class AlwaysBetray : public PlayingStrategy
{
public:
	virtual PlayerMove getNextMove(PlayerMove lastEnemyMove) {
		return PlayerMove::treason;
	}
	virtual PlayerMove getFirstMove() {
		return PlayerMove::treason;
	}
	AlwaysBetray() {
		name = "AlwaysBetray";
	}
};
