#ifndef MODEL_PRESTACAO_H
#define MODEL_PRESTACAO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "../../include/control/mensagem.h"

namespace model
{
class prestacao
{
private:
	double amortizacao;
	double juros;
	double servicos;
	int prazo;
	control::mensagem* msg;

public:
	double getAmortizacao();
	double getJuros();
	double getServicos();
	int getPrazo();
	prestacao();
	prestacao(double a, double j, double s, int prazo);
	control::mensagem* getMsg();
};

}  // namespace model
#endif
