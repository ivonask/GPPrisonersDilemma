#include "PlayingStrategy.h"
#include "PlayerMove.h"

class Pavlov : public PlayingStrategy
{
public:
	virtual PlayerMove getNextMove(PlayerMove lastEnemyMove, int lastResult) {
		if (lastResult >= 3) {
			return myLastMove;
		}
		else {
			switch (myLastMove)
			{
			case PlayerMove::cooperation:
				myLastMove = PlayerMove::treason;
				return PlayerMove::treason;
			case PlayerMove::treason:
				myLastMove = PlayerMove::cooperation;
				return PlayerMove::cooperation;
			}
		}	
	}
	virtual PlayerMove getFirstMove() {
		myLastMove = PlayerMove::cooperation;
		return PlayerMove::cooperation;
	}
	Pavlov() {
		name = "Pavlov";
	}
private:
	PlayerMove myLastMove;
};


