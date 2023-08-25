#ifndef ZEROFUNDING_H
#define ZEROFUNDING_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "../../include/model/capitalExterno.h"

namespace model
{
class zeroFunding : public capitalExterno
{

public:
    zeroFunding();
    void calcularPrestacoes(double t);
};
}  // namespace model
#endif // ZEROFUNDING_H
