#include "bloque.h"
#include "defs.h"
#ifndef VISUAL_H_INCLUDED
    #include "visual.h"
#endif
#include "globals.h"

//using namespace flojoEngine;

extern visual *g_gestorVideo;

cBloque::cBloque()
{
    AcomodarBloque(); // setea las coordenadas y la longitud del bloque y los contenedores
    this->m_surfaceBloque = NULL;
    this->m_visible=true;
}
cBloque::~cBloque()
{
    this->m_posX = 0;
    this->m_posY = 0;

}
SDL_Rect * cBloque::GetBox(int box)
{
    return &this->m_contColision[box];
}

bool cBloque::CheckColision(SDL_Rect * A, SDL_Rect * B)
{
    if( A->y == B->y +5 && A->x == B->x)
    {
        //A->y = B->y + 5;
        return true;
    }




    /*if( ( A->x > B->x ) && ( A->x < B->w + B->x ) && ( A->y > B->y ) && ( A->y < B->h + B->y ) )
	{
		return true;
	}
	if( ( A->x + A->w > B->x ) && ( A->x + A->w < B->w + B->x ) && ( A->y > B->y ) && ( A->y < B->h + B->y ) )
	{
		return true;
	}
	if( ( A->x > B->x ) && ( A->x < B->w + B->x ) && ( A->y + A->h > B->y ) && ( A->y + A->h < B->h + B->y ) )
	{
		return true;
	}
	if( ( A->x + A->w > B->x ) && ( A->x + A->w < B->w + B->x ) && ( A->y + A->h > B->y ) && ( A->y + A->h < B->h + B->y ) )
	{
		return true;
	}

	if( ( B->x > A->x ) && ( B->x < A->w + A->x ) && ( B->y > A->y ) && ( B->y < A->h + A->y ) )
	{
		return true;
	}
	if( ( B->x + B->w > A->x ) && ( B->x + B->w < A->w + A->x ) && ( B->y > A->y ) && ( B->y < A->h + A->y ) )
	{
		return true;
	}
	if( ( B->x > A->x ) && ( B->x < A->w + A->x ) && ( B->y + B->h > A->y ) && ( B->y + B->h < A->h + A->y ) )
	{
		return true;
	}
	if( ( B->x + B->w > A->x ) && ( B->x + B->w < A->w + A->x ) && ( B->y + B->h > A->y ) && ( B->y + B->h < A->h + A->y ) )
	{
		return true;
	}

	if( ( ( A->x == B->x ) && ( A->x + A->w == B->x + B->w ) ) && ( ( ( A->y > B->y ) && ( A->y < B->h + B->y ) ) || ( ( A->y + A->h > B->y ) && ( A->y + A->h < B->h + B->y ) ) ) )
	{
		return true;
	}

	if( ( ( A->y == B->y ) && ( A->y + A->h == B->y + B->h ) ) && ( ( ( A->x > B->x ) && ( A->x < B->w + B->x ) ) || ( ( A->x + A->w > B->x ) && ( A->x + A->w < B->w + B->x ) ) ) )
	{
		return true;
	}

	if( ( ( B->x == A->x ) && ( B->x + B->w == A->x + A->w ) ) && ( ( ( B->y > A->y ) && ( B->y < A->h + A->y ) ) || ( ( B->y + B->h > A->y ) && ( B->y + B->h < A->h + A->y ) ) ) )
	{
		return true;
	}

	if( ( ( B->y == A->y ) && ( B->y + B->h == A->y + A->h ) ) && ( ( ( B->x > A->x ) && ( B->x < A->w + A->x ) ) || ( ( B->x + B->w > A->x ) && ( B->x + B->w < A->w + A->x ) ) ) )
	{
		return true;
	}

	if( ( A->x == B->x ) && ( A->y == B->y ) && ( A->w == B->w ) && ( A->h == B->h ) )
	{
        return true;
    }*/

	return false;
}

