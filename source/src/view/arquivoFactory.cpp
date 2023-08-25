#include "../../include/view/arquivoFactory.h"

namespace view
{
arquivoFactory::arquivoFactory()
{
}

arquivo* arquivoFactory::criar(string tipo)
{
    arquivo* saida = new arquivo();
    if ((tipo == "CSV")|(tipo == "csv")){
        saida = new csv();
    } else if((tipo == "TXT")|(tipo == "txt")){
        saida = new txt();
    } else{
        saida->getMsg()->inserirMsg("Formato de aquivo não cadastrado");
        saida->getMsg()->setErro(true);
    }
    return saida;
}
}
