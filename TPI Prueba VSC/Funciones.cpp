#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

#include "Funciones.h"
#include "rlutil.h"
#include "FuncionesInicio.h"
#include "FuncionesMenu.h"

using namespace std;


void registarNombresJugadores(string& player1, string& player2, string nombrePuntajeMaximo[], int TAM_P, int puntajeMaximo[], int TAM_M)
{
    int opcion = 1;
    bool caratula = false;


    int y = 0;
    do
    {
        opcion = 1;

        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
        system("cls");

        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        dibujarTextosCentrados("Programar compulsivamente es perjudicial para la salud.", 32);
        dibujarTextosCentrados("Todos los derechos reservados.", 34);

        mostrarCartasMenu(7);

        rlutil::setColor(rlutil::WHITE);


        recuadro(3);
        rlutil::hidecursor();

        rlutil::setColor(rlutil::YELLOW);

        rlutil::locate(40, 15);
        cout << "Antes de comenzar debemos registrar sus nombres:" << endl;

        rlutil::locate(32, 19);
        cout << "Nombre del Jugador 1: ";
        rlutil::locate(54, 19);
        cin >> player1;

        rlutil::locate(32, 21);
        cout << "Nombre del Jugador 2: ";
        rlutil::locate(54, 21);
        cin >> player2;

        rlutil::locate(45, 25);
        cout << "Confirmar nombres: ";
        cout << endl;

        ///Guardo la opcion para ingresar en cada opcion o tira mensaje de error
        do
        {
            system("cls");
            
            rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
            dibujarTextosCentrados("Programar compulsivamente es perjudicial para la salud.", 32);
            dibujarTextosCentrados("Todos los derechos reservados", 34);

            rlutil::setColor(rlutil::WHITE);
            mostrarCartasMenu(7);
            recuadro(3);

            rlutil::setColor(rlutil::YELLOW);

            rlutil::locate(40, 15);
            cout << "Antes de jugar debemos registrar sus nombres: " << endl;

            rlutil::locate(32, 19);
            cout << "Nombre del Jugador 1: " << player1;

            rlutil::locate(32, 21);
            cout << "Nombre del Jugador 2: " << player2;

            rlutil::locate(55, 24);
            cout << "Confirmar nombres: ";
            cout << endl;


            confirmarNombres(" SI ", 62, 26, y == 0);
            confirmarNombres(" NO ", 62, 27, y == 1);


            switch (rlutil::getkey())
            {
            case 14: // Tecla UP
                rlutil::locate(62, 26 + y);
                Beep(150, 80);Sleep(80);
                y--;
                if (y < 0)
                {
                    y = 0;
                }
                break;
            case 15: // Tecla DOWN

                rlutil::locate(62, 26 + y);
                Beep(150, 80);Sleep(80);
                y++;

                if (y > 1)
                {
                    y = 1;
                }

                break;
            case 1: // Tecla ENTER

                Beep(200, 100);Sleep(100);
                opcion = 0;

                break;

            default:
                break;
            }


        } while (opcion != 0);


        if (y == 0)
        {
            caratula = true;
        }
        else
        {
            caratula = false;
        }


    } while (caratula == false);

    comenzarJuego(player1, player2, nombrePuntajeMaximo, TAM_P, puntajeMaximo, TAM_M);
}

void confirmarNombres(const char* text, int posicion_x, int posicion_y, bool selecion)
{

    if (selecion)
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        rlutil::locate(posicion_x - 2, posicion_y);
        cout << " " << text << " " << endl;
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
        rlutil::locate(posicion_x - 2, posicion_y);
        cout << " " << text << " " << endl;
    }

    rlutil::locate(posicion_x, posicion_y);

    rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
}

