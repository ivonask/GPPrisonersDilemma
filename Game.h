#include "PlayingStrategy.h"
#include "PlayerMove.h"

class Game
{
public:
	Game(PlayingStrategy *ps) {
		strategy = ps;
	}
	~Game() {
	}

	static int playMove(PlayerMove myMove, PlayerMove enemyMove) {
		int myResult = 0;
		switch (myMove)
		{
		case PlayerMove::treason:
			switch (enemyMove)
			{
			case PlayerMove::treason:
				myResult += 1;
				break;
			case PlayerMove::cooperation:
				myResult += 5;
				break;
			}
			break;
		case PlayerMove::cooperation:
			switch (enemyMove)
			{
			case PlayerMove::treason:
				myResult += 0;
				break;
			case PlayerMove::cooperation:
				myResult += 3;
				break;
			}
			break;
		//default:
			/*cout << "greska!";
			exit(1);*/
		}
		return myResult;
	};

	static int enemyResult(int res) {
		switch (res)
		{
		case 0:
			return 5;
			break;
		case 1:
			return 1;
			break;
		case 3:
			return 3;
			break;
		case 5:
			return 0;
			break;
		}
	}

private:
	PlayingStrategy *strategy;
};