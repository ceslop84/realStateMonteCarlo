#ifndef MODEL_DISTRIBUICAO_H
#define MODEL_DISTRIBUICAO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <random>
#include <time.h>

#include "../../include/control/mensagem.h"

namespace model
{
class distribuicao
{
protected:



private:
	control::mensagem* msg;

public:
	distribuicao();
	distribuicao(double p1, double p2, double p3);
	virtual double gerarAleatorio();
	control::mensagem* getMsg();
    string nome;
    double param1;
    double param2;
	double param3;
    std::default_random_engine random;
};

}  // namespace model
#endif
