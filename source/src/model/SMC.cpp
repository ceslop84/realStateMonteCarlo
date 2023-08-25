#include "../../include/model/SMC.h"

namespace model
{

void SMC::calcularSmc()
{
    double verif = getTransacao()->getValorBem() - getTransacao()->getAporteFgts() - getTransacao()->getEntrada() - getCapitalExt()->getValorCapExt();
    if (verif!=0){
        getMsg()->inserirMsg("Os valores de valor do bem, aporte FGTS, entrada e valor de capital externo estão irregulares. Atenção: VB - FGTS - E - CE = 0");
        getMsg()->setErro(true);
    }else{
        //Espaço reservado para quando da implementação multi-thread.
        //dimensionar();

        //Execução de amostragem na quantidade de amostras definida pelo usuário.
        double vt = 0; // Valor total.
        double vt1 = getTransacao()->getEntrada() + getTransacao()->getAporteFgts(); //Valores iniciais correspondem às entradas básicas da transação.
        vector<double> resultados;

        for (int i = 0; i<=getAmostras(); i++){
            //Reiniciar vt.
            vt = vt1;

            //Amostra e cálculo para Capital Externo.
            getCapitalExt()->calcularPrestacoes(getCapitalExt()->getDist()->gerarAleatorio());
            vt += getCapitalExt()->getValorAmortizacao() + getCapitalExt()->getValorJuros() + getCapitalExt()->getValorServicos() + getCapitalExt()->getCustoContratacao();

            //Amostra e cálculo para os Valores.
            double v1, v2;
            for (int j = 0; j<getValores().size(); j++){
                v1 = getValores()[j]->getDistQ()->gerarAleatorio();
                v2 = getValores()[j]->getDistU()->gerarAleatorio();
                vt += v1 * v2;
            }
            resultados.push_back(vt);
        }

        //Cálculo dos parâmetros das dist. normal com base nos resultados obtidos da amostragem.
        double soma = 0, var = 0;
        int k;
        for(k = 0; k < resultados.size(); k++)
        {
            soma += resultados[k];
        }
        media = soma/resultados.size();
        for(k = 0; k < resultados.size(); k++){
          var += pow(resultados[k] - media, 2);
        }
        desvPad =  sqrt(var/resultados.size());

        // Valor de Z para um intervalo deconfiança de 95%.
        double z = 1.960;

        // Valores mínimos e máximos do intervalo de confiança.
        valorMaisProvMin = media - (z*(desvPad/pow(getAmostras(),2)));
        valorMaisProvMax = media + (z*(desvPad/pow(getAmostras(),2)));
    }
}

//Método empregado para quando do uso de multi-threads.
void SMC::dimensionar()
{
}

int SMC::getAmostras()
{
    return amostras;
}

void SMC::setValores(vector<valor*> v)
{
    valores = v;
}

vector<valor*> SMC::getValores()
{
    return valores;
}

void SMC::setCalculado(bool c)
{
    calculado = c;
}

bool SMC::getCalculado()
{
    return calculado;
}

void SMC::setTransacao(transacao* t)
{
    trans = t;
}

transacao* SMC::getTransacao()
{
    return trans;
}

void SMC::setCapitalExt(capitalExterno* c)
{
    capitalExt = c;
}

capitalExterno* SMC::getCapitalExt()
{
    return capitalExt;
}

SMC::SMC()
{
    msg = new control::mensagem();
    trans = new model::transacao();
    capitalExt = new model::zeroFunding();
    media = 0;
    desvPad = 0;
    valorMaisProvMax = 0;
    valorMaisProvMin = 0;
}

SMC::SMC(int a):SMC()
{
    if ((a>0)&(a<=10000000)){
        amostras = a;
    }else{
        getMsg()->inserirMsg("O valor de amostras deve ser maior do que zero e inferior ou igual a 10 milhões.");
        getMsg()->setErro(true);
    }
}

control::mensagem* SMC::getMsg()
{
    return msg;
}

double SMC::getValorMaisProvMin()
{
    return valorMaisProvMin;
}
double SMC::getValorMaisProvMMax()
{
    return valorMaisProvMax;
}
double SMC::getMedia()
{
    return media;
}
double SMC::getDesvPad()
{
    return desvPad;
}

}  // namespace model
