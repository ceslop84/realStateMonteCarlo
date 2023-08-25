#include "../../include/model/normal.h"

namespace model
{

normal::normal():distribuicao()
{
}

normal::normal(double p1, double p2, double p3):distribuicao(p1, p2, p3)
{
    if ((p2>p1)||(p3!=0)){
        param1 = 0;
        param2 = 0;
        param3 = 0;
        getMsg()->inserirMsg("Parâmetros com erro de cadastro. Os parâmetros devem ser: p1: média, p2: desvio-padrão e p3: 0, sendo p1=>p2 e p3 = 0.");
        getMsg()->setErro(true);
    }else{
        nome = "Distribuição Normal";
    }
}

double normal::gerarAleatorio()
{
    std::normal_distribution<double> d(param1,param2);
    return d(random);
}
}  // namespace model