cBloque::cBloque(int color)
{
    AcomodarBloque();
    this->m_visible=true;
    switch(color)
    {
        case VERDE:
            this->m_surfaceBloque = g_gestorVideo->cargar_imagen("verde.png");
            break;
        case ROJO:
            this->m_surfaceBloque = g_gestorVideo->cargar_imagen("rojo.png");
            break;
        case AMARILLO:
            this->m_surfaceBloque = g_gestorVideo->cargar_imagen("amarillo.png");
            break;
        case AZUL:
            this->m_surfaceBloque = g_gestorVideo->cargar_imagen("azul.png");
            break;
        default:
            break;
    }

}

void cBloque::AcomodarBloque()
{
    /*   ___
    *  _|___|_
    * | |   | |  <---------- quedaría algo así, las cajas de los costados estan para detectar colisiones
    * |_|___|_|              la del medio muestra el sprite
    *   |___|
    */
    //m_contColision = contenedor de colisiones = contenedor para comprobar las colisiones
    this->m_contColision[CENTRO].x=this->m_posX; //las coordenadas (x,y) a cero
    this->m_contColision[CENTRO].y=this->m_posY; //porque este bloque se toma como referencia
    this->m_contColision[CENTRO].h=ALTO_BLOQUE; //20 px
    this->m_contColision[CENTRO].w=ANCHO_BLOQUE; //20 px

    this->m_contColision[ARRIBA].x = this->m_contColision[CENTRO].x; //en la misma posicion de CENTRO
    this->m_contColision[ARRIBA].y = this->m_contColision[CENTRO].y - ALTO_BLOQUE / 4; //pero 5px más arriba
    this->m_contColision[ARRIBA].h = ALTO_BLOQUE /4; //mas fino (5px) tambien
    this->m_contColision[ARRIBA].w = ANCHO_BLOQUE; //pero con el mismo ancho

    int prueba;
    this->m_contColision[ABAJO].x = this->m_contColision[CENTRO].x;
    this->m_contColision[ABAJO].y = this->m_contColision[CENTRO].y + ALTO_BLOQUE;
    this->m_contColision[ABAJO].h = ALTO_BLOQUE / 4;
    this->m_contColision[ABAJO].w = ANCHO_BLOQUE;
    prueba = this->m_contColision[ABAJO].y + ALTO_BLOQUE;

    this->m_contColision[IZQUIERDA].x = this->m_contColision[CENTRO].x - ANCHO_BLOQUE / 4; //5px a la izq
    this->m_contColision[IZQUIERDA].y = this->m_contColision[CENTRO].y; //a la misma altura de CENTRO
    this->m_contColision[IZQUIERDA].h = ALTO_BLOQUE;
    this->m_contColision[IZQUIERDA].w = ANCHO_BLOQUE / 4;

    this->m_contColision[DERECHA].x = this->m_contColision[CENTRO].x + ANCHO_BLOQUE;
    this->m_contColision[DERECHA].y = this->m_contColision[CENTRO].y;
    this->m_contColision[DERECHA].w = ANCHO_BLOQUE / 4;
    this->m_contColision[DERECHA].h = ALTO_BLOQUE;


}

void cBloque::DibujarBloque()
{

    SDL_BlitSurface(cBloque::m_surfaceBloque, 0, g_gestorVideo->pantalla(), &this->m_contColision[CENTRO]);
}

void cBloque::SetX(uint32_t x)
{
    this->m_posX = x;
    this->AcomodarBloque();
}

void cBloque::SetY(uint32_t y)
{
    this->m_posY = y;
    this->AcomodarBloque();
}

void cBloque::SetXY(uint32_t x, uint32_t y)
{
    this->m_posX = x;
    this->m_posY = y;
    this->AcomodarBloque();
}

uint32_t cBloque::GetX()
{
    return this->m_posX;
}

void cBloque::Invisible()
{
    this->m_visible = false;
}

int cBloque::GetY()
{
    return this->m_posY;
}

bool cBloque::EstaVisible()
{
    return this->m_visible;
}
/*cBloque * cBloque::getBloque(contBlocks posicion)
{

}*/