void comenzarJuego(string& player1, string& player2, string nombrePuntajeMaximo[], int TAM_P, int puntajeMaximo[], int TAM_M)
{
    rlutil::setBackgroundColor(rlutil::COLOR::GREEN);

    ///Declaro las variables para cada partida
    int const TAM_N = 5, TAM_R = 3;
    int puntosPlayer1 = 0, puntosPlayer2 = 0;
    int puntosPorRondaP1[TAM_R] = {}, puntosPorRondaP2[TAM_R] = {};
    char opcion;

    int figura_ActualP1[TAM_N] = {}, figura_ActualP2[TAM_N] = {};
    string naipe_ActualP1[TAM_N] = {}, naipe_ActualP2[TAM_N] = {};
    string embaucadora_naipe = "E";
    int embaucadora, opcion_regla = 1, y = 0;
    
    bool caratula = false;

    for (int i = 0; i < 3; i++)
    {
        opcion_regla = 1;

        system("cls");
        rlutil::setColor(rlutil::BLUE);
        pintarLineas(125, 4);

        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        rlutil::locate(54, 2);
        rlutil::setColor(rlutil::WHITE);
        cout << " EMBAUCADO RONDA #" << (i + 1) << endl;
        rlutil::locate(62, 3);
        cout << " vs " << endl;
        rlutil::locate(40, 3);
        cout << player1 << endl;
        rlutil::locate(80, 3);
        cout << player2 << endl;
        
        ///Randomizo las 10 cartas
        randomizarCartasParaPlayers(figura_ActualP1, TAM_N, naipe_ActualP1, TAM_N, figura_ActualP2, TAM_N, naipe_ActualP2, TAM_N);


        //Dibujar player 1
        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
        rlutil::locate(14, 7);
        rlutil::setColor(rlutil::YELLOW);
        cout << player1 << " PUNTOS: ( " << puntosPlayer1 << " )" << endl;

        for (int z = 0; z < 2; z++)
        {
            if (z == 0)
            {
                for (int i = 0; i < 50; i += 10)
                {
                    dibujarCartaDadaVuelta(8 + i, 9);
                }
            }
            else
            {
                for (int x = 0; x < 50; x += 10)
                {
                    for (int y = 0; y < 50; y += 10)
                    {
                        dibujarCarta(naipe_ActualP1[(rand() % 5)], obtenerPalo(rand() % 4), 8 + x, 9);
                        rlutil::msleep(20);
                    }
                    dibujarCarta(naipe_ActualP1[x / 10], obtenerFiguras(figura_ActualP1[x / 10]), 8 + x, 9);
                    rlutil::msleep(30);
                }
            }
        }

        //Dibujar player 2
        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
        rlutil::locate(78, 7);
        rlutil::setColor(rlutil::YELLOW);
        cout << player2 << " PUNTOS: ( " << puntosPlayer2 << " )" << endl;
        for (int z = 0; z < 2; z++)
        {
            if (z == 0)
            {
                for (int i = 0; i < 50; i += 10)
                {
                    dibujarCartaDadaVuelta(72 + i, 9);
                }
            }
            else
            {
                for (int x = 0; x < 50; x += 10)
                {
                    for (int y = 0; y < 50; y += 10)
                    {
                        dibujarCarta(naipe_ActualP2[(rand() % 5)], obtenerPalo(rand() % 4), 72 + x, 9);
                        rlutil::msleep(20);
                    }
                    dibujarCarta(naipe_ActualP2[x / 10], obtenerFiguras(figura_ActualP2[x / 10]), 72 + x, 9);
                    rlutil::msleep(30);
                }
            }
        }

        embaucadora = randomizarCartaEmbaucadora();

        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
        rlutil::setColor(rlutil::YELLOW);

        rlutil::locate(11, 15);
        mostrarPuntajesPlayers(player1, puntosPlayer1, naipe_ActualP1, TAM_N, figura_ActualP1, TAM_N, embaucadora);

        rlutil::locate(74, 15);
        mostrarPuntajesPlayers(player2, puntosPlayer2, naipe_ActualP2, TAM_N, figura_ActualP2, TAM_N, embaucadora);
        
        rlutil::setColor(rlutil::WHITE);
        recuadro(4);

        //Dibujar embaucadora
        rlutil::locate(54, 18);
        rlutil::setColor(rlutil::YELLOW);
        cout << "CARTA EMBAUCADORA:" << endl;

        for (int y = 0; y < 25; y ++)
        {
            dibujarCarta(naipe_ActualP2[(rand() % 5)], obtenerPalo(rand() % 4), 59, 20);
            rlutil::msleep(20);
        }
        dibujarCarta(embaucadora_naipe, obtenerFiguras(embaucadora), 59, 20);

        //Regla de cambiar embaucadora
        if (i == 1 && puntosPlayer1 > 20 && puntosPlayer2 > 20)
        {
            do
            {
                rlutil::locate(44, 26);
                rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
                rlutil::setColor(rlutil::WHITE);
                cout << player1 << " DESEA CAMBIAR LA EMBAUCADORA: " << endl;

                confirmarNombres(" SI ", 62, 27, y == 0);
                confirmarNombres(" NO ", 62, 28, y == 1);

                switch (rlutil::getkey())
                {
                case 14: // Tecla UP
                    rlutil::locate(62, 27 + y);
                    Beep(150, 80);Sleep(80);
                    y--;
                    if (y < 0)
                    {
                        y = 0;
                    }
                    break;
                case 15: // Tecla DOWN

                    rlutil::locate(62, 27 + y);
                    Beep(150, 80);Sleep(80);
                    y++;

                    if (y > 1)
                    {
                        y = 1;
                    }

                    break;
                case 1: // Tecla ENTER

                    Beep(200, 100);Sleep(100);
                    opcion_regla = 0;

                    break;

                default:
                    break;
                }

            } while (opcion_regla != 0);

            if (y == 1)
            {
                opcion_regla = 1;

                do
                {
                    for (int a = 0; a < 4; a++)
                    {
                        for (int b = 0; b < 50; b++)
                        {
                            rlutil::locate(42 + b, 26 + a);
                            rlutil::setColor(rlutil::GREEN);
                            cout << (char)219 << endl;
                        }
                    }

                    rlutil::locate(44, 26);
                    rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
                    rlutil::setColor(rlutil::WHITE);
                    cout << player2 << " DESEA CAMBIAR LA EMBAUCADORA: " << endl;

                    confirmarNombres(" SI ", 62, 27, y == 0);
                    confirmarNombres(" NO ", 62, 28, y == 1);

                    switch (rlutil::getkey())
                    {
                    case 14: // Tecla UP
                        rlutil::locate(62, 27 + y);
                        Beep(150, 80);Sleep(80);
                        y--;
                        if (y < 0)
                        {
                            y = 0;
                        }
                        break;
                    case 15: // Tecla DOWN

                        rlutil::locate(62, 27 + y);
                        Beep(150, 80);Sleep(80);
                        y++;

                        if (y > 1)
                        {
                            y = 1;
                        }

                        break;
                    case 1: // Tecla ENTER

                        Beep(200, 100);Sleep(100);
                        opcion_regla = 0;

                        break;

                    default:
                        break;
                    }

                } while (opcion_regla != 0);

                if (y == 0)
                {
                    for (int a = 0; a < 4; a++)
                    {
                        for (int b = 0; b < 50; b++)
                        {
                            rlutil::locate(42 + b, 26 + a);
                            rlutil::setColor(rlutil::GREEN);
                            cout << (char)219 << endl;
                        }
                    }

                    embaucadora = randomizarCartaEmbaucadora();

                    rlutil::locate(54, 18);
                    rlutil::setColor(rlutil::YELLOW);
                    cout << "NUEVA EMBAUCADORA:" << endl;

                    for (int y = 0; y < 25; y++)
                    {
                        dibujarCarta(naipe_ActualP2[(rand() % 5)], obtenerPalo(rand() % 4), 59, 20);
                        rlutil::msleep(20);
                    }
                    dibujarCarta(embaucadora_naipe, obtenerFiguras(embaucadora), 59, 20);


                    //SE RESTAN 20 PTOS
                    puntosPlayer2 -= 20;
                }
            }
            else
            {
                for (int a = 0; a < 4; a++)
                {
                    for (int b = 0; b < 50; b++)
                    {
                        rlutil::locate(42 + b, 26 + a);
                        rlutil::setColor(rlutil::GREEN);
                        cout << (char)219 << endl;
                    }
                }

                embaucadora = randomizarCartaEmbaucadora();

                rlutil::locate(54, 18);
                rlutil::setColor(rlutil::YELLOW);
                cout << "NUEVA EMBAUCADORA:" << endl;

                for (int y = 0; y < 25; y++)
                {
                    dibujarCarta(naipe_ActualP2[(rand() % 5)], obtenerPalo(rand() % 4), 59, 20);
                    rlutil::msleep(20);
                }
                dibujarCarta(embaucadora_naipe, obtenerFiguras(embaucadora), 59, 20);

                
                //SE RESTAN 20 PTOS
                puntosPlayer1 -= 20;
            }
            
        }
        else if(i == 2)
        {
            do
            {
                rlutil::locate(44, 26);
                rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
                rlutil::setColor(rlutil::WHITE);
                cout << player2 << " DESEA CAMBIAR LA EMBAUCADORA: " << endl;

                confirmarNombres(" SI ", 62, 27, y == 0);
                confirmarNombres(" NO ", 62, 28, y == 1);

                switch (rlutil::getkey())
                {
                case 14: // Tecla UP
                    rlutil::locate(62, 27 + y);
                    Beep(150, 80);Sleep(80);
                    y--;
                    if (y < 0)
                    {
                        y = 0;
                    }
                    break;
                case 15: // Tecla DOWN

                    rlutil::locate(62, 27 + y);
                    Beep(150, 80);Sleep(80);
                    y++;

                    if (y > 1)
                    {
                        y = 1;
                    }

                    break;
                case 1: // Tecla ENTER

                    Beep(200, 100);Sleep(100);
                    opcion_regla = 0;

                    break;

                default:
                    break;
                }

            } while (opcion_regla != 0);

            if (y == 1)
            {
                opcion_regla = 1;

                do
                {
                    for (int a = 0; a < 4; a++)
                    {
                        for (int b = 0; b < 50; b++)
                        {
                            rlutil::locate(42 + b, 26 + a);
                            rlutil::setColor(rlutil::GREEN);
                            cout << (char)219 << endl;
                        }
                    }

                    rlutil::locate(44, 26);
                    rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
                    rlutil::setColor(rlutil::WHITE);
                    cout << player1 << " DESEA CAMBIAR LA EMBAUCADORA: " << endl;

                    confirmarNombres(" SI ", 62, 27, y == 0);
                    confirmarNombres(" NO ", 62, 28, y == 1);

                    switch (rlutil::getkey())
                    {
                    case 14: // Tecla UP
                        rlutil::locate(62, 27 + y);
                        Beep(150, 80);Sleep(80);
                        y--;
                        if (y < 0)
                        {
                            y = 0;
                        }
                        break;
                    case 15: // Tecla DOWN

                        rlutil::locate(62, 27 + y);
                        Beep(150, 80);Sleep(80);
                        y++;

                        if (y > 1)
                        {
                            y = 1;
                        }

                        break;
                    case 1: // Tecla ENTER

                        Beep(200, 100);Sleep(100);
                        opcion_regla = 0;

                        break;

                    default:
                        break;
                    }

                } while (opcion_regla != 0);

                if (y == 0)
                {
                    for (int a = 0; a < 4; a++)
                    {
                        for (int b = 0; b < 50; b++)
                        {
                            rlutil::locate(42 + b, 26 + a);
                            rlutil::setColor(rlutil::GREEN);
                            cout << (char)219 << endl;
                        }
                    }

                    embaucadora = randomizarCartaEmbaucadora();

                    rlutil::locate(54, 18);
                    rlutil::setColor(rlutil::YELLOW);
                    cout << "NUEVA EMBAUCADORA:" << endl;

                    for (int y = 0; y < 25; y++)
                    {
                        dibujarCarta(naipe_ActualP2[(rand() % 5)], obtenerPalo(rand() % 4), 59, 20);
                        rlutil::msleep(20);
                    }
                    dibujarCarta(embaucadora_naipe, obtenerFiguras(embaucadora), 59, 20);


                    //SE RESTAN 20 PTOS
                    puntosPlayer1 -= 20;
                }
            }
            else
            {
                for (int a = 0; a < 4; a++)
                {
                    for (int b = 0; b < 50; b++)
                    {
                        rlutil::locate(42 + b, 26 + a);
                        rlutil::setColor(rlutil::GREEN);
                        cout << (char)219 << endl;
                    }
                }

                embaucadora = randomizarCartaEmbaucadora();

                rlutil::locate(54, 18);
                rlutil::setColor(rlutil::YELLOW);
                cout << "NUEVA EMBAUCADORA:" << endl;

                for (int y = 0; y < 25; y++)
                {
                    dibujarCarta(naipe_ActualP2[(rand() % 5)], obtenerPalo(rand() % 4), 59, 20);
                    rlutil::msleep(20);
                }
                dibujarCarta(embaucadora_naipe, obtenerFiguras(embaucadora), 59, 20);

                //SE RESTAN 20 PTOS
                puntosPlayer2 -= 20;
            }
        }
        
        for (int a = 0; a < 4; a++)
        {
            for (int b = 0; b < 50; b++)
            {
                rlutil::locate(42 + b, 26 + a);
                rlutil::setColor(rlutil::GREEN);
                cout << (char)219 << endl;
            }
        }

        //Puntos player 1
        puntosPorRondaP1[i] = calcularPuntajesPlayers(player1, puntosPlayer1, naipe_ActualP1, TAM_N, figura_ActualP1, TAM_N, embaucadora);

        //Puntos player 2
        puntosPorRondaP2[i] = calcularPuntajesPlayers(player2, puntosPlayer2, naipe_ActualP2, TAM_N, figura_ActualP2, TAM_N, embaucadora);

        //PUNTOS
        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
        rlutil::locate(51, 29);
        rlutil::setColor(rlutil::YELLOW);
        cout << "PUNTOS OBTENIDOS RONDA #" << i+1 << endl;

        rlutil::locate(20, 31);
        cout << player1 << " : " << puntosPlayer1 << endl;

        rlutil::locate(85, 31);
        cout << player2 << " : " << puntosPlayer2 << endl;

        rlutil::setColor(rlutil::WHITE);
        recuadro(5);

        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
        cout << "\n"<< endl;
        system("pause");
    }

    finalizarJuegoYMostrarEstadisticas(player1, player2, puntosPorRondaP1, TAM_R, puntosPorRondaP2, TAM_R, puntosPlayer1, puntosPlayer2, nombrePuntajeMaximo, TAM_P, puntajeMaximo, TAM_M);
}

