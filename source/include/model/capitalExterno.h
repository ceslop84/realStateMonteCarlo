#ifndef MODEL_CAPITAL_EXTERNO_H
#define MODEL_CAPITAL_EXTERNO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "../../include/control/mensagem.h"
#include "../../include/model/distribuicao.h"
#include "../../include/model/distribuicaoFactory.h"
#include "../../include/model/prestacao.h"

namespace model
{
class capitalExterno
{
protected:
	double valorCapExt;
	string fonte;
	double taxaJuros;
	string sistemaAmortizacao;
	int prazo;
	double taxaServicos;
	double custoContratacao;
	double valorJuros;
	double valorServicos;
	double valorAmortizacao;
	distribuicao* dist;
	vector<prestacao*> prestacoes;
	control::mensagem* msg;
public:
	virtual void calcularPrestacoes(double t);
	void setValorCapExt(double valorCapExt);
	double getValorCapExt();
	void setFonte(string fonte);
	string getFonte();
	void setTaxaJuros(double taxaJuros);
	double getTaxaJuros();
	string getSistemaAmortizacao();
	void setPrazo(int prazo);
	int getPrazo();
	void setTaxaServicos(double taxaServicos);
	double getTaxaServicos();
	void setCustoContratacao(double custoContratacao);
	double getCustoContratacao();
	void calcularValorJuros();
	double getValorJuros();
	void calcularValorServicos();
	double getValorServicos();
	void calcularValorAmortizacao();
	double getValorAmortizacao();
	distribuicao* getDist();
	void setDist(distribuicao* dce);
	vector<prestacao*> getPrestacoes();
	capitalExterno();
	capitalExterno(double v, string f, double tj, string sa, int prazo, double ts, double cc, string d, double p1, double p2, double p3);
	control::mensagem* getMsg();
};

}  // namespace model
#endif
