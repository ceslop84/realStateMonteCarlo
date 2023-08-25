#include "../../include/model/distribuicao.h"

namespace model
{

distribuicao::distribuicao()
{
    nome = "";
    param1 = 0;
    param2 = 0;
    param3 = 0;
    msg = new control::mensagem();
}

distribuicao::distribuicao(double p1, double p2, double p3):distribuicao()
{
    param1 = p1;
    param2 = p2;
    param3 = p3;
}

double distribuicao::gerarAleatorio()
{
    return 0;
}

control::mensagem* distribuicao::getMsg()
{
    return msg;
}

}  // namespace model
