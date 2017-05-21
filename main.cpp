#include <ECF/ECF.h>
#include "PrisDilemmaEvalOp.h"
#include "IfPositive.h"
#include "IfLessThanEq.h"

#include "Game.h"
#include "PlayingStrategy.h"
#include "PrisonersDilemma.h"

#include "AlwaysCooperate.h"
#include "AlwaysBetray.h"
#include "TitForTat.h"
#include "AlternatingMoves.h"
#include "SuspiciousTitForTat.h"
#include "Grudger.h"
#include "Pavlov.h"
#include "TitForTwoTats.h"

#include "TitForTatRPS.h"
#include "RockPaperScissors.h"
#include "RockPaperScissorsEvalOp.h"
#include "ScissorsOnly.h"

int main(int argc, char **argv)
{
	TreeP tree = static_cast<TreeP>(new Tree::Tree);

	StateP state = static_cast<StateP>(new State);

	Tree::PrimitiveP ifpos(new IfPositive);
	tree->addFunction(ifpos);
	Tree::PrimitiveP iflte(new IfLessThanEq);
	tree->addFunction(iflte);

	state->addGenotype(tree);
	//state->setEvalOp(static_cast<EvaluateOpP>(new PrisDilemmaEvalOp));
	state->setEvalOp(static_cast<EvaluateOpP>(new RockPaperScissorsEvalOp));
	state->initialize(argc, argv);
	state->run();

	std::vector<IndividualP> hof = state->getHoF()->getBest();
	IndividualP ind = hof[0];
	TreeP tree2 = boost::static_pointer_cast<Tree::Tree> (ind->getGenotype());

	ofstream best("./best.txt");
	best << ind->toString();
	best.close();

	Game *rps = new RockPaperScissors(new TitForTatRPS());
	//Game *rps = new RockPaperScissors(new ScissorsOnly());

	rps->play(10, tree2, true);


	//XMLNode xInd = XMLNode::parseFile("./best.txt", "Individual");
	//IndividualP ind = (IndividualP) new Individual(state);
	//ind->read(xInd); 

	////jako kooperativne
	//PlayingStrategy *ps1 = new AlwaysCooperate();
	//PlayingStrategy *ps2 = new TitForTat();
	//PlayingStrategy	*ps3 = new TitForTwoTats();

	////prilicno kooperativne
	//PlayingStrategy *ps4 = new AlternatingMoves();
	//PlayingStrategy *ps5 = new Grudger();
	//PlayingStrategy *ps6 = new Pavlov();

	////nekooperativne
	//PlayingStrategy *ps7 = new SuspiciousTitForTat();
	//PlayingStrategy *ps8 = new AlwaysBetray();

	//Game *game1 = new PrisonersDilemma(ps1);
	//game1->play (10, tree2, true);

	//Game *game2 = new PrisonersDilemma(ps2);
	//game2->play(10, tree2, true);

	//Game *game3 = new PrisonersDilemma(ps3);
	//game3->play(10, tree2, true);

	//std::cout << "--------------------------------------------\n";

	//Game *game4 = new PrisonersDilemma(ps4);
	//game4->play(10, tree2, true);

	//Game *game5 = new PrisonersDilemma(ps5);
	//game5->play(10, tree2, true);

	//Game *game6 = new PrisonersDilemma(ps6);
	//game6->play(10, tree2, true);

	//std::cout << "--------------------------------------------\n";

	//Game *game7 = new PrisonersDilemma(ps7);
	//game7->play(10, tree2, true);

	//Game *game8 = new PrisonersDilemma(ps8);
	//game8->play(10, tree2, true);

	return 0;
}