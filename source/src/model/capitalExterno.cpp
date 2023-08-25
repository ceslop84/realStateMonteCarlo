#include "../../include/model/capitalExterno.h"

namespace model
{

void capitalExterno::calcularPrestacoes(double t)
{
}

vector<prestacao*> capitalExterno::getPrestacoes()
{
    return prestacoes;
}

void capitalExterno::setValorCapExt(double v)
{
    if (v>0){
        valorCapExt = v;
    }else{
        getMsg()->setErro(true);
        getMsg()->inserirMsg("Valor cadastrado para valor de capital externo zero ou negativo.");
        valorCapExt = 0;
    }
}

double capitalExterno::getValorCapExt()
{
	return valorCapExt;
}

void capitalExterno::setFonte(string f)
{
    fonte = f;
}

string capitalExterno::getFonte()
{
	return fonte;
}

void capitalExterno::setTaxaJuros(double tj)
{
    if (tj>=0){
        taxaJuros = tj;
    }else{
        getMsg()->setErro(true);
        getMsg()->inserirMsg("Valor cadastrado para taxa de juros negativo.");
        taxaJuros = 0;
    }
}

double capitalExterno::getTaxaJuros()
{
	return taxaJuros;
}

string capitalExterno::getSistemaAmortizacao()
{
	return sistemaAmortizacao;
}

void capitalExterno::setPrazo(int p)
{
    if (p>0){
        if (p<1020){
            prazo = p;
        }else{
            getMsg()->setErro(true);
            getMsg()->inserirMsg("Prazo cadastrado para pagamento do capital maior do que 85 anos.");
            prazo = 0;
        }

    }else{
        getMsg()->setErro(true);
        getMsg()->inserirMsg("Prazo cadastrado para pagamento do capital externo negativo.");
        prazo = 0;
    }
}

int capitalExterno::getPrazo()
{
	return prazo;
}

void capitalExterno::setTaxaServicos(double ts)
{
    if (ts>=0){
        taxaServicos = ts;
    }else{
        getMsg()->setErro(true);
        getMsg()->inserirMsg("Valor cadastrado para taxa de serviços negativo.");
        taxaServicos = 0;
    }
}

double capitalExterno::getTaxaServicos()
{
	return taxaServicos;
}

void capitalExterno::setCustoContratacao(double cc)
{
    if (cc>=0){
        custoContratacao = cc;
    }else{
        getMsg()->setErro(true);
        getMsg()->inserirMsg("Valor cadastrado para custo de contratação negativo.");
        custoContratacao = 0;
    }
}

double capitalExterno::getCustoContratacao()
{
	return custoContratacao;
}

double capitalExterno::getValorJuros()
{
	return valorJuros;
}

double capitalExterno::getValorServicos()
{
	return valorServicos;
}


double capitalExterno::getValorAmortizacao()
{
	return valorAmortizacao;
}

distribuicao* capitalExterno::getDist()
{
	return dist;
}

void capitalExterno::setDist(distribuicao* dce)
{
    dist = dce;
}

capitalExterno::capitalExterno()
{
    msg = new control::mensagem();
    valorCapExt = 0;
	fonte = "";
	taxaJuros = 0;
	sistemaAmortizacao = "";
	prazo = 0;
	taxaServicos = 0;
	custoContratacao = 0;
	valorJuros = 0;
	valorServicos = 0;
	valorAmortizacao = 0;
	prestacoes.clear();

}

capitalExterno::capitalExterno(double v, string f, double tj, string sa, int p, double ts, double cc, string d, double p1, double p2, double p3):capitalExterno()
{
    setValorCapExt(v);
    setFonte(f);
    sistemaAmortizacao = sa;
    setPrazo(p);
    setTaxaServicos(ts);
    setCustoContratacao(cc);

    model::distribuicaoFactory fact = model::distribuicaoFactory();
    model::distribuicao* dd = new model::distribuicao();
    dd = fact.criar(d, p1, p2, p3);
    //Verifica se existem erros. Se postivio, passa para a camada de view.
    if (dd->getMsg()->isErro()){
        getMsg()->inserirMsg(dd->getMsg()->gerarSaida());
        getMsg()->setErro(true);
    }else{
        setDist(dd);
    }
}

control::mensagem* capitalExterno::getMsg()
{
    return msg;
}
}  // namespace model
