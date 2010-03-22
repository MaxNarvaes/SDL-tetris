#ifndef PIEZAI_H_INCLUDED
#define PIEZAI_H_INCLUDED
#include "pieza.h"

class piezaI : public pieza
{
    public:
        piezaI();
        piezaI(uint16_t x, uint16_t y);

        void MoverIzq();
        void MoverDer();
        void EnJuego();

        void dibujarPieza();
        virtual void RotarPieza();

    private:

        void inizializarPieza();


};

#endif // PIEZAI_H_INCLUDED
