#include <ecf/ECF.h>
#include <time.h> 
#include <math.h> 
#include "RockPaperScissorsEvalOp.h"
#include "Game.h"
#include "PlayingStrategy.h"
#include "RockPaperScissors.h"

#include "TitForTatRPS.h"
#include "ScissorsOnly.h"

bool RockPaperScissorsEvalOp::initialize(StateP state)
{
	srand(time(NULL));
	return true;
}

FitnessP RockPaperScissorsEvalOp::evaluate(IndividualP individual)
{
	// maksimiziramo bodove u svakoj "rundi" 
	FitnessP fitness(new FitnessMax);

	// get the genotype we defined in the configuration file
	//Tree::Tree* tree = (Tree::Tree*) individual->getGenotype().get();
	// (you can also use boost smart pointers:)
	TreeP tree = boost::static_pointer_cast<Tree::Tree> (individual->getGenotype());


	int sum = 0;

	Game *rps = new RockPaperScissors(new TitForTatRPS());
	//Game *rps = new RockPaperScissors(new ScissorsOnly());

	sum += rps->play(20, tree, false);

	fitness->setValue(sum);

	return fitness;
}

