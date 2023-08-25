#ifndef DISTRIBUICAOFACTORY_H
#define DISTRIBUICAOFACTORY_H

#include "../../include/model/distribuicao.h"
#include "../../include/model/normal.h"
#include "../../include/model/uniforme.h"

namespace model
{
class distribuicaoFactory
{
    public:
        distribuicaoFactory();
        distribuicao* criar(string d, double p1, double p2, double p3);
};
}  // namespace model
#endif // DISTRIBUICAOFACTORY_H
