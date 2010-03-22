
#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED



//Constantes de bloque
enum contenedorBlock { CENTRO, ARRIBA, ABAJO, IZQUIERDA, DERECHA };
enum medidasBlock { ALTO_BLOQUE = 20 , ANCHO_BLOQUE = 20 };
enum colorBlock { VERDE, ROJO, AMARILLO, AZUL, NARANJA, VIOLETA, BLANCO };

const int BLOQUES_POR_PIEZA = 4;//Cnstante de pieza
const int BOUNDX_GAME_SCREEN_IZQ = 200; // Límite para la pantalla de juego (donde se mueven los blocks)
const int BOUNDX_GAME_SCREEN_DER = 460;// Límite para la pantalla de juego (donde se mueven los blocks)
const int BOUNDY_GAME_SCREEN_ARRIBA = 60;
const int BOUNDY_GAME_SCREEN_ABAJO = 460;

//constantes de fabrica de piezas
enum tipoPieza { PIEZA_O, PIEZA_T, PIEZA_I};



#endif // DEFS_H_INCLUDED
