#ifndef VIEW_VIEW_WX_H
#define VIEW_VIEW_WX_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <sstream>

#include "../../include/view/view.h"


namespace view
{
class viewCmd : public view
{
public:
    viewCmd();
	void lerDados();
	void carregarDados();
	void exibirDados();
	void exibirResSmc();
	void exibirResAvef();
};
}  // namespace view
#endif
