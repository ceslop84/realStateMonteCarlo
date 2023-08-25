#include "../../include/model/AVEF.h"

#define LOW_RATE -0.5
#define HIGH_RATE 0.5
#define MAX_ITERATION 1000
#define PRECISION_REQ 0.00000001

namespace model
{

double calcularTir(double cf[], int numOfFlows)
{
 //https://www.codeproject.com/Tips/461049/Internal-Rate-of-Return-IRR-Calculation
 int i = 0,j = 0;
 double m = 0.0;
 double old = 0.00;
 double newv = 0.00;
 double oldguessRate = LOW_RATE;
 double newguessRate = LOW_RATE;
 double guessRate = LOW_RATE;
 double lowGuessRate = LOW_RATE;
 double highGuessRate = HIGH_RATE;
 double npv = 0.0;
 double denom = 0.0;

 for(i=0; i<MAX_ITERATION; i++)
 {
  npv = 0.00;
  for(j=0; j<numOfFlows; j++)
  {
   denom = pow((1 + guessRate),j);
   npv = npv + (cf[j]/denom);
  }
   /* Stop checking once the required precision is achieved */
  if((npv > 0) && (npv < PRECISION_REQ))
   break;
  if(old == 0)
   old = npv;
  else
   old = newv;
  newv = npv;
  if(i > 0)
  {
   if(old < newv)
   {
    if(old < 0 && newv < 0)
     highGuessRate = newguessRate;
    else
     lowGuessRate = newguessRate;
   }
   else
   {
    if(old > 0 && newv > 0)
     lowGuessRate = newguessRate;
    else
     highGuessRate = newguessRate;
   }
  }
  oldguessRate = guessRate;
  guessRate = (lowGuessRate + highGuessRate) / 2;
  newguessRate = guessRate;
 }
 return guessRate;
}

void AVEF::calcularAvef()
{
    int cont;
    //Conversào de taxa anual para mensal.
    double p1, p2, tie, tco, v, inv_in;

    double fc[getPeriodo()+2];
//    double fc[getSmc()->getCapitalExt()->getPrazo()+2];

    //Ind. economico
    p1 = 1.0 + getTaxaIndEcon()/100.0;
    p2 = pow(p1, 0.083333);
    tie = p2 - 1.0;

    //Custo de oportunidade.
    p1 = 1.0 + getTaxaOport()/100.0;
    p2 = pow(p1, 0.083333);
    tco = p2 - 1.0;

    //Taxa FGTS
    double tf = 0.002466;

    //Cálculo do investimento inicial.
    inv_in = 0;
    inv_in = getSmc()->getTransacao()->getEntrada() + getSmc()->getCapitalExt()->getCustoContratacao();
    for (int i = 0; i<getSmc()->getValores().size(); i++){
            inv_in += getSmc()->getValores()[i]->getValorU() * getSmc()->getValores()[i]->getValorQ();
    }

    //Calculo do fluxo de caixa.
    fc[0] = -inv_in;
    for (int i = 0; i<getSmc()->getCapitalExt()->getPrazo(); i++){
        fc[i+1] = getCustoEvitado() - getSmc()->getCapitalExt()->getPrestacoes()[i]->getAmortizacao() - getSmc()->getCapitalExt()->getPrestacoes()[i]->getJuros()- getSmc()->getCapitalExt()->getPrestacoes()[i]->getServicos() - (inv_in * tco) - getSmc()->getTransacao()->getAporteFgts()*tf;
    }
    if (getPeriodo()>getSmc()->getCapitalExt()->getPrazo()){
        for (int i = getSmc()->getCapitalExt()->getPrazo(); i<=getPeriodo(); i++){
            fc[i+1] = getCustoEvitado() - (inv_in * tco) - getSmc()->getTransacao()->getAporteFgts()*tf;
        }
    }
    v = getSmc()->getTransacao()->getValorBem();
    for (int i = 0; i<getPeriodo()+2; i++){
        v += v*tie;
    }
    fc[getPeriodo()+2] = v;

    //Calculando a TIR anualizada do projeto.
    setTir((pow(1 + model::calcularTir(fc, getPeriodo() + 3),12)-1)*100.0);

    //Calcular VPL com a TMA igual à taxa de oportunidade.
    v = 0;
    for (int i = 0; i<getPeriodo() + 3; i++){
        v += fc[i]/pow((1+tco),i);
    }
     setVpl(v);

     //Calcular payback simples.
    v = 0;
    cont = 0;
    while (v<=0){
        if (cont>getPeriodo()+2){
            v += getCustoEvitado() - (inv_in * tco) - getSmc()->getTransacao()->getAporteFgts()*tf;
        } else {
            v += fc[cont];
        }
        if (cont >= 85*12){
            cont = 0;
            break;
        }
        cont++;
    }
    setPaybackSimples(cont);

    //Calcular payback Descontado.
    v = 0;
    cont = 0;
    while (v<=0){
        if (cont>getPeriodo()+2){
            v += (getCustoEvitado() - (inv_in * tco) - getSmc()->getTransacao()->getAporteFgts()*tf)/pow((1+tie),cont);
        } else {
            v += fc[cont]/pow((1+tie),cont);
        }
        cont++;
        if (cont >= 85*12){
            cont = 0;
            break;
        }
    }
    setPaybackDescontado(cont);

    //Calcular razão custo/benefício.
    v = 0;
    for (int i = 1; i<getPeriodo() + 3; i++){
        v += fc[i]/pow((1+tco),i);
    }
    setRazaoCustoBenf(v/inv_in);
}

void AVEF::setTaxaIndEcon(double t)
{
    taxaIndEcon = t;
}

double AVEF::getTaxaIndEcon()
{
    return taxaIndEcon;
}

void AVEF::setNomeIndEcon(string n)
{
    nomeIndEcon = n;
}

string AVEF::getNomeIndEcon()
{
    return nomeIndEcon;
}

void AVEF::setTaxaOport(double t)
{
    taxaOport = t;
}

double AVEF::getTaxaOport()
{
    return taxaOport;
}

void AVEF::setPeriodo(int p)
{
    periodo = p;
}

int AVEF::getPeriodo()
{
    return periodo;
}


void AVEF::setCustoEvitado(double c)
{
    custoEvitado = c;
}

double AVEF::getCustoEvitado()
{
    return custoEvitado;
}

void AVEF::setTir(double t)
{
    tir = t;
}

double AVEF::getTir()
{
    return tir;
}

void AVEF::setPaybackSimples(double p)
{
    paybackSimples = p;
}

double AVEF::getPaybackSimples()
{
    return paybackSimples;
}

void AVEF::setPaybackDescontado(double p)
{
    paybackDescontado = p;
}

double AVEF::getPaybackDescontado()
{
    return paybackDescontado;
}

void AVEF::setVpl(double v)
{
    vpl = v;
}

double AVEF::getVpl()
{
    return vpl;
}

void AVEF::setRazaoCustoBenf(double r)
{
    razaoCustoBenf = r;
}

double AVEF::getRazaoCustoBenf()
{
    return razaoCustoBenf;
}

SMC* AVEF::getSmc()
{
	return AVEF::smc;
}

AVEF::AVEF()
{
    msg = new control::mensagem();
    smc = new model::SMC();
    taxaIndEcon = 0;
	nomeIndEcon = "";
	taxaOport = 0;
	custoEvitado = 0;
	tir = 0;
	paybackSimples = 0;
	paybackDescontado = 0;
	vpl = 0;
	razaoCustoBenf = 0;
}

AVEF::AVEF(model::SMC* s):AVEF()
{
    smc = s;
}

AVEF::AVEF(model::SMC* s, string nome, double taxai, double taxao, double custoE):AVEF(s)
{
}

control::mensagem* AVEF::getMsg()
{
    return msg;
}
}  // namespace model
