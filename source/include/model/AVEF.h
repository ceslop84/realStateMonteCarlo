#ifndef MODEL_A_V_E_F_H
#define MODEL_A_V_E_F_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "../../include/control/mensagem.h"
#include "../../include/model/SMC.h"

namespace model
{
class AVEF
{
private:
	double taxaIndEcon;
	string nomeIndEcon;
	double taxaOport;
	double custoEvitado;
	double tir;
	double paybackSimples;
	double paybackDescontado;
	double vpl;
	double razaoCustoBenf;
	int periodo;
	SMC* smc;
	control::mensagem* msg;

public:
    double calcularTir(double cf[], int numOfFlows);
	void calcularAvef();
	void setTaxaIndEcon(double t);
	double getTaxaIndEcon();
	void setNomeIndEcon(string n);
	string getNomeIndEcon();
	void setTaxaOport(double t);
	double getTaxaOport();
	void setCustoEvitado(double c);
	double getCustoEvitado();
	void setTir(double t);
	double getTir();
	void setPaybackSimples(double p);
	double getPaybackSimples();
	void setPaybackDescontado(double p);
	double getPaybackDescontado();
	void setVpl(double v);
	double getVpl();
	void setRazaoCustoBenf(double r);
	double getRazaoCustoBenf();
    void setPeriodo(int p);
	int getPeriodo();
	SMC* getSmc();
	AVEF();
	AVEF(model::SMC* s);
	AVEF(model::SMC* s, string nome, double taxai, double taxao, double custoE);
	control::mensagem* getMsg();
};

}  // namespace model
#endif
