#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono> 

#include "Funciones.h"
#include "rlutil.h"
#include "FuncionesInicio.h"
#include "FuncionesMenu.h"

using namespace std;

void mostrarMenuEmbaucado(string player1, string player2, string nombrePuntajeMaximo[], int TAM_M, int puntajeMaximo[], int TAM_PM)
{
    
    ///Solo para pruebas
    string playerPrueba1 = "Tomás";
    string playerPrueba2 = "Germán";

    int opcion = 1;
    bool caratula = false;

    int y = 0;


    ///Guardo la opcion para ingresar en cada opcion o tira mensaje de error
    do
    {
        if (!caratula)
        {
            system("cls");
            mostrarLogoEmbaucado(3);
            caratula = true;
        }
        rlutil::setColor(rlutil::COLOR::YELLOW);
        recuadro(1);

        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();

        mostrarItems("         JUGAR           ", 50, 20, y == 0);
        mostrarItems("      ESTADISTICAS       ", 50, 21, y == 1);
        mostrarItems("        CREDITOS         ", 50, 22, y == 2);
        mostrarItems("     REGLAS DE JUEGO     ", 50, 23, y == 3);
        mostrarItems("         SALIR           ", 50, 25, y == 4);

        rlutil::setColor(rlutil::COLOR::YELLOW);

        switch (rlutil::getkey())
        {
        case 14: // Tecla UP
            rlutil::locate(50, 20 + y);
            Beep(150, 80);Sleep(80);
            y--;
            if (y < 0)
            {
                y = 0;
            }
            break;
        case 15: // Tecla DOWN

            rlutil::locate(50, 20 + y);
            Beep(150, 80);Sleep(80);
            y++;

            if (y > 4)
            {
                y = 4;
            }

            break;
        case 1: // Tecla ENTER

            Beep(200, 100);Sleep(100);
            switch (y)
            {
            case 0:
                ///Registrar Nombres
                registarNombresJugadores(player1, player2, nombrePuntajeMaximo, TAM_M, puntajeMaximo, TAM_PM);
                caratula = false;
                break;

            case 1:
                ///Estadisticas
                mostrarEstadisticas(nombrePuntajeMaximo, TAM_M, puntajeMaximo, TAM_PM);
                caratula = false;
                break;

            case 2:
                ///Creditos
                mostrarCreditos();
                caratula = false;
                break;

            case 3:
                ///~Extra~ Reglas del juego
                mostrarReglasDeJuego();
                caratula = false;
                break;

                /*case '5':
                     ///~Extra~ Easter egg desempate

                     desempatarPlayers(playerPrueba1, playerPrueba2, 999, 888, nombrePuntajeMaximo, TAM, puntajeMaximo, TAM);
                     break; */

            case 4:
                opcion = 0;
                break;

            default:
                break;
            }
            break;

        default:
            break;
        }


    } while (opcion != 0);



}

void mostrarItems(const char* text, int posicion_x, int posicion_y, bool selecion)
{
    char naipe = obtenerPalo(rand() % 4);

    if (selecion)
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        rlutil::locate(posicion_x - 2, posicion_y);
        cout << " " << naipe << " " << text << " " << naipe << " " << endl;
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(posicion_x - 2, posicion_y);
        cout << "   " << text << "   "<< endl;
    }

    rlutil::locate(posicion_x, posicion_y);

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void mostrarEstadisticas(string nombrePuntajeMaximo[], int TAM_P, int puntajeMaximo[], int TAM_M)
{
    system("cls");

    mostrarLogoEmbaucado(6);
    rlutil::setColor(rlutil::YELLOW);

    rlutil::setColor(rlutil::WHITE);

    /// Estadisticas por partida de los puntajes maximos de los ganadores nada más
    cout << "\n \n \n \n" << endl;
    cout << "\t\t\t\t  LUGAR     : \t\t   PUNTOS: \t\t   NOMBRE: \n" << endl;
    cout << endl;
    rlutil::setColor(rlutil::YELLOW);
    cout << "\t\t\t\t 1: ORO    : \t\t     " << puntajeMaximo[0] << "\t\t   " << nombrePuntajeMaximo[0] << "\n\n" << endl;
    rlutil::setColor(rlutil::GREY);
    cout << "\t\t\t\t 2: PLATA  : \t\t     " << puntajeMaximo[1] << "\t\t   " << nombrePuntajeMaximo[1] << "\n\n" << endl;
    rlutil::setColor(rlutil::LIGHTRED);
    cout << "\t\t\t\t 3: BRONCE : \t\t     " << puntajeMaximo[2] << "\t\t   " << nombrePuntajeMaximo[2] << "\n\n" << endl;
    rlutil::setColor(rlutil::WHITE);
    
    recuadro(2);
    rlutil::setColor(rlutil::YELLOW);
    recuadro(1);
    cout << endl;
    system("pause");
}

