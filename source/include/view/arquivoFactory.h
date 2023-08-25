#ifndef ARQUIVOFACTORY_H
#define ARQUIVOFACTORY_H

#include "arquivo.h"
#include "csv.h"
#include "txt.h"

namespace view
{
class arquivoFactory
{
    public:
        arquivoFactory();
        arquivo* criar(string a);
};
}
#endif // ARQUIVOFACTORY_H
