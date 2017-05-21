#include "PlayingStrategy.h"
#include "PlayerMove.h"
#include "Game.h"

class RockPaperScissors : public Game 
{
public:
	RockPaperScissors(PlayingStrategy *ps) : Game(ps) {
	}
	virtual int play(int nMoves, TreeP tree, bool print) {
		PlayerMove myMove = (PlayerMove)(rand() % 3 + 1);
		PlayerMove enemyMove = strategy->getFirstMove();

		int myResult = playMove(myMove, enemyMove);

		std::stringstream myMoves, enemyMoves, round, res;
		if (print) {
			std::cout << "Playing against: \"" << strategy->getName() << "\"\n";
			myMoves << "My moves:     " << sh(myMove);
			enemyMoves << "Enemy moves:  " << sh(enemyMove);
			round << "Round:        0";
			res << "Result:       " << myResult;
		}

		int sum = myResult;
		int enemySum = enemyResult(myResult);

		//OSNOVNI PARAMETRI
		//x = moj zadnji potez
		//y = protivnicki zadnji potez
		//z = moji bodovi

		//DODATNI PARAMETRI
		//n = broj poteza do kraja



		for (int i = 0; i < nMoves; i++) {
			tree->setTerminalValue("x", &myMove);
			tree->setTerminalValue("y", &enemyMove);
			tree->setTerminalValue("z", &myResult);

			int nEnd = nMoves - i;
			tree->setTerminalValue("n", &nEnd);

			double result;
			tree->execute(&result);

			enemyMove = strategy->getNextMove(myMove, enemyResult(myResult));

			//*********************DEKODIRANJE***********************

			if (result <= abs(1)) {
				myMove = PlayerMove::paper;
			}
			else if (result > 1000) {
				myMove = PlayerMove::scissors;
			}
			else {
				myMove = PlayerMove::rock;
			}
			//*********************DEKODIRANJE***********************

			myResult = playMove(myMove, enemyMove);
			sum += myResult;

			if (print) {
				myMoves << " " << sh(myMove);
				enemyMoves << " " << sh(enemyMove);
				round << " " << i + 1;
				res << " " << myResult;

				enemySum += enemyResult(myResult);
			}
		}
		if (print) {
			std::cout << round.str() << endl;
			std::cout << myMoves.str() << "  sum: " << sum << endl;
			std::cout << enemyMoves.str() << "  sum: " << enemySum << endl;
			std::cout << res.str() << endl << endl;
		}
		return sum;
	}
	int playMove(PlayerMove myMove, PlayerMove enemyMove) override {
		switch (myMove)
		{
		case PlayerMove::rock:
			switch (enemyMove)
			{
			case PlayerMove::rock:
				return 1;
			case PlayerMove::paper:
				return 0;
			case PlayerMove::scissors:
				return 3;
			}
			break;
		case PlayerMove::paper:
			switch (enemyMove)
			{
			case PlayerMove::rock:
				return 3;
			case PlayerMove::paper:
				return 1;
			case PlayerMove::scissors:
				return 0;
			}
			break;
		case PlayerMove::scissors:
			switch (enemyMove)
			{
			case PlayerMove::rock:
				return 0;
			case PlayerMove::paper:
				return 3;
			case PlayerMove::scissors:
				return 1;
			}
			break;
		}
	}
	static int enemyResult(int res) {
		switch (res)
		{
		case 0:
			return 3;
			break;
		case 1:
			return 1;
			break;
		case 3:
			return 0;
			break;
		}
	}

	static string sh(PlayerMove move) {
		switch (move)
		{
		case PlayerMove::rock:
			return "R";
			break;
		case PlayerMove::paper:
			return "P";
			break;
		case PlayerMove::scissors:
			return "S";
			break;
		}
	}
};