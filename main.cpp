#include <ECF/ECF.h>
#include "PrisDilemmaEvalOp.h"
#include "IfPositive.h"
#include "IfLessThanEq.h"

#include "Game.h"
#include "PlayingStrategy.h"
#include "PrisonersDilemma.h"

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

	Game *game = new PrisonersDilemma(ps1);
	int sum = game->play (10, tree2, true);

	return 0;
}