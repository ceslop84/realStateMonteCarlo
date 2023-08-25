#ifndef VIEW_ARQUIVO_H
#define VIEW_ARQUIVO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <ctime>

#include "../../include/control/mensagem.h"
#include "../../include/view/view.h"

namespace view
{
class arquivo
{
private:
    string nome;
    view* dados;

public:
    arquivo();
    control::mensagem* msg;
	virtual void lerArquivo();
	virtual void escreverArquivo();
	control::mensagem* getMsg();
    void setDados(view* d);
	view* getDados();
	void setNome(string n);
	string getNome();
};

}  // namespace view
#endif