void finalizarJuegoYMostrarEstadisticas(string player1, string player2, int puntosPorRondaP1[], int TAM_R1, int puntosPorRondaP2[], int TAM_R, int puntosPlayer1, int puntosPlayer2, string nombrePuntajeMaximo[], int TAM_P, int puntajeMaximo[], int TAM_M)
{

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    system("cls");

    rlutil::setColor(rlutil::YELLOW);
    mostrarLogoEmbaucado(8);

    rlutil::setColor(rlutil::YELLOW);
    recuadro(1);
    cout << endl;

    rlutil::setColor(rlutil::WHITE);

    /// Estadisticas por partida de los puntajes maximos de los ganadores nada más
    rlutil::locate(27, 19);
    cout << "RONDA: " << endl;
    rlutil::locate(54, 19);
    cout << player1 << endl;
    rlutil::locate(78, 19);
    cout << player2 << endl;

    rlutil::locate(35, 21);
    cout << "#1: " << endl;
    rlutil::locate(35, 22);
    cout << "#2: " << endl;
    rlutil::locate(35, 23);
    cout << "#3: " << endl;
    rlutil::locate(35, 25);
    cout << "TOTAL: " << endl;

    rlutil::locate(62, 21);
    cout << puntosPorRondaP1[0] << endl;
    rlutil::locate(62, 22);
    cout << puntosPorRondaP1[1] << endl;
    rlutil::locate(62, 23);
    cout << puntosPorRondaP1[2] << endl;
    rlutil::locate(62, 25);
    cout << puntosPlayer1 << endl;

    rlutil::locate(88, 21);
    cout << puntosPorRondaP2[0] << endl;
    rlutil::locate(88, 22);
    cout << puntosPorRondaP2[1] << endl;
    rlutil::locate(88, 23);
    cout << puntosPorRondaP2[2] << endl;
    rlutil::locate(88, 25);
    cout << puntosPlayer2 << endl;

    recuadro(6);

    if (puntosPlayer1 > puntosPlayer2)
    {
        rlutil::locate(40, 28);
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout << "GANADOR: " << player1 << " con " << puntosPlayer1 << " puntos de victoria!!!" << endl;

        ///Calcular valoresa maximo pero por partida (v2) ponele... (hay que mejorarlo tira fallas)
        for (int x = 0; x < 3; x++)
        {
            if (puntosPlayer1 > puntajeMaximo[x])
            {
                ///Mueve los puntajes mas bajos en la posición correspondiente
                for (int j = 2; j > x; j--)
                {
                    puntajeMaximo[j] = puntajeMaximo[j - 1];
                    nombrePuntajeMaximo[j] = nombrePuntajeMaximo[j - 1];
                }
                ///Nuevo puntaje en la posicion correcta
                puntajeMaximo[x] = puntosPlayer1;
                nombrePuntajeMaximo[x] = player1;
                break;
            }
        }


    }
    else if (puntosPlayer2 > puntosPlayer1)
    {
        rlutil::locate(40, 28);
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout << "GANADOR: " << player2 << " con " << puntosPlayer2 << " puntos de victoria!!!" << endl;

        ///Calcular valoresa maximo pero por partida (v2) mas o menos....

        for (int y = 0; y < 3; y++)
        {
            if (puntosPlayer2 > puntajeMaximo[y])
            {
                ///Mueve los puntajes mas bajos en la posición correspondiente
                for (int z = 2; z > y; z--)
                {
                    puntajeMaximo[z] = puntajeMaximo[z - 1];
                    nombrePuntajeMaximo[z] = nombrePuntajeMaximo[z - 1];
                }
                ///Nuevo puntaje en la posicion correcta
                puntajeMaximo[y] = puntosPlayer2;
                nombrePuntajeMaximo[y] = player2;
                break;
            }
        }

    }
    else
    {
        rlutil::locate(40, 28);
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout << "EMPATE ENTRE: " << player1 << " y " << player2 << " PROCEDEMOS A DESEMPATAR" << endl;


        desempatarPlayers(player1, player2, puntosPlayer1, puntosPlayer2, nombrePuntajeMaximo, TAM_P, puntajeMaximo, TAM_M);
        system("pause");
    }

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    cout << "\n\n\n\n\n" << endl;
    system("pause");

}

