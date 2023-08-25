#ifndef MODEL_UNIFORME_H
#define MODEL_UNIFORME_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <stdlib.h>

#include "../../include/model/distribuicao.h"

namespace model
{
class uniforme : public distribuicao
{
public:
    uniforme();
    uniforme(double p1, double p2, double p3);
	double gerarAleatorio();
};

}  // namespace model
#endif
