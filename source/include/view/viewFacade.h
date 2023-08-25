#ifndef VIEW_VIEW_FACADE_H
#define VIEW_VIEW_FACADE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "../../include/view/view.h"
#include "../../include/control/controlFacade.h"
#include "../../include/view/arquivo.h"
#include "../../include/view/arquivoFactory.h"


namespace view{

class viewFacade
{
private:
    control::controlFacade cf;
	view* dados;

public:
	viewFacade();
	void executar();
	void importar();
	void exportar();
	control::controlFacade* getCF();
	view* getDados();
	void setDados(view* v);
};
}
#endif
