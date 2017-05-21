#ifndef RPSEVALOP_H_
#define RPSEVALOP_H_

#include <cmath>

class RockPaperScissorsEvalOp : public EvaluateOp
{
public:
	FitnessP evaluate(IndividualP individual);
	//void registerParameters(StateP);
	bool initialize(StateP);
	//static int play(int myMove, int enemyMove);
};
//typedef boost::shared_ptr<PrisDilemmaEvalOp> PrisDilemmaEvalOp;

#endif /* RPSEVALOP_H_ */
