#ifndef CONTROL_MENSAGEM_H
#define CONTROL_MENSAGEM_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <sstream>

using namespace std;

namespace control
{
class mensagem
{
private:
	bool erro;
	vector<string> m;

public:
    mensagem();
	string gerarSaida();
	void inserirMsg(string t);
	bool isErro();
	void setErro(bool e);
};

}  // namespace control
#endif
