#ifndef MODEL_NORMAL_H
#define MODEL_NORMAL_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <stdlib.h>

#include "../../include/model/distribuicao.h"

namespace model
{
class normal : public distribuicao
{
public:
    normal();
    normal(double p1, double p2, double p3);
	double gerarAleatorio();
};

}  // namespace model
#endif
