#include "defs.h"
#include "pieza.h"
#include "piezaI.h"

piezaI::piezaI() : pieza()
{
    for (int i = 0; i<BLOQUES_POR_PIEZA; i++)
    {
        this->m_pieza[i] = AMARILLO;
    }
}

piezaI::piezaI(uint16_t x, uint16_t y) : pieza()
{
    for (int i = 0; i<BLOQUES_POR_PIEZA; i++)
    {
        this->m_pieza[i] = AMARILLO;
    }

    this->SetXY(x, y);
    this->inizializarPieza();
}

void piezaI::RotarPieza()
{
    if(this->m_estadoPieza) //si la pieza esta en juego
    {
        if (this->m_estadoRotacion == 0)
        {
            if(this->m_coordX + ANCHO_BLOQUE * 2 > BOUNDX_GAME_SCREEN_DER)
                this->m_coordX = BOUNDX_GAME_SCREEN_DER - ALTO_BLOQUE * 2;
            this->m_estadoRotacion++;
        }
        else if (this->m_estadoRotacion == 1)
        {
            if(this->m_coordX - ANCHO_BLOQUE * 2 < BOUNDX_GAME_SCREEN_IZQ) //si girarlo dibuja bloques fuera
                this->m_coordX = BOUNDX_GAME_SCREEN_IZQ + ANCHO_BLOQUE * 2; //asegurar que todo quede dentro
            else if( this->m_coordX + ANCHO_BLOQUE * 2 > BOUNDX_GAME_SCREEN_DER)
                this->m_coordX = BOUNDX_GAME_SCREEN_DER - ANCHO_BLOQUE * 2;

            this->m_estadoRotacion = 0; // y girarlo
        }
    }

}

void piezaI::MoverDer()
{
    if(this->m_estadoPieza == true)
    {
        if( this->m_estadoRotacion == 0 && this->m_coordX + ANCHO_BLOQUE * 2 < BOUNDX_GAME_SCREEN_DER)
            pieza::MoverDer();
        else if(this->m_estadoRotacion == 1 && this->m_coordX + ANCHO_BLOQUE < BOUNDX_GAME_SCREEN_DER)
            pieza::MoverDer();


    }
}

void piezaI::MoverIzq()
{
    if(this->m_estadoPieza == true)
    {
        if(this->m_estadoRotacion == 0 && this->m_coordX - ANCHO_BLOQUE * 2 > BOUNDX_GAME_SCREEN_IZQ)
            pieza::MoverIzq();
        else if(this->m_estadoRotacion == 1 && this->m_coordX > BOUNDX_GAME_SCREEN_IZQ)
            pieza::MoverIzq();
    }

}

void piezaI::EnJuego()
{
    if(this->m_estadoRotacion == 1 && this->m_coordY + ALTO_BLOQUE * 2 < BOUNDY_GAME_SCREEN_ABAJO)
    {
        //this->m_estadoPieza = true;
        pieza::EnJuego();
    }
    else if(this->m_estadoRotacion == 0 && this->m_coordY + ALTO_BLOQUE < BOUNDY_GAME_SCREEN_ABAJO)
    {
        //this->m_estadoPieza = true;
        pieza::EnJuego();
    }
    else
        this->m_estadoPieza = false;
}

void piezaI::inizializarPieza()
{
    if(this->m_estadoRotacion == 0)
    {
        /* toma esta forma al inicio
        * [3][2][1][0]
        *
        */
        this->m_pieza[0].SetXY(this->m_coordX, this->m_coordY);
        this->m_pieza[1].SetXY(this->m_coordX + ANCHO_BLOQUE, this->m_coordY );
        this->m_pieza[2].SetXY(this->m_coordX - ANCHO_BLOQUE, this->m_coordY);
        this->m_pieza[3].SetXY(this->m_coordX - ANCHO_BLOQUE * 2, this->m_coordY);


    }
    else if(this->m_estadoRotacion == 1)
    {
        /* que tome esta forma
        *   [0]
        *   [1]
        *   [2]
        *   [3]
        */
        this->m_pieza[0].SetXY(this->m_coordX, this->m_coordY);
        this->m_pieza[1].SetXY(this->m_coordX, this->m_coordY + ANCHO_BLOQUE);
        this->m_pieza[2].SetXY(this->m_coordX, this->m_coordY - ANCHO_BLOQUE );
        this->m_pieza[3].SetXY(this->m_coordX, this->m_coordY - ANCHO_BLOQUE * 2);
    }
}

void piezaI::dibujarPieza()
{
    if (this->m_estadoPieza)
        this->inizializarPieza();
    pieza::dibujarPieza();
}
