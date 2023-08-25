#ifndef ARQTEXTO_H
#define ARQTEXTO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <iostream>
#include <fstream>

#include "../../include/view/arquivo.h"

namespace view
{
class arqTexto : public arquivo
{
    protected:
        string sep1, sep2;
        string ext;

    public:
        arqTexto();
        void lerArquivo();
        void escreverArquivo();
};
}  // namespace view
#endif // ARQTEXTO_H
