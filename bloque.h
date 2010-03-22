#ifndef BLOQUE_H_INCLUDED
#define BLOQUE_H_INCLUDED
#include "SDL.h"
#include "visual.h"
//using namespace flojoEngine;

class cBloque
{
    public:
        cBloque();
        cBloque(int color);
        ~cBloque();
        SDL_Rect * GetBox(int box);
        void DibujarBloque();
        void SetX(uint32_t x);
        void SetY(uint32_t y);
        void SetXY(uint32_t x, uint32_t y);
        uint32_t GetX();
        int GetY();
        bool EstaVisible();
        void Invisible();
        static bool CheckColision(SDL_Rect * A, SDL_Rect * B);
    private:
        int32_t m_posX; //posision en X
        int32_t m_posY; //posicion en Y
        bool m_visible;
        SDL_Surface *m_surfaceBloque; //superficie donde se pinta el bloque
        SDL_Rect m_contColision[5]; //contenedores para chequear colisiones y un conenedor central para el sprite

        void AcomodarBloque(); //setea las coordenadas y la longitud del bloque y los contenedores


};

#endif // BLOQUE_H_INCLUDED
