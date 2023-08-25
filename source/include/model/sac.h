#ifndef MODEL_SAC_H
#define MODEL_SAC_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <math.h>

#include "../../include/model/capitalExterno.h"

namespace model
{
class sac : public capitalExterno
{

public:
    sac();
    sac(double v, string f, double tj,int prazo, double ts, double cc, string d, double p1, double p2, double p3);
	void calcularPrestacoes(double t);
};
}  // namespace model
#endif
