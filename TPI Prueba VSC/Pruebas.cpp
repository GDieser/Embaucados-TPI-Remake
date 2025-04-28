#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <thread> 
#include <chrono> 

#include "Funciones.h"
#include "rlutil.h"
#include "FuncionesInicio.h"

using namespace std;



///Inicio Prueba de cartas
void tiradaDeCartas()
{
    rlutil::setBackgroundColor(rlutil::GREEN);
    rlutil::cls();

    for (int x = 0; x < 2; x++)
    {
        for (int j = 7; j <= 28; j += 7)
        {
            for (int i = 1; i <= 13; i++)
            {
                if (x == 0)
                {
                    dibujarReversoCarta((i * 9), j);
                }
                else
                {
                    for (int y = 1; y <= 15; y++)
                    {
                        dibujarCartas(obtenerNumeroCarta(rand() % 13 + 1), obtenerPalo(rand() % 4), (i * 9), j);
                        rlutil::msleep(3);
                    }
                    dibujarCartas(obtenerNumeroCarta(rand() % 13 + 1), obtenerPalo(rand() % 4), (i * 9), j);
                    rlutil::msleep(30);
                }
            }
        }
    }

    rlutil::setBackgroundColor(rlutil::BLACK);

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    system("pause");
}


void dibujarReactangulo(int posx, int posy, int ancho, int alto, char fondo)
{
    for (int x = posx; x < (posx + ancho); x++)
    {
        for (int y = posy; y < (posy + alto); y++)
        {
            rlutil::locate(x, y);
            cout << fondo;
        }
    }
}


void dibujarReversoCarta(int posx, int posy)
{
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::LIGHTRED);
    dibujarReactangulo(posx, posy, 7, 5, 206);
}


void dibujarCartas(string numero, char figura, int posx, int posy)
{
    rlutil::setColor(rlutil::WHITE);
    dibujarReactangulo(posx, posy, 7, 5);


    if (figura == 3 || figura == 4)
    {
        rlutil::setColor(rlutil::RED);
    }
    else
    {
        rlutil::setColor(rlutil::BLACK);
    }

    rlutil::setBackgroundColor(rlutil::WHITE);
    dibujarNumero(numero, posx, posy);
    rlutil::locate(posx + 3, posy + 2);
    cout << figura;


}


void dibujarNumero(string numero, int posx, int posy)
{
    rlutil::locate(posx, posy);
    cout << numero;

    rlutil::locate(posx + 7 - numero.size(), posy + 4);
    cout << numero;


}


string obtenerNumeroCarta(int numero)
{

    switch (numero)
    {
    case 1:
        return "A";
        break;
    case 11:
        return "J";
        break;
    case 12:
        return "Q";
        break;
    case 13:
        return "K";
        break;
    default:
        return to_string(numero);
        break;
    }
}


char obtenerPalo(int numero)
{
    char palos[] = { 3, 4, 5, 6 };

    return palos[numero];
}
///Fin pruebas de cartas


///Opciones de menú
/*void elegirOpcionesDelJuego(string& player1, string& player2, char& opcion, string nombrePuntajeMaximo[], int TAM_P, int puntajeMaximo[], int TAM_M)
{
    ///Solo para pruebas
    string playerPrueba1 = "Tomás";
    string playerPrueba2 = "Germán";

    //mostrarMenuEmbaucado(opcion);

    switch (opcion)
    {
    case '1':
        ///Registrar Nombres
        registarNombresJugadores(player1, player2, nombrePuntajeMaximo, TAM_P, puntajeMaximo, TAM_M);
        break;

    case '2':
        ///Estadisticas
        mostrarEstadisticas(nombrePuntajeMaximo, TAM_P, puntajeMaximo, TAM_M);
        break;

    case '3':
        ///Creditos
        mostrarCreditos();
        break;

    case '4':
        ///~Extra~ Reglas del juego
        mostrarReglasDeJuego();
        break;
    case '5':
        ///~Extra~ Easter egg desempate

        desempatarPlayers(playerPrueba1, playerPrueba2, 999, 888, nombrePuntajeMaximo, TAM_P, puntajeMaximo, TAM_M);
        break;

    case '0':
        ///Fin del juego
        system("cls");
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
        cout << "  !                      |     GRACIAS POR JUGAR!!!    |                         !" << endl;
        cout << "  !                      +-----------------------------+                         !" << endl;
        cout << "  +~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-+" << endl;
        break;

    default:
        system("cls");
        cout << "  +~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-+" << endl;
        cout << "  !                      +-----------------------------+                         !" << endl;
        cout << "  !                      |   ERROR, PRUEBE DE NUEVO!   |                         !" << endl;
        cout << "  !                      +-----------------------------+                         !" << endl;
        cout << "  +~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-+" << endl;
        system("pause");
        break;
    }
}
*/
