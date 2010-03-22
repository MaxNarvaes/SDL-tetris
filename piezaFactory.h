#ifndef PIEZAFACTORY_H_INCLUDED
#define PIEZAFACTORY_H_INCLUDED
#include "pieza.h"
#include "defs.h"

class piezaFactory
{
    public:
        pieza *NuevaPieza(int tipo, int x, int y);

};

#endif // PIEZAFACTORY_H_INCLUDED
