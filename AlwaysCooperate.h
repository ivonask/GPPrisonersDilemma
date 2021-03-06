#include "PlayingStrategy.h"
#include "PlayerMove.h"

class AlwaysCooperate : public PlayingStrategy
{
public:
	virtual PlayerMove getNextMove(PlayerMove lastEnemyMove, int lastResult) {
		return PlayerMove::cooperation;
	}
	virtual PlayerMove getFirstMove() {
		return PlayerMove::cooperation;
	}
	AlwaysCooperate() {
		name = "AlwaysCooperate";
	}
};
