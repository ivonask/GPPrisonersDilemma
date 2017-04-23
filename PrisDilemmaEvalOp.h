#ifndef PRISDILEMMAEVALOP_H_
#define PRISDILEMMAEVALOP_H_

#include <cmath>

class PrisDilemmaEvalOp : public EvaluateOp
{
public:
	FitnessP evaluate(IndividualP individual);
	//void registerParameters(StateP);
	bool initialize(StateP);
	//static int play(int myMove, int enemyMove);
};
//typedef boost::shared_ptr<PrisDilemmaEvalOp> PrisDilemmaEvalOp;

#endif /* PRISDILEMMAEVALOP_H_ */
