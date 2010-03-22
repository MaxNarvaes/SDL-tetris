#ifndef GLOBALS_H_INCLUDED
    #define GLOBALS_H_INCLUDED
#ifndef VISUAL_H_INCLUDED
    #include "visual.h"
#endif

using namespace flojoEngine;
//GLOBALS
visual *g_gestorVideo = visual::init_visual(); //singleton del gestor de video
int mapa[13][20] = {{0}, {0}}; //esto va en objeto game
#endif // GLOBALS_H_INCLUDED
