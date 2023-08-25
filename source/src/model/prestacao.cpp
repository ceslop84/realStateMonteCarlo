#include "../../include/model/prestacao.h"

namespace model
{

double prestacao::getAmortizacao()
{
	return amortizacao;
}

double prestacao::getJuros()
{
	return juros;
}

double prestacao::getServicos()
{
	return servicos;
}

int prestacao::getPrazo()
{
	return prazo;
}

prestacao::prestacao()
{
    msg = new control::mensagem();
    amortizacao = 0;
    juros = 0;
    servicos = 0;
    prazo = 0;
}

prestacao::prestacao(double a, double j, double s, int p):prestacao()
{
    amortizacao = a;
    juros = j;
    servicos = s;
    prazo = p;
}

control::mensagem* prestacao::getMsg()
{
    return msg;
}
}  // namespace model
