#include "PlayingStrategy.h"
#include "PlayerMove.h"

class AlternatingMoves : public PlayingStrategy
{
public:
	virtual PlayerMove getNextMove(PlayerMove lastEnemyMove, int lastResult) {
		if (myLastMove == PlayerMove::cooperation) {
			myLastMove = PlayerMove::treason;
			return PlayerMove::treason;
		}
		else {
			myLastMove = PlayerMove::cooperation;
			return PlayerMove::cooperation;
		}
	}
	virtual PlayerMove getFirstMove() {
		myLastMove = PlayerMove::cooperation;
		return PlayerMove::cooperation;
	}
	AlternatingMoves() {
		name = "AlternatingMoves";
	}
private:
	PlayerMove myLastMove;
};


