#include "piezaO.h"

piezaO::piezaO() : pieza()
{
    for (int i=0; i<BLOQUES_POR_PIEZA; i++)
    {
        this->m_pieza[i] = ROJO;
    }
    m_estadoRotacion = 0;
    this->SetXY(0, 0);
    this->inizializarPieza();
}

piezaO::piezaO(uint16_t x, uint16_t y) : pieza()
{
    for (int i=0; i<BLOQUES_POR_PIEZA; i++)
    {
        this->m_pieza[i] = ROJO;
    }
    /*this->m_pieza[0] = ROJO;
    this->m_pieza[1] = VERDE;
    this->m_pieza[2] = AZUL;
    this->m_pieza[3] = AMARILLO;*/
    this->m_estadoRotacion = 0;
    this->SetXY(x, y);
    this->inizializarPieza();
}

void piezaO::inizializarPieza()
{
    /* necesito dibujar esto
    *
    *  [0][1]
    *  [2][3]
    */
    this->m_pieza[0].SetXY( this->m_coordX, this->m_coordY);
    this->m_pieza[1].SetXY( this->m_coordX + ANCHO_BLOQUE, this->m_coordY);
    this->m_pieza[2].SetXY( this->m_coordX, this->m_coordY + ANCHO_BLOQUE);
    this->m_pieza[3].SetXY( this->m_coordX + ANCHO_BLOQUE, this->m_coordY + ANCHO_BLOQUE);

}

void piezaO::RotarPieza()
{

}

void piezaO::EnJuego()
{
    if(this->m_coordY + ALTO_BLOQUE * 2 < BOUNDY_GAME_SCREEN_ABAJO)
        pieza::EnJuego();
    else
        this->m_estadoPieza = false;
}

void piezaO::dibujarPieza()
{
    if (this->m_estadoPieza)
        this->inizializarPieza();
    pieza::dibujarPieza();
}

void piezaO::MoverDer()
{
    if( this->m_coordX + ANCHO_BLOQUE * 2 < BOUNDX_GAME_SCREEN_DER && this->m_estadoPieza == true)
        pieza::MoverDer();
}

void piezaO::MoverIzq()
{
    if( this->m_coordX > BOUNDX_GAME_SCREEN_IZQ && this->m_estadoPieza == true)
    {
        pieza::MoverIzq();
    }
}
