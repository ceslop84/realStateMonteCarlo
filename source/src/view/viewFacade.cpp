#include "../../include/view/viewFacade.h"

namespace view
{

viewFacade::viewFacade()
{
    cf = control::controlFacade();
}

void viewFacade::executar()
{
    getCF()->executar(dados);
}

void viewFacade::importar()
{
    arquivoFactory af = arquivoFactory();
    arquivo* arq = new arquivo();
    arq = af.criar(dados->getExportFormat());
    arq->setNome(dados->getImportEnd());
    arq->setDados(dados);
    //Verifica se existem erros. Se postivio, passa para a camada de view.
    if (arq->getMsg()->isErro()){
        dados->addMsg(arq->getMsg()->gerarSaida());
        dados->setErro(true);
    }else{
        arq->lerArquivo();
    }
}

void viewFacade::exportar()
{
    arquivoFactory af = arquivoFactory();
    arquivo* arq = new arquivo();
    arq = af.criar(dados->getExportFormat());
    arq->setDados(dados);
    //Verifica se existem erros. Se postivio, passa para a camada de view.
    if (arq->getMsg()->isErro()){
        dados->addMsg(arq->getMsg()->gerarSaida());
        dados->setErro(true);
    }else{
        arq->escreverArquivo();
    }
}

control::controlFacade* viewFacade::getCF()
{
    return &cf;
}

view* viewFacade::getDados()
{
    return dados;
}

void viewFacade::setDados(view* v){
    dados = v;
}
}  // namespace view
