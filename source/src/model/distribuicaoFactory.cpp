#include "../../include/model/distribuicaoFactory.h"

namespace model
{

distribuicaoFactory::distribuicaoFactory()
{
}

distribuicao* distribuicaoFactory::criar(string d, double p1, double p2, double p3)
{
    distribuicao* saida = new model::distribuicao();
    if ((d=="Normal")|(d=="Uniforme")){
        if (d=="Normal"){
            saida = new model::normal(p1, p2, p3);
        } else if (d=="Uniforme"){
            saida = new model::uniforme(p1, p2, p3);
        }
    }else {
        saida->getMsg()->inserirMsg("Distribuição estatística dos juros de capital externo não cadastrado.");
        saida->getMsg()->setErro(true);
    }
    return saida;
}
}  // namespace model
