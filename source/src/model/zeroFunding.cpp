#include "../../include/model/zeroFunding.h"

namespace model
{

zeroFunding::zeroFunding():capitalExterno()
{
    distribuicao* d = new uniforme();
	setDist(d);
}

void zeroFunding::calcularPrestacoes(double t)
{
}

}