void randomizarCartasParaPlayers(int figura_ActualP1[], int TAM_P1, string naipe_ActualP1[], int TAM_N1, int figura_ActualP2[], int TAM_P2, string naipe_ActualP2[], int TAM_N2)
{
    ///Declaro las figuras y los naipes
    int const TAM_F = 4, TAM_N = 5, TAM_T = 10;
    int RAN_F, RAN_N, contCartas = 0;

    int figura[TAM_F] = { 0, 1, 2, 3 };
    string naipe[TAM_N] = { "A", "10", "J", "K", "Q" };

    char figura_Actual[TAM_T];
    string naipe_Actual[TAM_T];

    /// Genero 10 cartas randoms todas distintas (al fin...)
    while (contCartas < TAM_T)
    {
        /// Numeros randoms
        RAN_F = rand() % TAM_F;
        RAN_N = rand() % TAM_N;

        /// Bandera repetidos
        bool noRepetida = true;

        /// Comparo en cada carta con las ya randomizadas anteriormente
        for (int i = 0; i < contCartas; i++)
        {
            if (figura_Actual[i] == figura[RAN_F] && naipe_Actual[i] == naipe[RAN_N])
            {
                noRepetida = false;
            }
        }

        /// Guardo la carta con figura y naipe random
        if (noRepetida)
        {
            figura_Actual[contCartas] = figura[RAN_F];
            naipe_Actual[contCartas] = naipe[RAN_N];

            /// Cuento cuantas cartas se van randomizando
            contCartas++;
        }
    }

    /// Divido en los 2 players
    for (int x = 0; x < 10; x++)
    {
        if (x < 5)
        {
            figura_ActualP1[x] = figura_Actual[x];
            naipe_ActualP1[x] = naipe_Actual[x];
        }
        else
        {
            figura_ActualP2[x - 5] = figura_Actual[x];
            naipe_ActualP2[x - 5] = naipe_Actual[x];
        }
    }
}

