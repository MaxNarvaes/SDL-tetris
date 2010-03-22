#ifndef PIEZAT_H_INCLUDED
#define PIEZAT_H_INCLUDED

#include "pieza.h"
#include "visual.h"


class piezaT : public pieza
{
    public:
        piezaT();
        piezaT(uint16_t X, uint16_t Y);

        void MoverIzq();
        void MoverDer();
        void EnJuego();



        void dibujarPieza(); //muestra la pieza en pantalla despues de setear las coord
        virtual void RotarPieza();

    private:
        //uint16_t m_coordX; //coordenadas del primer bloque
        //uint16_t m_coordY; //coordenadas del segundo bloque
        //uint8_t m_estado; //estado de la rotacion de la pieza
        void inizializarPieza();

};

#endif // PIEZAT_H_INCLUDED
