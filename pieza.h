#ifndef PIEZA_H_INCLUDED
#define PIEZA_H_INCLUDED
#include "bloque.h"
#include "defs.h"

class pieza
{

    public:
        pieza();

        virtual void dibujarPieza();
        void SetXY(uint16_t X, uint16_t Y);
        void SetX(uint16_t X);
        void SetY(uint16_t Y);
        uint16_t GetY();
        virtual void RotarPieza();
        virtual void MoverIzq(); // si se puede lo mueve a la izquierda
        virtual void MoverDer(); // si se puede lo mueve a la derecha
        virtual void EnJuego(); //pone la pieza en juego: en movimiento descendente
        bool EstaVisible();
        void Bajar(); //FIXME cambiar nombre
        void DownUp();
        void Map();
        void UnMap();
        bool GetEstado(); //devuelve si la pieza esta activa o no
        virtual bool CheckColision(pieza * p);
        cBloque * GetBloque(int bloque);
        bool DestruirBloque(uint16_t y); //destruye un bloque en la coordenada deseada
        void Linea(int y);


    protected:
        int timer;
        int factor;
        uint16_t y;
        uint16_t m_coordX; //coordenadas del bloque central
        uint16_t m_coordY; //coordenadas del bloquecentral
        uint8_t m_estadoRotacion; //estado de rotacion d ela pieza
        bool m_estadoPieza; //si esta en juego o no
        virtual void inizializarPieza(); //setea la forma de la pieza dependiendo el estado de rotacion
        cBloque m_pieza[BLOQUES_POR_PIEZA]; //array de bloques que conforman la pieza (4)
};

#endif // PIEZA_H_INCLUDED
