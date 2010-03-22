#ifndef VISUAL_H_INCLUDED
#define VISUAL_H_INCLUDED

#ifdef __cplusplus
#include <cstdlib>
#include <iostream>
#include <string>
#else
#include <stdlib.h>
#endif
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#include "SDL_image.h"
#endif

using namespace std;
namespace flojoEngine
{
    class visual //clase singleton que parece andar, eaea!
    {
    public:
        static visual *init_visual(); //devuelve la direccion de la instancia del gestor
        virtual ~visual(); //destructor
        //crea la pantalla
        void crear_pantalla(int ancho, int alto, int bpp, uint32_t flags);
        //devuelve la direccion de la pantalla
        SDL_Surface * pantalla();
        //carga un archivo de imagen
        SDL_Surface * cargar_imagen(string ruta);
        //carga una imagen y le setea eñ colorkey
        SDL_Surface * cargar_imagen(string ruta, uint32_t colorkey);
        //limpia la pantalla con el color especificado
        void limpia_pantalla(uint8_t R, uint8_t G, uint8_t B);
        //dibuja en pantalla

        // Actualiza la pantalla
        void actualizar_pantalla();
        // Libera surface
        void liberar_superficie(SDL_Surface * sup);

    private:
        SDL_Surface * m_pantalla;//pantalla principal
        static visual * m_instancia; //puntero que guarda la direccion en memoria de la instancia
        visual(); //constructor privado


    };
}

#endif // VISUAL_H_INCLUDED
