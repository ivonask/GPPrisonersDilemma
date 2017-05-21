#include "PlayingStrategy.h"
#include "PlayerMove.h"

class TitForTwoTats : public PlayingStrategy
{
public:
	virtual PlayerMove getNextMove(PlayerMove lastEnemyMove, int lastResult) {
		if (enemyDefect) {
			if (lastEnemyMove==PlayerMove::treason)
			{
				return PlayerMove::treason;
			}
			else
			{
				enemyDefect = false;
				return PlayerMove::cooperation;
			}
		}
		else
		{
			if (lastEnemyMove == PlayerMove::treason)
			{
				enemyDefect = true;
			}
			return PlayerMove::cooperation;
		}
	}
	virtual PlayerMove getFirstMove() {
		return PlayerMove::cooperation;
	}
	TitForTwoTats() {
		name = "TitForTwoTats";
	}
private:
	bool enemyDefect = false;
};