int randomizarCartaEmbaucadora()
{

    ///Randopmizador de las figuras de para la embaucadora, devuelve uno al "azar"
    int const TAM_F = 4;
    int RAN_F;

    int figura[TAM_F] = { 0, 1, 2, 3 };

    RAN_F = (rand() % TAM_F);

    return figura[RAN_F];

}

void mostrarPuntajesPlayers(string player, int& puntosPlayer, string naipe_ActualP[], int TAM_N, int figura_ActualP[], int TAM_A, int embaucadora)
{

    /// Ciclo de 5 vueltas para comparar con la embaucadora y solo sumar las que no coinciden
    for (int i = 0; i < 5; i++)
    {
        if (naipe_ActualP[i] == "10")
        {
            cout << "10        "; 
        }
        else if (naipe_ActualP[i] == "J")
        {
            cout << "11        ";
        }
        else if (naipe_ActualP[i] == "Q")
        {
            cout << "12        ";
        }
        else if (naipe_ActualP[i] == "K")
        {
            cout << "15        ";
            
        }
        else if (naipe_ActualP[i] == "A")
        {
            cout << "20        ";
            
        }
    }

}

int calcularPuntajesPlayers(string player, int& puntosPlayer, string naipe_ActualP[], int TAM_N, int figura_ActualP[], int TAM_A, int embaucadora)
{
    /// Contador de puntos para retornar al final, guardar en un vector mostrar en el resumen
    int contadorDePuntos = 0;

    /// Ciclo de 5 vueltas para comparar con la embaucadora y solo sumar las que no coinciden
    for (int i = 0; i < 5; i++)
    {
        if (naipe_ActualP[i] == "10")
        {
            if (figura_ActualP[i] != embaucadora)
            {
                puntosPlayer += 10;
                contadorDePuntos += 10;
            }
        }
        else if (naipe_ActualP[i] == "J")
        {
            if (figura_ActualP[i] != embaucadora)
            {
                puntosPlayer += 11;
                contadorDePuntos += 11;
            }
        }
        else if (naipe_ActualP[i] == "Q")
        {
            if (figura_ActualP[i] != embaucadora)
            {
                puntosPlayer += 12;
                contadorDePuntos += 12;
            }
        }
        else if (naipe_ActualP[i] == "K")
        {
            if (figura_ActualP[i] != embaucadora)
            {
                puntosPlayer += 15;
                contadorDePuntos += 15;
            }
        }
        else if (naipe_ActualP[i] == "A")
        {
            if (figura_ActualP[i] != embaucadora)
            {
                puntosPlayer += 20;
                contadorDePuntos += 20;
            }
        }
    }

    /// Retona el punta individual de cada player por cada una de las 3 rondas para que se muestre en el resumen
    return contadorDePuntos;
}

