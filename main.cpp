#ifdef __cplusplus
#include <cstdlib>
#include <iostream>

#else
#include <stdlib.h>
#endif
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#endif
#include "visual.h"
#include "bloque.h"
#include "defs.h"
//#ifndef DEFS_H_INCLUDED
//#include "defs.h"
//#endif
#include <vector>
using namespace std;
using std::vector;
#include "pieza.h"
#include "piezaT.h"
#include "piezaO.h"
#include "piezaI.h"
#include "piezaFactory.h"

using namespace flojoEngine;

extern visual *g_gestorVideo;
double time_scale = 0;
extern int mapa[13][20];

void mostrarMap()
{

    for (int i=20; i>0; i--)
    {
        for (int j=13; j>0; j--)
        {
            cout<< mapa[j-1][i-1] << " ";
        }
        cout << endl;

    }
    cout << "******************************" << endl;
}


int main ( int argc, char** argv )
{

    //pieza piez;
    piezaFactory factory;
    //piezaO  PI1(0,0);
    //piezaO PI2(0,0);
    vector<pieza*> P;
    cout << &mapa<<endl;






    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);
    srand(SDL_GetTicks());


    SDL_Rect temp;
    temp.x=0;
    temp.y=0;


    // create a new window
    g_gestorVideo->crear_pantalla(640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF );


    int prev_ticks = 0, cur_ticks = 0; /* for keeping track of timing */

    /* framerate counter variables */
    int start_time, end_time;
    int frames_drawn = 0;

    prev_ticks = SDL_GetTicks();

    start_time = time(NULL);




    bool check;

    SDL_Surface * fondo = g_gestorVideo->cargar_imagen("fondo.png");
    if (!fondo) cout << "ERROR CARGANFO IMANE";
    P.push_back(factory.NuevaPieza(rand() % 3, 300, 0));
    P[P.size()-1]->EnJuego();
    //P[P.size()-1]->SetXY(300,200);
    // program main loop
    bool gameover = false;
    bool done = false;

    while (!done)
    {
        prev_ticks = cur_ticks;
        cur_ticks = SDL_GetTicks();
        time_scale = (double)(cur_ticks-prev_ticks)/30.0;
        // message processing loop
        //g_gestorVideo->limpia_pantalla(0, 0, 0);

        //BORRAR NO VISIBLES
        for (size_t i = 0; i < P.size()-1; i++) //size -1 pq se supone que el mas nuevo esta visible
        {
            if(P[i]->EstaVisible()==false)
            {
                delete P[i];
                P.erase(P.begin()+i);
            }
        }


        //crear nueva pieza
        if (P[P.size()-1]->GetEstado() == false && gameover == false)
        {

            P.push_back(factory.NuevaPieza(rand() % 3, 300, BOUNDY_GAME_SCREEN_ARRIBA));
            P[P.size()-2]->Map();
            //P[P.size()-2]->PosMap[mapa];
            //P[P.size()-1]->SetXY(300,200);
            //P[P.size()-1]->EnJuego();
            //P[P.size()-1]->dibujarPieza();
        }
        //contar lineas y destruir bloques y mapear bloques
        int cont =0;
        for (int y = 0; y < 20; y++)
        {
            for ( int x = 0; x<13; x++)
            {
                if (mapa[x][y] == 1)
                {
                    cont ++;
                }
            }
            if (cont == 13)
            {
                for (int u =0; u<13; u++)
                {
                    mapa[u][y] = 0;

                }
                for (size_t i = 0; i < P.size()-1; i++)
                {

                    P[i]->UnMap();

                    if (P[i]->DestruirBloque(BOUNDY_GAME_SCREEN_ABAJO - ((y + 1) * ALTO_BLOQUE)))
                        P[i]->Linea(BOUNDY_GAME_SCREEN_ABAJO - ((y + 1) * ALTO_BLOQUE));
                    else //if (P[i]->GetY() < (y + 1) * ALTO_BLOQUE)
                        P[i]->Linea(BOUNDY_GAME_SCREEN_ABAJO - ((y + 1) * ALTO_BLOQUE));
                    //P[i]->SetActivo();

                    P[i]->Map();

                }
                //destruir bloques en y
            }
            cont=0;
        }




        // check colision
        if (P.size() > 1) //porqueeeeeeeee
        {

            for (size_t i=P.size(); i>1; i--)
            {
                for (size_t j=P.size(); j>1; j--)
                {
                    pieza * p1 = P[j-1];
                    pieza * p2 = P[i-2];
                    check = p1->CheckColision(p2);
                    //if (check == true)
                    //p1->Map();
                }
            }

        }

        //p1->

        if (P[P.size()-1]->GetEstado() == false && P[P.size()-1]->GetY() < BOUNDY_GAME_SCREEN_ARRIBA + ALTO_BLOQUE)
        {
            gameover = true;
            done = true;
        }
        //for (size_t i = 0; i < P.size(); i++)
            P[P.size()-1]->EnJuego();
        SDL_BlitSurface(fondo, 0, g_gestorVideo->pantalla(), &temp);
        for ( size_t i = 0; i<P.size(); i++)
            P[i]->dibujarPieza();

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
            {
                // exit if ESCAPE is pressed
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    done = true;
                    break;
                }

                if (event.key.keysym.sym == SDLK_UP)
                {
                    //PI->RotarPieza();
                    P[P.size()-1]->RotarPieza();
//                        T1.RotarPieza();

                    //T1.dibujarPieza();
                    break;
                }
                if (event.key.keysym.sym == SDLK_DOWN)
                {
                    //mostrarMap();
                    P[P.size()-1]->Bajar();

                    break;

                }
                if (event.key.keysym.sym == SDLK_w)
                {
                    //mostrarMap();
                    cout<<P.size()<<endl;

                    break;

                }
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    //PI->MoverIzq();
                    P[P.size()-1]->MoverIzq();
//                        T1.MoverIzq();
                    break;
                }
                if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    //PI->MoverDer();
                    P[P.size()-1]->MoverDer();
//                        T1.MoverDer();
                    break;
                }
            }
            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_DOWN)
                    P[P.size()-1]->DownUp();

            } // end switch
        } // end of message processing

        // finally, update the screen :)
        g_gestorVideo->actualizar_pantalla();
        frames_drawn++;
    } // end main loop
    for (size_t i = 0; i < P.size(); i++)
    {
        delete P[i];
    }
    end_time = time(NULL);
    if (start_time == end_time) end_time++;

    /* Display the average framerate. */
    printf("Drew %i frames in %i seconds, for a framerate of %.2f fps.\n",
           frames_drawn,
           end_time-start_time,
           (float)frames_drawn/(float)(end_time-start_time));
    // all is well ;)
    SDL_FreeSurface(fondo);
    printf("Exited cleanly\n");
    return 0;
}
