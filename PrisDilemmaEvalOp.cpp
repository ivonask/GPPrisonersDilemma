#include <ecf/ECF.h>
#include <time.h> 
#include <math.h> 
#include "PrisDilemmaEvalOp.h"
#include "Game.h"
#include "PlayingStrategy.h"
#include "AlwaysCooperate.h"
#include "AlwaysBetray.h"
#include "TitForTat.h"
#include "AlternatingMoves.h"
#include "PrisonersDilemma.h"
#include "TitForTwoTats.h"
#include "Grudger.h"
#include "SuspiciousTitForTat.h"
#include "Pavlov.h"

#include "RockPaperScissors.h"

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

	//jako kooperativne
	PlayingStrategy *ps1 = new AlwaysCooperate();
	PlayingStrategy *ps2 = new TitForTat();
	PlayingStrategy	*ps3 = new TitForTwoTats();

	//prilicno kooperativne
	PlayingStrategy *ps4 = new AlternatingMoves();
	PlayingStrategy *ps5 = new Grudger();
	PlayingStrategy *ps6 = new Pavlov();

	//nekooperativne
	PlayingStrategy *ps7 = new SuspiciousTitForTat();
	PlayingStrategy *ps8 = new AlwaysBetray();

	int sum = 0;

	Game *game1 = new PrisonersDilemma(ps1);
	sum += game1->play(20, tree, false);

	Game *game2 = new PrisonersDilemma(ps2);
	sum += game2->play(20, tree, false);

	Game *game3 = new PrisonersDilemma(ps3);
	sum += game3->play(20, tree, false);

	//Game *game4 = new PrisonersDilemma(ps4);
	//sum += game4->play(20, tree, false);

	//Game *game5= new PrisonersDilemma(ps5);
	//sum += game5->play(20, tree, false);

	//Game *game6= new PrisonersDilemma(ps6);
	//sum += game6->play(20, tree, false);

	//Game *game7= new PrisonersDilemma(ps7);
	//sum += game7->play(20, tree, false);

	//Game *game8= new PrisonersDilemma(ps8);
	//sum += game8->play(20, tree, false);
	
	fitness->setValue(sum);

	return fitness;
}

