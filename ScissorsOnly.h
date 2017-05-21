#include "PlayingStrategy.h"
#include "PlayerMove.h"

class ScissorsOnly : public PlayingStrategy
{
public:
	virtual PlayerMove getNextMove(PlayerMove lastEnemyMove, int lastResult) {
		return PlayerMove::rock;
	}
	virtual PlayerMove getFirstMove() {
		return PlayerMove::rock;
	}
	ScissorsOnly() {
		name = "ScissorsOnly";
	}
};


