#include "../../include/control/mensagem.h"

namespace control
{

mensagem::mensagem()
{
    setErro(false);
    mensagem::m.clear();
}

string mensagem::gerarSaida()
{
    std::stringstream s;
    for (int i=0; i<(mensagem::m.size()); i++){
        s << mensagem::m[i] << "\n";
    }
    return s.str();
}

void mensagem::inserirMsg(string t)
{
    mensagem::m.push_back(t);
}
bool mensagem::isErro()
{
    return mensagem::erro;
}

void mensagem::setErro(bool e)
{
    mensagem::erro = e;
}
}  // namespace control
