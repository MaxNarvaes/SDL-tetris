#ifndef PIEZAO_H_INCLUDED
#define PIEZAO_H_INCLUDED
#include "pieza.h"
#include "defs.h"

class piezaO : public pieza
{
    public:
        piezaO();
        piezaO(uint16_t x, uint16_t y);

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


#endif // PIEZAO_H_INCLUDED
