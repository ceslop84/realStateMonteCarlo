#ifndef MODEL_S_M_C_H
#define MODEL_S_M_C_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <math.h>

#include "../../include/control/mensagem.h"
#include "../../include/model/transacao.h"
#include "../../include/model/capitalExterno.h"
#include "../../include/model/zeroFunding.h"
#include "../../include/model/valor.h"


namespace model
{
class SMC
{
private:
	double valorMaisProvMin;
	double valorMaisProvMax;
	double media;
	double desvPad;
	int amostras;
	vector<valor*> valores;
	bool calculado;
	transacao* trans;
	capitalExterno* capitalExt;
	control::mensagem* msg;

private:
	void dimensionar();

public:
	void calcularSmc();
	void setValores(vector<valor*> v);
	vector<valor*> getValores();
	void setCalculado(bool c);
	bool getCalculado();
	void setTransacao(transacao* t);
	transacao* getTransacao();
	void setCapitalExt(capitalExterno* c);
	capitalExterno* getCapitalExt();
	SMC();
	SMC(int a);
	control::mensagem* getMsg();
	int getAmostras();
	double getValorMaisProvMin();
	double getValorMaisProvMMax();
    double getMedia();
    double getDesvPad();
};

}  // namespace model
#endif