void mostrarCreditos()
{
    system("cls");

    mostrarLogoEmbaucado(4);
    rlutil::setColor(rlutil::YELLOW);

    rlutil::setColor(rlutil::WHITE);

    /// Creditos con los datos de los participantes
    
    cout << "\n \n \n" << endl;
    cout << "\t  ++========================================++ \t\t ++==========================================++" << endl;
    cout << "\t  || LEGAJO |   NOMBRE:    |   APELLIDO:    || \t\t || EQUIPO DOCENTES                          ||" << endl;
    cout << "\t  ++========================================++ \t\t ++==========================================++" << endl;
    cout << "\t  || 30999  |    Tomas     | Guzman Camacho || \t\t || ANGEL SIMON                - PROFESOR    ||" << endl;
    cout << "\t  ++========================================++ \t\t ++==========================================++" << endl;
    cout << "\t  || 30957  | German J. E. |    Dieser      || \t\t || MAXIMILIANO SAR FERNANDEZ  - PROFESOR    ||" << endl;
    cout << "\t  ++=========================================+ \t\t ++==========================================++" << endl;
    cout << "\t  ||               GRUPO: 32                || \t\t || LAURA VELEZ                - PROFESORA   ||" << endl;
    cout << "\t  ++========================================++ \t\t ++==========================================++" << endl;
    cout << "\t                                              \t\t || BRIAN LARA CAMPOS          - PROFESOR    ||" << endl;
    cout << "\t                                              \t\t ++==========================================++" << endl;
    cout << endl;
    cout << "\t Creditos Soundtrack: Logo - Mark VII Limited/Universal Television (1967) (Adult Swim Intro)" << endl;
    cout << "\t                      Music - Puttin' On the Ritz,  Irving Berlin - (1927) (version MIDI Taco - 1980)" << endl;

    rlutil::setColor(rlutil::YELLOW);
    recuadro(1);
    cout << endl;
    system("pause");

}

void mostrarReglasDeJuego()
{
    system("cls");

    mostrarLogoEmbaucado(5);
    rlutil::setColor(rlutil::YELLOW);

    rlutil::setColor(rlutil::WHITE);

    cout << "\n \n \n \n" << endl;
    cout << "\t Embaucado es un juego de naipes para 2 players, se juega con 20 naipes de 4 figuras (PICA, DIAMANTE, " << endl;
    cout << "\t CORAZON, TREBOL) con 5 valores (10, J, Q, K, A) y 4 naipes que seria la embaucadora." << endl;
    cout << "\n" << endl;
    cout << "\t +-----------+     El objetivo del juego es ganar acumulando puntos durante 3 rondas. En cada ronda, se recibe  " << endl;
    cout << "\t |  "<<(char)5<<" " << (char)4 << " " << (char)3 << " " << (char)6 << "  |   5 cartas al azar y se revela un naipe conocido como la EMBAUCADORA, que determina cuales   " << endl;
    cout << "\t |10: 10 pts |   naipes no sumarán puntos en esa ronda." << endl;
    cout << "\t | J: 11 pts |     A partir de la ronda 2, los players tienen la opcion de gastar 20 puntos para cambiar la" << endl;
    cout << "\t | Q: 12 pts |   carta embaucadora. Esto solo puede hacerse una vez por ronda y solo si el jugador +20 PUNTOS." << endl;
    cout << "\t | K: 15 pts |     En la ronda 2, el Player 1  tiene primero la opcion de cambiar la embaucadora, si elige NO,  " << endl;
    cout << "\t | A: 20 pts |   el Player 2 decide. En la ronda 3, viceversa primero elige el Player 2. Al final de las 3 " << endl;
    cout << "\t +-----------+   rondas gana el player con mas puntos." << endl;


    rlutil::setColor(rlutil::YELLOW);
    recuadro(1);
    cout << endl;
    system("pause");
}

