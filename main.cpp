#include <ECF/ECF.h>
#include "PrisDilemmaEvalOp.h"
#include "IfPositive.h"
#include "IfLessThanEq.h"

#include "Game.h"
#include "PlayingStrategy.h"

#include "AlwaysCooperate.h"
#include "AlwaysBetray.h"
#include "TitOrTat.h"
#include "AlternatingMoves.h"

int main(int argc, char **argv)
{
	TreeP tree = static_cast<TreeP>(new Tree::Tree);

	StateP state = static_cast<StateP>(new State);

	Tree::PrimitiveP ifpos(new IfPositive);
	tree->addFunction(ifpos);
	Tree::PrimitiveP iflte(new IfLessThanEq);
	tree->addFunction(iflte);

	state->addGenotype(tree);
	state->setEvalOp(static_cast<EvaluateOpP>(new PrisDilemmaEvalOp));
	state->initialize(argc, argv);
	state->run();

	std::vector<IndividualP> hof = state->getHoF()->getBest();
	IndividualP ind = hof[0];
	TreeP tree2 = boost::static_pointer_cast<Tree::Tree> (ind->getGenotype());

	PlayingStrategy *ps1 = new AlwaysCooperate();
	PlayingStrategy *ps2 = new AlwaysBetray();
	PlayingStrategy *ps3 = new TitOrTat();
	PlayingStrategy *ps4 = new AlternatingMoves();

	PlayerMove myMove = (PlayerMove)(rand() % 2 + 1);	//prvi potez - 1(izdaja) ili 2(suradnja)
	//int enemyMove = rand() % 2 + 1;
	PlayerMove enemyMove = ps4->getFirstMove();
	int myResult = Game::playMove(myMove, enemyMove);

	std::stringstream myMoves, enemyMoves, round, res;
	myMoves << "My moves:     " << (int)myMove;
	enemyMoves << "Enemy moves:  " << (int)enemyMove;
	round << "Round:        0";
	res << "Result:       " << myResult;

	int sum = myResult;
	int enemySum = Game::enemyResult(myResult);

	//x = moj zadnji potez
	//y = protivnicki zadnji potez
	//z = moji bodovi

	for (int i = 0; i < 10; i++) {
		tree2->setTerminalValue("x", &myMove);
		tree2->setTerminalValue("y", &enemyMove);
		tree2->setTerminalValue("z", &myResult);

		double result;
		tree2->execute(&result);

		enemyMove = ps4->getNextMove(myMove);

		if (result > abs(1)) {
			myMove = PlayerMove::cooperation;
		}
		else {
			myMove = PlayerMove::treason;
		}

		myResult = Game::playMove(myMove, enemyMove);
		sum += myResult;

		myMoves << " " << (int)myMove;
		enemyMoves << " " << (int)enemyMove;
		round << " "<< i+1;
		res << " " << myResult;

		enemySum += Game::enemyResult(myResult);
	}

	std::cout << round.str() << endl;
	std::cout << myMoves.str() << "  sum: " << sum << endl;
	std::cout << enemyMoves.str() << "  sum: " << enemySum << endl;
	std::cout << res.str() << endl;

	return 0;
}