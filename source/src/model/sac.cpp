#include "../../include/model/sac.h"

namespace model
{

sac::sac():capitalExterno()
{
}

sac::sac(double v, string f, double tj,int prazo, double ts, double cc, string d, double p1, double p2, double p3):capitalExterno(v, f, tj, "SAC", prazo, ts, cc, d, p1, p2, p3)
{
}

void sac::calcularPrestacoes(double t)
{
    //Fonte: https://pt.wikipedia.org/wiki/Sistema_de_Amortiza%C3%A7%C3%A3o_Constante
    double vAmort, saldo, juros, servicos, taxaJurosMensal;
    double amortTotal, jurosTotal, servicosTotal;
    double p1, p2;
    //Conversào de taxa de juros anual para mensal.
    p1 = 1.0 + t/100.0;
    p2 = pow(p1, 0.083333);
    taxaJurosMensal = p2 - 1.0;

    //Cálculo da amortização constante.
    vAmort = valorCapExt/prazo;

    //Inicialização das demais variáveis.
    amortTotal = 0;
    jurosTotal = 0;
    servicosTotal = 0;
    prestacoes.clear();
    for (int i = 0; i<prazo;i++){
        saldo = valorCapExt - amortTotal;
        juros = taxaJurosMensal * saldo;
        servicos = taxaServicos/100.0 * saldo;
        prestacao* p = new prestacao(vAmort, juros, servicos, i);
        prestacoes.push_back(p);
        amortTotal += vAmort;
        jurosTotal += juros;
        servicosTotal += servicos;
    }
    valorJuros = jurosTotal;
	valorServicos = servicosTotal;
	valorAmortizacao = amortTotal;
}
}  // namespace model
