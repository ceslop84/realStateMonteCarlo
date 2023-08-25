#ifndef CONTROL_CONTROL_FACADE_H
#define CONTROL_CONTROL_FACADE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "../../include/control/mensagem.h"
#include "../../include/model/AVEF.h"
#include "../../include/view/view.h"
#include "../../include/model/capitalExterno.h"
#include "../../include/model/capitalExternoFactory.h"

namespace control
{
class controlFacade
{
private:
	mensagem msg;
	model::AVEF* avef;
	void construirModelo(view::view* dados);

public:
	controlFacade();
	void executar(view::view* v);
	control::mensagem* getMsg();
	model::AVEF* getAvef();
	void setAvef(model::AVEF* a);
};

}  // namespace control
#endif
