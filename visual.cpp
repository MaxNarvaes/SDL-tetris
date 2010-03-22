#ifndef VISUAL_CPP_INCLUDED
#define VISUAL_CPP_INCLUDED

#include "visual.h"
namespace flojoEngine
{
//para usar la variable static la tengo que declarar :S de vuelta
    visual * visual::m_instancia;

    visual * visual::init_visual()
    {
        if (!m_instancia)
        {
            m_instancia = new visual();

        }
        return m_instancia;
    }

    visual::visual()
    {
        m_instancia = NULL;
        this->m_pantalla = NULL;
    }

    visual::~visual()
    {
        delete m_instancia;//no se cual de las dos opciones usar
        m_instancia = NULL;

    }

    void visual::crear_pantalla(int ancho, int alto, int bpp, uint32_t flags)
    {
        this->m_pantalla = SDL_SetVideoMode(ancho, alto, bpp, flags); //esta funcion en realidad no sirve para un choto
        if (!m_pantalla) cout << "Error: " << SDL_GetError();

    }

    SDL_Surface * visual::pantalla()
    {
        return this->m_pantalla;
    }

//carga una imagen y le setea el color key
    SDL_Surface * visual::cargar_imagen(string ruta, uint32_t colorkey)
    {
        SDL_Surface *temp; //puntero temporal donde se guarda la dir del surface
        temp = IMG_Load(ruta.c_str()); //cargo la imagen
        temp = SDL_DisplayFormat(temp); // y la optimizo
        SDL_SetColorKey(temp, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey); //seteo el color key
        return temp; //devulevo la imagen joya
    }
//carga una imagen y nada mas
    SDL_Surface * visual::cargar_imagen(string ruta)
    {
        SDL_Surface *temp; //puntero temporal donde se guarda la dir del surface
        temp = IMG_Load(ruta.c_str()); //cargo la imagen
        if(!temp) cout << "ERROR AL CARGAR IMAGEN"<< endl;
        temp = SDL_DisplayFormat(temp); // y la optimizo
        return temp; //devuelvo la img optimizada
    }

    void visual::limpia_pantalla(uint8_t R, uint8_t G, uint8_t B)
    {
        SDL_FillRect(this->m_pantalla, 0, SDL_MapRGB(this->m_pantalla->format, R, G, B));
    }

    void visual::actualizar_pantalla()
    {
        SDL_Flip(this->m_pantalla);
    }

    void visual::liberar_superficie(SDL_Surface * sup)
    {
        SDL_FreeSurface(sup);
    }
}
#endif // VISUAL_CPP_INCLUDED
