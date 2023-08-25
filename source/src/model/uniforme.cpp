#include "../../include/model/uniforme.h"

namespace model
{
uniforme::uniforme():distribuicao()
{
}

uniforme::uniforme(double p1, double p2, double p3):distribuicao(p1, p2, p3)
{
    if ((p1>p2)||(p1>p3)||(p2>p3)){
        param1 = 0;
        param2 = 0;
        param3 = 0;
        getMsg()->inserirMsg("Parâmetros com erro de cadastro. Os parâmetros devem ser: p1: mínimo, p2: provável e p3: máximo sendo p1<=p2<=p3");
        getMsg()->setErro(true);
    }else{
        nome = "Distribuição Uniforme";
    }
}

double uniforme::gerarAleatorio()
{
    std::uniform_real_distribution<double> d(param1,param3);
    return d(random);
}

}  // namespace model
