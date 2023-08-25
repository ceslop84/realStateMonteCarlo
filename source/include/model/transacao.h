#ifndef MODEL_TRANSACAO_H
#define MODEL_TRANSACAO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "../../include/control/mensagem.h"

namespace model
{
class transacao
{
private:
	double valorBem;
	double entrada;
	double aporteFgts;
	double saldoDevedor;
	control::mensagem* msg;

public:
	void calcularSaldoDevedor();
	void setValorBem(double valorBem);
	double getValorBem();
	void setEntrada(double entrada);
	double getEntrada();
	void setAporteFgts(double aporteFgts);
	double getAporteFgts();
	double getSaldoDevedor();
	transacao(double vb, double e, double fgts);
	transacao();
	control::mensagem* getMsg();
};

}  // namespace model
#endif