void desempatarPlayers(string player1, string player2, int puntosPlayer1, int puntosPlayer2, string nombrePuntajeMaximo[], int TAM_P, int puntajeMaximo[], int TAM_M)
{
    int moneda;
    moneda = (rand() % 2);


    string caraCruz[2] = { "Cara", "Cruz" };

    system("cls");

    /// Estadisticas por partida de los puntajes maximos de los ganadores nada más
    cout << endl;
    cout << "  +~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-+" << endl;
    cout << "  !                                                                              !" << endl;
    cout << "  !  _______ _______ ______  _______ _     _ _______ _______ ______  _______ ®   !" << endl;
    cout << "  ! (_______|_______|____  \\(_______|_)   (_|_______|_______|______)(_______)    !" << endl;
    cout << "  !  _____   _  _  _ ____)  )_______ _     _ _       _______ _     _ _     _     !" << endl;
    cout << "  ! |  ___) | ||_|| |  __  (|  ___  | |   | | |     |  ___  | |   | | |   | |    !" << endl;
    cout << "  ! | |_____| |   | | |__)  ) |   | | |___| | |_____| |   | | |__/ /| |___| |    !" << endl;
    cout << "  ! |_______)_|   |_|______/|_|   |_|\\_____/ \\______)_|   |_|_____/  \\_____/     !" << endl;
    cout << "  !                                                                              !" << endl;
    cout << "  !                                                           By Angel Simón     !" << endl;
    cout << "  !                                                                              !" << endl;
    cout << "  !                                                                              !" << endl;
    cout << "  !                      +-----------------------------+                         !" << endl;
    cout << "  !                      |        DESEMPATE!!!         |                         !" << endl;
    cout << "  !                      +-----------------------------+                         !" << endl;
    cout << "  !                                                                              !" << endl;
    cout << "  +~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-+" << endl;
    cout << endl;
    cout << "                                 " << player1 << " vs " << player2 << endl;
    cout << endl;
    cout << "                       Vamos a tirar una moneda al aire....." << endl;
    cout << endl;
    cout << "                             " << player1 << ": CARA " << player2 << ": CRUZ " << endl;
    cout << endl;
    system("pause");
    cout << endl;
    cout << "                                  3....2....1...." << endl;
    cout << endl;
    system("pause");
    cout << endl;
    cout << "                                  Monedad: " << caraCruz[moneda] << endl;
    cout << endl;
    system("pause");

    cout << endl;
    if (moneda == 0)
    {
        cout << "  +~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-+" << endl;
        cout << "                                GANADOR: " << player1 << "!!! " << endl;
        cout << "  +~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-+" << endl;

        ///Calcular valoresa maximo pero por partida (v2) ponele...
        ///V3 Ahora si...
        for (int x = 0; x < 3; x++)
        {
            if (puntosPlayer1 > puntajeMaximo[x])
            {
                ///Mueve los puntajes mas bajos en la posición correspondiente
                for (int j = 2; j > x; j--)
                {
                    puntajeMaximo[j] = puntajeMaximo[j - 1];
                    nombrePuntajeMaximo[j] = nombrePuntajeMaximo[j - 1];
                }
                ///Nuevo puntaje en la posicion correcta
                puntajeMaximo[x] = puntosPlayer1;
                nombrePuntajeMaximo[x] = player1;
                break;
            }
        }
    }
    else
    {
        cout << "  +~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-+" << endl;
        cout << "                                GANADOR: " << player2 << "!!!" << endl;
        cout << "  +~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-+" << endl;

        ///Calcular valoresa maximo pero por partida (v2) mas o menos....
        ///V3 Ahora si...
        for (int y = 0; y < 3; y++)
        {
            if (puntosPlayer2 > puntajeMaximo[y])
            {
                ///Mueve los puntajes mas bajos en la posición correspondiente
                for (int z = 2; z > y; z--)
                {
                    puntajeMaximo[z] = puntajeMaximo[z - 1];
                    nombrePuntajeMaximo[z] = nombrePuntajeMaximo[z - 1];
                }
                ///Nuevo puntaje en la posicion correcta
                puntajeMaximo[y] = puntosPlayer2;
                nombrePuntajeMaximo[y] = player2;
                break;
            }
        }
    }
    system("pause");
}

void pintarLineas(int posicion_x, int posicion_y)
{
    for (int y = 1; y <= posicion_y; y++)
    {
        for (int x = 1; x <= posicion_x; x++)
        {
            rlutil::locate(x, y);
            cout << (char)219;
        }
    }

    
}

