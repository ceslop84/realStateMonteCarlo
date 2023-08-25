#ifndef CAPITALEXTERNOFACTORY_H
#define CAPITALEXTERNOFACTORY_H

#include "../../include/model/capitalExterno.h"
#include "../../include/model/sac.h"
#include "../../include/model/price.h"
#include "../../include/model/zeroFunding.h"

namespace model
{
class capitalExternoFactory
{
    public:
        capitalExternoFactory();
        capitalExterno* criar(double v, string f, double tj, string sa, int p, double ts, double cc, string d, double p1, double p2, double p3);
};
}  // namespace model
#endif // CAPITALEXTERNOFACTORY_H
