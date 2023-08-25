#include "../../include/model/transacao.h"

namespace model
{

void transacao::calcularSaldoDevedor()
{
    saldoDevedor = valorBem - entrada - aporteFgts;
    if (saldoDevedor<0){
        getMsg()->setErro(true);
        getMsg()->inserirMsg("Valores cadastrados para valor do bem, entrada e aporte FGTS geram saldo devedor negativo.");
        saldoDevedor = 0;
    }
}

void transacao::setValorBem(double vb)
{
    if (vb>0){
        valorBem = vb;
    }else{
        getMsg()->setErro(true);
        getMsg()->inserirMsg("Valor do bem é negativo.");
        valorBem = 0;
    }
}

double transacao::getValorBem()
{
	return valorBem;
}

void transacao::setEntrada(double e)
{
    if (e>=0){
        entrada = e;
    }else{
        getMsg()->setErro(true);
        getMsg()->inserirMsg("Valor de entrada negativo.");
        entrada = 0;
    }
}

double transacao::getEntrada()
{
	return entrada;
}

void transacao::setAporteFgts(double f)
{
    if (f>=0){
        aporteFgts = f;
    }else{
        getMsg()->setErro(true);
        getMsg()->inserirMsg("Valor do aporte de FGTS é negativo.");
        aporteFgts = 0;
    }
}

double transacao::getAporteFgts()
{
	return aporteFgts;
}

double transacao::getSaldoDevedor()
{
	return saldoDevedor;
}

transacao::transacao(double vb, double e, double fgts):transacao()
{
    setValorBem(vb);
    setEntrada(e);
    setAporteFgts(fgts);
    calcularSaldoDevedor();
}

transacao::transacao()
{
    msg = new control::mensagem();
    saldoDevedor = 0;
    entrada = 0;
    aporteFgts = 0;
    valorBem = 0;
}

control::mensagem* transacao::getMsg()
{
    return msg;
}
}  // namespace model
