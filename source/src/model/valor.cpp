#include "../../include/model/valor.h"

namespace model
{

void valor::setDescricao(string desc)
{
    descricao = desc;
}

string valor::getDescricao()
{
    return descricao;
}

void valor::setValorU(double v)
{
    valorU = v;
}

double valor::getValorU()
{
	return valorU;;
}

void valor::setDistU(distribuicao* dvu)
{
    distU = dvu;
}

distribuicao* valor::getDistU()
{
    return distU;
}

void valor::setValorQ(double v)
{
    valorQ= v;
}

double valor::getValorQ()
{
	return valorQ;
}

void valor::setDistQ(distribuicao* dvq)
{
    distQ = dvq;
}

distribuicao* valor::getDistQ()
{
    return distQ;
}

valor::valor()
{
    msg = new control::mensagem();
    descricao = "";
   	valorU = 0;
	valorQ = 0;
}

valor::valor(int id, string n, double vu, string du, double dup1, double dup2, double dup3, double vq, string dq, double dqp1, double dqp2, double dqp3):valor()
{
    std::stringstream s;

    setId(id);
    setDescricao(n);
    setValorU(vu);
    setValorQ(vq);

    model::distribuicaoFactory fact = model::distribuicaoFactory();
    model::distribuicao* ddu = new model::distribuicao();
    ddu = fact.criar(du, dup1, dup2, dup3);
    //Verifica se existem erros. Se postivio, passa para a camada de view.
    if (ddu->getMsg()->isErro()){
        s << "Distribuição estatística de valor unitário na linha - erro na linha " << id << " - " << n << " " << ddu->getMsg()->gerarSaida();
        getMsg()->inserirMsg(s.str());
        getMsg()->setErro(true);
    }else{
        setDistU(ddu);
    }
    model::distribuicao* ddq = new model::distribuicao();
    ddq = fact.criar(dq, dqp1, dqp2, dqp3);
    //Verifica se existem erros. Se postivio, passa para a camada de view.
    if (ddq->getMsg()->isErro()){
        s << "Distribuição estatística de valor de qntd na linha - erro na linha " << id << " - " << n << " " << ddq->getMsg()->gerarSaida();
        getMsg()->inserirMsg(s.str());
        getMsg()->setErro(true);
    }else{
        setDistQ(ddq);
    }
}

control::mensagem* valor::getMsg()
{
    return msg;
}

int valor::getId()
{
    return id;
}

void valor::setId(int i)
{
    id = i;
}

}  // namespace model
