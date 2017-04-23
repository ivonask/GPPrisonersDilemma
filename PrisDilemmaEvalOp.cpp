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
#include "PrisonersDilemma.h"

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
	//Tree::Tree* tree = (Tree::Tree*) individual->getGenotype().get();
	// (you can also use boost smart pointers:)
	TreeP tree = boost::static_pointer_cast<Tree::Tree> (individual->getGenotype());

	PlayingStrategy *ps1 = new AlwaysCooperate();
	PlayingStrategy *ps2 = new AlwaysBetray();
	PlayingStrategy *ps3 = new TitOrTat();
	PlayingStrategy *ps4 = new AlternatingMoves();

	Game *game = new PrisonersDilemma(ps1);
	int sum = game->play(10, tree, false);

	fitness->setValue(sum);

	return fitness;
}

