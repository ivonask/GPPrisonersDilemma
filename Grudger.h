#include "PlayingStrategy.h"
#include "PlayerMove.h"

class Grudger : public PlayingStrategy
{
public:
	virtual PlayerMove getNextMove(PlayerMove lastEnemyMove, int lastResult) {
		if (lastEnemyMove == PlayerMove::treason) {
			enemyDefect = true;
		}
		if (enemyDefect) {
			return PlayerMove::treason;
		}
		else {
			return PlayerMove::cooperation;
		}
	}
	virtual PlayerMove getFirstMove() {
		return PlayerMove::cooperation;
	}
	Grudger() {
		name = "Grudger";
	}
private:
	bool enemyDefect = false;
};


