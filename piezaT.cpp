#include "defs.h"
//#include "pieza.h"
#include "piezaT.h"
#include <iostream>
using namespace std;



piezaT::piezaT() : pieza()
{
    for (int i=0; i<BLOQUES_POR_PIEZA; i++)
    {
        this->m_pieza[i] = VERDE;
    }
    m_estadoRotacion = 0;
    this->SetXY(0, 0);
    inizializarPieza();
}



piezaT::piezaT(uint16_t X, uint16_t Y) : pieza()
{
    for (int i=0; i<BLOQUES_POR_PIEZA; i++)
    {
        this->m_pieza[i] = VERDE;
    }


    this->m_estadoRotacion = 0;
    this->SetXY(X, Y);
    inizializarPieza();
}



void piezaT::RotarPieza()
{
    if(this->m_estadoPieza) //si a pieza esta en juego podemos rotarla
    {
        switch (this->m_estadoRotacion)
        {
            //para entender mejor esto ver piezaT::inicializarPieza()
            case 0: //girarla en sentido del reloj
            {
                m_estadoRotacion++;
                break;
            }
            case 1: //girarla otra vez
            {
                if( this->m_coordX + ANCHO_BLOQUE >= BOUNDX_GAME_SCREEN_DER) //si girarla supone dibujar un bloque fuera
                    this->m_coordX -= ANCHO_BLOQUE; // moverlo a la izquierda un bloque
                m_estadoRotacion++; //y girarlo
                break;
            }
            case 2: //girarla otra vez
            {
                m_estadoRotacion++;
                break;
            }
            case 3: //volver al estado inicial
            {
                if( this->m_coordX - ANCHO_BLOQUE < BOUNDX_GAME_SCREEN_IZQ)//si girarla supone dibujar un bloque fuera
                    this->m_coordX += ANCHO_BLOQUE; // moverlo a la derecha un bloque
                m_estadoRotacion = 0;
                break;
            }
        }
    }


}

void piezaT::inizializarPieza()
{
    /* los bloques estan distribuidos de esta forma
    *          [0]->bloque central
    *
    *       [1][0][3]
    *          [2]
    *
    */
    this->m_pieza[0].SetXY(this->m_coordX, this->m_coordY); //mantener las coordenadas del bloque central
    switch (this->m_estadoRotacion)
    {
    case 0:
        /* dibujar esto en estado inicial
        *
        *       [1][0][3]
        *          [2]
        */

        this->m_pieza[1].SetXY(this->m_coordX - ANCHO_BLOQUE, this->m_coordY);
        this->m_pieza[2].SetXY(this->m_coordX , this->m_coordY + ANCHO_BLOQUE);
        this->m_pieza[3].SetXY(this->m_coordX + ANCHO_BLOQUE, this->m_coordY );
        break;

    case 1:
        /* dibujar esto si la gira una vez
        *     [1]
        *  [2][0]
        *     [3]
        */

        this->m_pieza[3].SetXY(this->m_coordX, this->m_coordY + ANCHO_BLOQUE);
        this->m_pieza[2].SetXY(this->m_coordX - ANCHO_BLOQUE, this->m_coordY);
        this->m_pieza[1].SetXY (this->m_coordX, this->m_coordY -ANCHO_BLOQUE);
        break;
    case 2:
        /* dibujar esto si la gira de vuelta
        *     [2]
        *  [3][0][1]
        *
        */

        this->m_pieza[3].SetXY(this->m_coordX - ANCHO_BLOQUE, this->m_coordY);
        this->m_pieza[2].SetXY(this->m_coordX, this->m_coordY -ANCHO_BLOQUE);
        this->m_pieza[1].SetXY (this->m_coordX + ANCHO_BLOQUE, this->m_coordY);
        break;
    case 3:
        /* dibujar esto si la vuelve a girar
        *   [3]
        *   [0][2]
        *   [1]
        */
        this->m_pieza[3].SetXY(this->m_coordX , this->m_coordY - ANCHO_BLOQUE);
        this->m_pieza[2].SetXY(this->m_coordX + ANCHO_BLOQUE, this->m_coordY);
        this->m_pieza[1].SetXY (this->m_coordX, this->m_coordY + ANCHO_BLOQUE);
        break;
    }

}

void piezaT::MoverDer()
{
    if(this->m_estadoPieza) //si la pieza esat en juego podemos moverla
    {
        if(this->m_coordX + ANCHO_BLOQUE * 2 < BOUNDX_GAME_SCREEN_DER)
            pieza::MoverDer();

        else if (this->m_estadoRotacion == 1 && this->m_coordX + ANCHO_BLOQUE < BOUNDX_GAME_SCREEN_DER)
            pieza::MoverDer();
    }

}

void piezaT::MoverIzq()
{
    if(this->m_estadoPieza) //si la pieza esat en juego podemos moverla
    {
        if(this->m_coordX - ANCHO_BLOQUE > BOUNDX_GAME_SCREEN_IZQ)
            pieza::MoverIzq();

        else if (this->m_estadoRotacion == 3 && this->m_coordX > BOUNDX_GAME_SCREEN_IZQ)
            pieza::MoverIzq();
    }

}

void piezaT::EnJuego()
{
    if(this->m_estadoRotacion == 2 && this->m_coordY + ALTO_BLOQUE < BOUNDY_GAME_SCREEN_ABAJO)
        pieza::EnJuego();
    else if( this->m_coordY + ALTO_BLOQUE * 2 < BOUNDY_GAME_SCREEN_ABAJO)
        pieza::EnJuego();
    else if( this->m_estadoPieza == true)
    {
        this->m_estadoPieza = false;
        cout<<"toco fondo en: " << this->m_coordY << endl;
    }
}

void piezaT::dibujarPieza()
{
    if (this->m_estadoPieza)
        this->inizializarPieza(); //mantener la forma del bloque T
    pieza::dibujarPieza();// dibujarla bloque por bloque
}
