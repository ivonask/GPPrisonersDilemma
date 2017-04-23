#include "PlayingStrategy.h"
#include "PlayerMove.h"
#include "Game.h"

class PrisonersDilemma : public Game
{
public:
	PrisonersDilemma(PlayingStrategy *ps) : Game (ps) {
	}

	virtual int play(int nMoves, TreeP tree, bool print) {
		PlayerMove myMove = (PlayerMove)(rand() % 2 + 1);
		PlayerMove enemyMove = strategy->getFirstMove();

		int myResult = playMove(myMove, enemyMove);

		std::stringstream myMoves, enemyMoves, round, res;
		if (print) {
			myMoves << "My moves:     " << (int)myMove;
			enemyMoves << "Enemy moves:  " << (int)enemyMove;
			round << "Round:        0";
			res << "Result:       " << myResult;
		}

		int sum = myResult;
		int enemySum = enemyResult(myResult);

		//x = moj zadnji potez
		//y = protivnicki zadnji potez
		//z = moji bodovi

		for (int i = 0; i < nMoves; i++) {
			tree->setTerminalValue("x", &myMove);
			tree->setTerminalValue("y", &enemyMove);
			tree->setTerminalValue("z", &myResult);

			double result;
			tree->execute(&result);

			enemyMove = strategy->getNextMove(myMove);

			if (result > abs(1)) {
				myMove = PlayerMove::cooperation;
			}
			else {
				myMove = PlayerMove::treason;
			}

			myResult = playMove(myMove, enemyMove);
			sum += myResult;

			if (print) {
				myMoves << " " << (int)myMove;
				enemyMoves << " " << (int)enemyMove;
				round << " " << i + 1;
				res << " " << myResult;

				enemySum += enemyResult(myResult);
			}
		}
		if (print) {
			std::cout << round.str() << endl;
			std::cout << myMoves.str() << "  sum: " << sum << endl;
			std::cout << enemyMoves.str() << "  sum: " << enemySum << endl;
			std::cout << res.str() << endl;
		}

		return sum;
	}

	int playMove(PlayerMove myMove, PlayerMove enemyMove) {
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
};