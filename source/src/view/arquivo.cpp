#include "../../include/view/arquivo.h"

namespace view
{
arquivo::arquivo()
{
    msg = new control::mensagem();
    stringstream currentDateTime;
    // current date/time based on current system
    time_t ttNow = time(0);
    tm * ptmNow;
    ptmNow = localtime(&ttNow);
    //year
    currentDateTime << 1900 + ptmNow->tm_year;
    //month
    if (ptmNow->tm_mon < 9)
        //Fill in the leading 0 if less than 10
        currentDateTime << "0" << 1 + ptmNow->tm_mon;
    else
        currentDateTime << (1 + ptmNow->tm_mon);
    //day
    if (ptmNow->tm_mday < 10)
        currentDateTime << "0" << ptmNow->tm_mday << " ";
    else
        currentDateTime <<  ptmNow->tm_mday << " ";
    //hour
    if (ptmNow->tm_hour < 10)
        currentDateTime << "0" << ptmNow->tm_hour;
    else
        currentDateTime << ptmNow->tm_hour;
    //min
    if (ptmNow->tm_min < 10)
        currentDateTime << "0" << ptmNow->tm_min;
    else
        currentDateTime << ptmNow->tm_min;
    //sec
    if (ptmNow->tm_sec < 10)
        currentDateTime << "0" << ptmNow->tm_sec;
    else
        currentDateTime << ptmNow->tm_sec;

    nome = currentDateTime.str();
}

control::mensagem* arquivo::getMsg()
{
    return msg;
}

void arquivo::lerArquivo()
{
}

void arquivo::escreverArquivo()
{
}

void arquivo::setNome(string n)
{
    nome = n;
}
string arquivo::getNome()
{
    return nome;
}

void arquivo::setDados(view* d)
{
    dados = d;
    if (d->getImportEnd()!=""){
        nome = d->getImportEnd();
    }
}

view* arquivo::getDados()
{
    return dados;
}

}  // namespace view
