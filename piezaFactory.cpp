#include "piezaFactory.h"
#include "pieza.h"
#include "piezaI.h"
#include "piezaO.h"
#include "piezaT.h"

pieza * piezaFactory::NuevaPieza(int tipo, int x, int y)
{
    switch(tipo)
    {
        case PIEZA_I:
            return new piezaI(x, y);
            break;
        case PIEZA_O:
            return new piezaO(x, y);
            break;
        case PIEZA_T:
            return new piezaT(x, y);
            break;
        default:
            return NULL;
            break;
    }
    return NULL;
}
