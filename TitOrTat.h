#include "PlayingStrategy.h"
#include "PlayerMove.h"

class TitOrTat : public PlayingStrategy
{
public:
	virtual PlayerMove getNextMove(PlayerMove lastEnemyMove) {
		return lastEnemyMove;
	}
	virtual PlayerMove getFirstMove() {
		return PlayerMove::cooperation;
	}
	TitOrTat() {
		name = "TitOrTat";
	}
};

