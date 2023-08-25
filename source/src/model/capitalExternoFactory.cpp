#include "../../include/model/capitalExternoFactory.h"

namespace model
{

capitalExternoFactory::capitalExternoFactory()
{
}

capitalExterno* capitalExternoFactory::criar(double v, string f, double tj, string sa, int p, double ts, double cc, string d, double p1, double p2, double p3)
{
    capitalExterno* saida = new model::capitalExterno();

    if (sa == "SAC"){
        saida = new model::sac(v, f, tj, p, ts, cc, d, p1, p2, p3);
    } else if(sa == "PRICE"){
        saida = new model::price(v, f, tj, p, ts, cc, d, p1, p2, p3);
    } else if(sa == "Não aplicável"){
        saida = new model::zeroFunding();
    } else{
        saida->getMsg()->inserirMsg("Sistema de amortização não cadastrado.");
        saida->getMsg()->setErro(true);
    }

    return saida;
}
}  // namespace model
