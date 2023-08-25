#include "../../include/model/price.h"

namespace model
{

price::price():capitalExterno()
{
}

price::price(double v, string f, double tj,int prazo, double ts, double cc, string d, double p1, double p2, double p3):capitalExterno(v, f, tj, "PRICE", prazo, ts, cc, d, p1, p2, p3)
{
}

void price::calcularPrestacoes(double t)
{
    //Fonte: https://pt.wikipedia.org/wiki/Tabela_Price
    double vAmort, saldo, juros, servicos, taxaJurosMensal;
    double amortTotal, jurosTotal, servicosTotal, pmt;
    double p1, p2;
    //Conversào de taxa de juros anual para mensal.
    p1 = 1.0 + t/100.0;
    p2 = pow(p1, 0.083333);
    taxaJurosMensal = p2 - 1.0;

    //Cálculo da prestação constante.
    pmt = (1-(1/pow((1+taxaJurosMensal),prazo)));

    //Inicialização das demais variáveis.
    amortTotal = 0;
    jurosTotal = 0;
    servicosTotal = 0;
    prestacoes.clear();
    for (int i = 1; i<prazo;i++){
        saldo = valorCapExt - amortTotal;
        juros = taxaJurosMensal * saldo;
        servicos = taxaServicos/100.0 * saldo;
        vAmort = pmt - juros;
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
