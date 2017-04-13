#include <ecf/ECF.h>
#include <time.h> 
#include <math.h> 
#include "PrisDilemmaEvalOp.h"
#include "Game.h"
#include "PlayingStrategy.h"
#include "AlwaysCooperate.h"
#include "AlwaysBetray.h"
#include "TitOrTat.h"
#include "AlternatingMoves.h"

bool PrisDilemmaEvalOp::initialize(StateP state)
{
	srand(time(NULL));
	return true;
}

FitnessP PrisDilemmaEvalOp::evaluate(IndividualP individual)
{
	// maksimiziramo bodove u svakoj "rundi" 
	FitnessP fitness(new FitnessMax);

	// get the genotype we defined in the configuration file
	Tree::Tree* tree = (Tree::Tree*) individual->getGenotype().get();
	// (you can also use boost smart pointers:)
	//TreeP tree = boost::static_pointer_cast<Tree::Tree> (individual->getGenotype());

	PlayingStrategy *ps1 = new AlwaysCooperate();
	PlayingStrategy *ps2 = new AlwaysBetray();
	PlayingStrategy *ps3 = new TitOrTat();
	PlayingStrategy *ps4 = new AlternatingMoves();

	PlayerMove myMove = (PlayerMove) (rand() % 2 + 1);	//prvi potez - 0(izdaja) ili 1(suradnja)
	PlayerMove enemyMove = ps4->getFirstMove();

	int myResult = Game::playMove(myMove, enemyMove);

	int sum = myResult;

	//x = moj zadnji potez
	//y = protivnicki zadnji potez
	//z = moji bodovi

	for (int i = 0; i < 10; i++) {
		tree->setTerminalValue("x", &myMove);
		tree->setTerminalValue("y", &enemyMove);
		tree->setTerminalValue("z", &myResult);

		double result;
		tree->execute(&result);

		enemyMove = ps4->getNextMove(myMove);

		if (result > abs(1)) {
			myMove = PlayerMove::cooperation;
		}
		else {
			myMove = PlayerMove::treason;
		}

		myResult = Game::playMove(myMove, enemyMove);
		sum += myResult;
	}
	fitness->setValue(sum);

	return fitness;
}

