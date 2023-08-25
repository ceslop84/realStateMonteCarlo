#ifndef MODEL_VALOR_H
#define MODEL_VALOR_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <sstream>

#include "../../include/model/distribuicao.h"
#include "../../include/control/mensagem.h"
#include "../../include/model/distribuicaoFactory.h"


namespace model
{
class valor
{
private:
	string descricao;
	int id;
	double valorU;
	double valorQ;
	distribuicao* distU;
	distribuicao* distQ;
	control::mensagem* msg;

public:
	void setDescricao(string d);
	string getDescricao();
	void setValorU(double v);
	double getValorU();
	void setDistU(distribuicao* dvu);
	distribuicao* getDistU();
    void setValorQ(double v);
	double getValorQ();
	void setDistQ(distribuicao* dvq);
	distribuicao* getDistQ();
	valor();
	valor(int id, string n, double vu, string du, double dup1, double dup2, double dup3, double vq, string dq, double dqp1, double dqp2, double dqp3);
	control::mensagem* getMsg();
	int getId();
	void setId(int i);
};

}  // namespace model
#endif
