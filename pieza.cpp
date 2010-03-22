#include "pieza.h"
#include "bloque.h"
#include "defs.h"
#include <iostream>
#include "SDL.h"
using namespace std;
extern int mapa[13][20];

pieza::pieza()
{
    timer = SDL_GetTicks();
    this->m_estadoPieza = true;
    this->m_estadoRotacion = 0;
    this->SetXY(0, 0);
    this->inizializarPieza();
    this->y = BOUNDY_GAME_SCREEN_ARRIBA;
    factor = 20;
}

void pieza::SetXY( const uint16_t X, const uint16_t Y)
{
    //this->y = this->m_coordY;
    this->m_coordX = X;
    this->m_coordY = Y;
    this->m_pieza[CENTRO].SetXY(X, Y);

}

void pieza::RotarPieza()
{
}

void pieza::inizializarPieza()
{

}

void pieza::dibujarPieza()
{
    for (int i=0; i<BLOQUES_POR_PIEZA; i++)
    {
        if(this->m_pieza[i].EstaVisible())
            this->m_pieza[i].DibujarBloque();
    }
}

bool pieza::DestruirBloque(uint16_t y)
{
    bool resultado = false;
    for (int i=0; i<BLOQUES_POR_PIEZA; i++)
    {
        if(this->m_pieza[i].GetY() == y)
        {
            this->m_pieza[i].Invisible();
            resultado = true;
        }
    }
    return resultado;
}

bool pieza::GetEstado()
{
    return this->m_estadoPieza;
}

void pieza::SetX(uint16_t x)
{
    this->m_coordX = x;
}

void pieza::SetY(uint16_t y)
{
    this->m_coordY = y;
}

void pieza::Bajar()
{
    this->factor = 1;
}
void pieza::DownUp()
{
    this->factor = 20;
}

void pieza::MoverDer()
{
    this->SetX(this->m_coordX + ANCHO_BLOQUE);
}

void pieza::MoverIzq()
{
    this->SetX(this->m_coordX - ANCHO_BLOQUE);
}

cBloque * pieza::GetBloque(int bloque)
{
    return &this->m_pieza[bloque];
}

uint16_t pieza::GetY()
{
    return this->m_coordY;
}

bool pieza::CheckColision(pieza * p)
{

if(this->m_estadoPieza==true)
{
    SDL_Rect *A;
    SDL_Rect *B;

    for(int i=0; i<BLOQUES_POR_PIEZA; i++)
    {
        if(this->m_pieza[i].EstaVisible())
        {
            A= this->m_pieza[i].GetBox(ABAJO);
            for(int j=0; j<BLOQUES_POR_PIEZA; j++)
            {
                if(p->GetBloque(j)->EstaVisible())
                {
                    B=p->GetBloque(j)->GetBox(ARRIBA);

                    if(cBloque::CheckColision(A, B))
                    {
                        this->m_estadoPieza = false;
                        //cout << "colision"<<endl;
                        //this->PosMap();
                        //this->Map();
                        return true;
                    }
                }
            }
        }
    }

}
    return false;
}

void pieza::Linea(int y)
{
    for(int i = 0; i<BLOQUES_POR_PIEZA; i++)
    {
        bool visible = this->m_pieza[i].EstaVisible();
        int alto=this->m_pieza[i].GetY();
        if( visible == true && alto <= y )
        {
            this->m_pieza[i].SetY(this->m_pieza[i].GetY() + 20);
        }
    }
    //this->Map();
}

void pieza::EnJuego()
{

    if(this->m_estadoPieza)
    {
        int timer2 = SDL_GetTicks();

        if(timer2 - timer > factor)
        {
        this->SetY(y);
        this->y+=1;
        timer = SDL_GetTicks();
        }
        //if(y>430)
        //cout << "en juego " << this->m_coordY << endl;
    }
    //else
    //this->Map();




}

void pieza::Map()
{
    int x, y;
    for(int i=0; i<BLOQUES_POR_PIEZA; i++)
    {
        if(this->m_pieza[i].EstaVisible())
        {
            x = (BOUNDX_GAME_SCREEN_DER - this->m_pieza[i].GetX()) / ANCHO_BLOQUE;
            y = (BOUNDY_GAME_SCREEN_ABAJO - this->m_pieza[i].GetY()) / ALTO_BLOQUE;
            mapa[x-1][y-1] = 1;
            //cout <<mapa [x-1][y-1]<<endl;
        }
    }
    cout << &mapa << "map"<< endl;
}

void pieza::UnMap()
{
    int x, y;
    for(int i=0; i<BLOQUES_POR_PIEZA; i++)
    {
        if(this->m_pieza[i].EstaVisible())
        {
            x = (BOUNDX_GAME_SCREEN_DER - this->m_pieza[i].GetX()) / ANCHO_BLOQUE;
            y = (BOUNDY_GAME_SCREEN_ABAJO - this->m_pieza[i].GetY()) / ALTO_BLOQUE;
            mapa[x-1][y-1] = 0;
            //cout <<mapa [x-1][y-1]<<endl;
        }
    }
    cout << &mapa << "map"<< endl;
}

bool pieza::EstaVisible()
{
    for (int i=0; i<BLOQUES_POR_PIEZA; i++)
    {
        if( this->m_pieza[i].EstaVisible())
            return true;
    }
    return false;
}
