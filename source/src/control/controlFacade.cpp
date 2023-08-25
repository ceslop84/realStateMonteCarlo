#include "../../include/control/controlFacade.h"

namespace control
{

controlFacade::controlFacade()
{
    msg = control::mensagem();
}

void controlFacade::executar(view::view* d)
{
    //Método que constroi todos os objetos necessários para rodar o modelo.
    construirModelo(d);
    if (!d->isErro()){
        //Método que inicia a simulação de Monte Carlo.
        getAvef()->getSmc()->calcularSmc();
        if (getAvef()->getSmc()->getMsg()->isErro()){
            d->addMsg(getAvef()->getSmc()->getMsg()->gerarSaida());
            d->setErro(true);
        }else{
            d->setValorMaisProvMax(getAvef()->getSmc()->getValorMaisProvMMax());
            d->setValorMaisProvMin(getAvef()->getSmc()->getValorMaisProvMin());
            if (d->isCalcularAvef()){
                getAvef()->calcularAvef();
            if (getAvef()->getSmc()->getMsg()->isErro()){
                d->addMsg(getAvef()->getMsg()->gerarSaida());
                d->setErro(true);
            }else{
                d->setTir(getAvef()->getTir());
                d->setVpl(getAvef()->getVpl());
                d->setPaybackSimples(getAvef()->getPaybackSimples());
                d->setPaybackDescontado(getAvef()->getPaybackDescontado());
                d->setRazaoCB(getAvef()->getRazaoCustoBenf());
            }
            }
        }
    }
}

control::mensagem* controlFacade::getMsg()
{
    return &msg;
}

model::AVEF* controlFacade::getAvef()
{
    return avef;
}

void controlFacade::setAvef(model::AVEF* a)
{
    avef = a;
}

void controlFacade::construirModelo(view::view* d)
{
    //Inicialização da Simulação de Monte Carlo.
    model::SMC* smc = new model::SMC();
    smc = new model::SMC(d->getAmostras());
    //Verifica se existem erros. Se postivio, passa para a camada de view.
    if (smc->getMsg()->isErro()){
        d->addMsg(smc->getMsg()->gerarSaida());
        d->setErro(true);
    }

    //Inicializa a classe tranasação.
    model::transacao* transacao = new model::transacao();
    transacao = new model::transacao(d->getValorBem(), d->getEntrada(), d->getAporteFgts());
    //Verifica se existem erros. Se postivio, passa para a camada de view.
    if (transacao->getMsg()->isErro()){
        d->addMsg(transacao->getMsg()->gerarSaida());
        d->setErro(true);
    }
    smc->setTransacao(transacao);

    //Inicializa a classe capital externo.
    model::capitalExternoFactory fact = model::capitalExternoFactory();
    model::capitalExterno* capExt =  new model::capitalExterno();
    capExt = fact.criar(d->getValorCapExt(), d->getFonte(), d->getTaxaJuros(), d->getSistAmort(), d->getPrazo(), d->getTaxaServicos(), d->getCustoContratacao(), d->getDistJuros(), d->getDistJurosP1(), d->getDistJurosP2(), d->getDistJurosP3());
    //Verifica se existem erros. Se postivio, passa para a camada de view.
    if (capExt->getMsg()->isErro()){
        d->addMsg(capExt->getMsg()->gerarSaida());
        d->setErro(true);
    }else{
        smc->setCapitalExt(capExt);
    }

    //Inicializa valores.
    if (d->getVDescricao().size()>0){
        vector<model::valor*> valores;
        for (int i = 0; i < d->getVDescricao().size(); i++){
            model::valor* v = new model::valor(i+1, d->getVDescricao()[i], d->getVValorU()[i], d->getVDistVU()[i], d->getVDistVUP1()[i], d->getVDistVUP2()[i], d->getVDistVUP3()[i], d->getVValorQ()[i], d->getVDistQ()[i], d->getVDistQP1()[i], d->getVDistQP2()[i], d->getVDistQP3()[i]);
            if (v->getMsg()->isErro()){
                d->addMsg(v->getMsg()->gerarSaida());
                d->setErro(true);
            }else{
                valores.push_back(v);
            }
        }
        smc->setValores(valores);
    }

    //Inicializa Aval. Econ.-Fin.
    model::AVEF* avef = new model::AVEF(smc);
    avef->setCustoEvitado(d->getCustoEvitado());
    avef->setTaxaIndEcon(d->getTaxaIndEcon());
    avef->setNomeIndEcon(d->getNomeIndEcon());
    avef->setTaxaOport(d->getTaxaOport());
    avef->setPeriodo(d->getPeriodo());
    if (avef->getMsg()->isErro()){
        d->addMsg(avef->getMsg()->gerarSaida());
        d->setErro(true);
    }else{
        setAvef(avef);
    }
}
}  // namespace control
