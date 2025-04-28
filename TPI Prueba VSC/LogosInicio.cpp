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

void iniciarPresentacion()
{
    PlaySound(TEXT("intro.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    //Mostrar Logo UTN
    presentarLogo();
    rlutil::setColor(rlutil::YELLOW);
    recuadro(1);
    rlutil::msleep(900);
    cout << endl;


    ///Bienvenida
    system("cls");
    mostrarLogoEmbaucado(1);
    rlutil::setColor(rlutil::YELLOW);
    recuadro(1);
    cout << endl;
    rlutil::msleep(2000);

    
}

void recuadro(int tipo)
{
    switch (tipo)
    {
    case 1:
        for (int x = 2; x <= 123; x++)
        {
            if (x == 2)
            {
                rlutil::locate(x, 1);
                cout << (char)201;
            }
            else if (x == 123)
            {
                rlutil::locate(x, 1);
                cout << (char)187;
            }
            else
            {
                rlutil::locate(x, 1);
                cout << (char)205;
                rlutil::locate(x, 33);
                cout << (char)205;
            }

        }

        for (int y = 2; y <= 33; y++)
        {

            if (y == 33)
            {
                rlutil::locate(2, y);
                cout << (char)200;

                rlutil::locate(123, y);
                cout << (char)188;
            }
            else
            {
                rlutil::locate(2, y);
                cout << (char)186;

                rlutil::locate(123, y);
                cout << (char)186;
            }


        }
        break;
    case 2:
        for (int x = 25; x <= 100; x++)
        {
            if (x == 25)
            {
                rlutil::locate(x, 18);
                cout << (char)201;
            }
            else if (x == 100)
            {
                rlutil::locate(x, 18);
                cout << (char)187;
            }
            else
            {
                rlutil::locate(x, 20);
                cout << (char)205;

                rlutil::locate(x, 18);
                cout << (char)205;
                rlutil::locate(x, 31);
                cout << (char)205;
            }

        }

        for (int y = 19; y <= 31; y++)
        {

            if (y == 31)
            {
                rlutil::locate(25, y);
                cout << (char)200;

                rlutil::locate(100, y);
                cout << (char)188;
            }
            else
            {   
                rlutil::locate(50, y);
                cout << (char)186;

                rlutil::locate(75, y);
                cout << (char)186;

                rlutil::locate(25, y);
                cout << (char)186;

                rlutil::locate(100, y);
                cout << (char)186;
            }


        }
        break;
    case 3:
        for (int x = 25; x <= 100; x++)
        {
            if (x == 25)
            {
                rlutil::locate(x, 13);
                cout << (char)201;
            }
            else if (x == 100)
            {
                rlutil::locate(x, 13);
                cout << (char)187;
            }
            else
            {

                rlutil::locate(x, 13);
                cout << (char)205;
                rlutil::locate(x, 28);
                cout << (char)205;
            }

        }

        for (int y = 14; y <= 28; y++)
        {

            if (y == 28)
            {
                rlutil::locate(25, y);
                cout << (char)200;

                rlutil::locate(100, y);
                cout << (char)188;
            }
            else
            {
                rlutil::locate(25, y);
                cout << (char)186;

                rlutil::locate(100, y);
                cout << (char)186;
            }


        }
        break;
    case 4:
        for (int x = 6; x <= 120; x++)
        {
            if (x == 6)
            {
                rlutil::locate(x, 14);
                cout << (char)201;
            }
            else if (x == 120)
            {
                rlutil::locate(x, 14);
                cout << (char)187;
            }
            else
            {

                rlutil::locate(x, 14);
                cout << (char)205;
                rlutil::locate(x, 16);
                cout << (char)205;
            }

        }

        for (int y = 15; y <= 16; y++)
        {

            if (y == 16)
            {
                rlutil::locate(6, y);
                cout << (char)200;

                rlutil::locate(120, y);
                cout << (char)188;
            }
            else
            {
                rlutil::locate(6, y);
                cout << (char)186;

                rlutil::locate(120, y);
                cout << (char)186;
            }


        }
        break;
    case 5:
        for (int x = 6; x <= 120; x++)
        {
            if (x == 6)
            {
                rlutil::locate(x, 30);
                cout << (char)201;
            }
            else if (x == 120)
            {
                rlutil::locate(x, 30);
                cout << (char)187;
            }
            else
            {

                rlutil::locate(x, 30);
                cout << (char)205;
                rlutil::locate(x, 32);
                cout << (char)205;
            }

        }

        for (int y = 31; y <= 32; y++)
        {

            if (y == 32)
            {
                rlutil::locate(6, y);
                cout << (char)200;

                rlutil::locate(120, y);
                cout << (char)188;
            }
            else
            {
                rlutil::locate(6, y);
                cout << (char)186;

                rlutil::locate(120, y);
                cout << (char)186;
            }


        }
        break;
    case 6:
        for (int x = 25; x <= 100; x++)
        {
            if (x == 25)
            {
                rlutil::locate(x, 18);
                cout << (char)201;
            }
            else if (x == 100)
            {
                rlutil::locate(x, 18);
                cout << (char)187;
            }
            else
            {
                rlutil::locate(x, 20);
                cout << (char)205;

                rlutil::locate(x, 24);
                cout << (char)205;

                rlutil::locate(x, 18);
                cout << (char)205;
                rlutil::locate(x, 26);
                cout << (char)205;
            }

        }

        for (int y = 19; y <= 26; y++)
        {

            if (y == 26)
            {
                rlutil::locate(25, y);
                cout << (char)200;

                rlutil::locate(100, y);
                cout << (char)188;
            }
            else
            {
                rlutil::locate(50, y);
                cout << (char)186;

                rlutil::locate(75, y);
                cout << (char)186;

                rlutil::locate(25, y);
                cout << (char)186;

                rlutil::locate(100, y);
                cout << (char)186;
            }


        }
        break;
    default:
        break;
    }

    cout << endl;
}

void presentarLogo()
{


    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            rlutil::msleep(800);
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "\t\t        __    __  ________  __    __                " << endl;
            cout << "\t\t       |  \\  |  \\|        \\|  \\  |  \\          " << endl;
            cout << "\t\t       | $$  | $$ \\$$$$$$$$| $$\\ | $$             " << endl;
            cout << "\t\t       | $$  | $$   | $$   | $$$\\| $$              " << endl;
            cout << "\t\t       | $$  | $$   | $$   | $$$$\\ $$              " << endl;
            cout << "\t\t       | $$  | $$   | $$   | $$\\$$ $$              " << endl;
            cout << "\t\t       | $$__/ $$   | $$   | $$ \\$$$$ __           " << endl;
            cout << "\t\t        \\$$    $$   | $$   | $$  \\$$$|  \\        " << endl;
            cout << "\t\t         \\$$$$$$     \\$$    \\$$   \\$$ \\$$      " << endl;
            cout << endl;
            rlutil::msleep(950);
        }
        else
        {
            system("cls");
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "\t\t        __    __  ________  __    __            ______  __    __   ______       " << endl;
            cout << "\t\t       |  \\  |  \\|        \\|  \\  |  \\          |      \\|  \\  |  \\ /      \\  " << endl;
            cout << "\t\t       | $$  | $$ \\$$$$$$$$| $$\\ | $$           \\$$$$$$| $$\\ | $$|  $$$$$$\\   " << endl;
            cout << "\t\t       | $$  | $$   | $$   | $$$\\| $$            | $$  | $$$\\| $$| $$   \\$$    " << endl;
            cout << "\t\t       | $$  | $$   | $$   | $$$$\\ $$            | $$  | $$$$\\ $$| $$          " << endl;
            cout << "\t\t       | $$  | $$   | $$   | $$\\$$ $$            | $$  | $$\\$$ $$| $$   __    " << endl;
            cout << "\t\t       | $$__/ $$   | $$   | $$ \\$$$$ __        _| $$_ | $$ \\$$$$| $$__/  \\ __" << endl;
            cout << "\t\t        \\$$    $$   | $$   | $$  \\$$$|  \\      |   $$ \\| $$  \\$$$ \\$$    $$|  \\ " << endl;
            cout << "\t\t         \\$$$$$$     \\$$    \\$$   \\$$ \\$$       \\$$$$$$ \\$$   \\$$  \\$$$$$$  \\$$" << endl;
            cout << endl;
            rlutil::msleep(800);
        }
    }
    cout << endl;
    cout << "\t\t               Programar compulsivamente es perjudicial para la salud." << endl;


    dibujarFiguras(1, 16, 20, 0);
    rlutil::msleep(200);
    dibujarFiguras(3, 42, 20, 0);
    rlutil::msleep(200);
    dibujarFiguras(2, 68, 20, 0);
    rlutil::msleep(200);
    dibujarFiguras(4, 94, 20, 0);

    PlaySound(TEXT("embaucadora.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    
    rlutil::msleep(200);

}

void mostrarLogoEmbaucado(int opcion)
{

    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t    _______ _______ ______  _______ _     _ _______ _______       ______  _______ ______ " << endl;
    cout << "\t\t   (_______|_______|____  \\(_______|_)   (_|_______|_______)     (______)(_______) _____)  " << endl;
    cout << "\t\t    _____   _  _  _ ____)  )_______ _     _ _       _______ _____ _     _ _     ( (____  " << endl;
    cout << "\t\t   |  ___) | ||_|| |  __  (|  ___  | |   | | |     |  ___  (_____) |   | | |   | \\____ \\  " << endl;
    cout << "\t\t   | |_____| |   | | |__)  ) |   | | |___| | |_____| |   | |     | |__/ /| |___| |____) )  " << endl;
    cout << "\t\t   |_______)_|   |_|______/|_|   |_|\\_____/ \\______)_|   |_|     |_____/  \\_____(______/" << endl;
    cout << endl;
    cout << endl;

    mostrarCartasMenu(opcion);
}

void finalizarPresentacion()
{
    ///Fin del juego
    system("cls");
    mostrarLogoEmbaucado(2);
    rlutil::setColor(rlutil::YELLOW);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}

void dibujarFiguras(int figura, int posx, int posy, int color)
{
    switch (figura)
    {
    case 1:
        //Corazon
        for (int y = posy; y < posy + 7; y++)
        {
            // Primero 
            for (int x = posx; x < posx + 14; x++)
            {
                if (y == posy)
                {
                    if (x > posx + 1 && x < posx + 6 || x > posx + 7 && x < posx + 12)
                    {
                        rlutil::setColor(rlutil::RED);
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }

                }
                else if (y > posy && y < posy + 4)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate(x, y);
                    cout << (char)219;
                }
                else if (y == posy + 4)
                {
                    if (x > posx + 1 && x < posx + 12)
                    {
                        rlutil::setColor(rlutil::RED);
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }
                }
                else if (y == posy + 5)
                {
                    if (x > posx + 3 && x < posx + 10)
                    {
                        rlutil::setColor(rlutil::RED);
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }
                }
                else if (y == posy + 6)
                {
                    if (x > posx + 5 && x < posx + 8)
                    {
                        rlutil::setColor(rlutil::RED);
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }
                }

            }

        }
        break;
    case 2:
        //Diamante
        for (int y = posy; y < posy + 7; y++)
        {
            for (int x = posx; x < posx + 14; x++)
            {
                if (y == posy || y == posy + 6)
                {
                    if (x > posx + 5 && x < posx + 8 )
                    {
                        rlutil::setColor(rlutil::RED);
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }

                }
                else if (y == posy + 1 || y  == posy + 5)
                {
                    if (x > posx + 3 && x < posx + 10)
                    {
                        rlutil::setColor(rlutil::RED);
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }
                }
                else if (y == posy + 2 || y == posy + 4)
                {
                    if (x > posx + 1 && x < posx + 12)
                    {
                        rlutil::setColor(rlutil::RED);
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }
                }
                else if (y == posy + 3)
                {
                    if (x >= posx && x < posx + 14)
                    {
                        rlutil::setColor(rlutil::RED);
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }
                }

            }

        }
        break;
    case 3:
        //Trebol
        for (int y = posy; y < posy + 7; y++)
        {
            for (int x = posx; x < posx + 14; x++)
            {
                if (y == posy || y == posy + 1)
                {
                    if (x > posx + 3 && x < posx + 10)
                    {
                        if (color == 1)
                        {
                            rlutil::setColor(rlutil::BLACK);
                        }
                        else
                        {
                            rlutil::setColor(rlutil::DARKGREY);
                        }
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }

                }
                else if (y == posy + 2 || y == posy + 6)
                {
                    if (x >= posx && x < posx + 14)
                    {
                        if (color == 1)
                        {
                            rlutil::setColor(rlutil::BLACK);
                        }
                        else
                        {
                            rlutil::setColor(rlutil::DARKGREY);
                        }
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }
                }
                else if (y == posy + 3 || y == posy + 4)
                {
                    if (x >= posx && x < posx + 4 || x == posx + 6 || x == posx + 7 || x > posx + 9 && x <= posx + 14)
                    {
                        if (color == 1)
                        {
                            rlutil::setColor(rlutil::BLACK);
                        }
                        else
                        {
                            rlutil::setColor(rlutil::DARKGREY);
                        }
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }
                }
                else if (y == posy + 5 || y == posy + 6)
                {
                    if (x == posx + 6 || x == posx + 7)
                    {
                        if (color == 1)
                        {
                            rlutil::setColor(rlutil::BLACK);
                        }
                        else
                        {
                            rlutil::setColor(rlutil::DARKGREY);
                        }
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }
                }

            }

        }
        break;

    case 4:
        //Picas
        for (int y = posy; y < posy + 7; y++)
        {
            for (int x = posx; x < posx + 14; x++)
            {
                if (y == posy || y == posy + 5)
                {
                    if (x > posx + 5 && x < posx + 8)
                    {
                        if (color == 1)
                        {
                            rlutil::setColor(rlutil::BLACK);
                        }
                        else
                        {
                            rlutil::setColor(rlutil::DARKGREY);
                        }
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }

                }
                else if (y == posy + 1)
                {
                    if (x > posx + 3 && x < posx + 10)
                    {
                        if (color == 1)
                        {
                            rlutil::setColor(rlutil::BLACK);
                        }
                        else
                        {
                            rlutil::setColor(rlutil::DARKGREY);
                        }
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }
                }
                else if (y == posy + 2)
                {
                    if (x > posx + 1 && x < posx + 12)
                    {
                        if (color == 1)
                        {
                            rlutil::setColor(rlutil::BLACK);
                        }
                        else
                        {
                            rlutil::setColor(rlutil::DARKGREY);
                        }
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }
                }
                else if (y == posy + 3)
                {
                    if (x >= posx && x < posx + 14)
                    {
                        if (color == 1)
                        {
                            rlutil::setColor(rlutil::BLACK);
                        }
                        else
                        {
                            rlutil::setColor(rlutil::DARKGREY);
                        }
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }
                }
                else if (y == posy + 4)
                {
                    if (x >= posx && x < posx + 4 || x == posx + 6 || x == posx + 7 || x > posx + 9 && x <= posx + 14)
                    {
                        if (color == 1)
                        {
                            rlutil::setColor(rlutil::BLACK);
                        }
                        else
                        {
                            rlutil::setColor(rlutil::DARKGREY);
                        }
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }
                }
                else if (y == posy + 6)
                {
                    if (x >= posx && x < posx + 14)
                    {
                        if (color == 1)
                        {
                            rlutil::setColor(rlutil::BLACK);
                        }
                        else
                        {
                            rlutil::setColor(rlutil::DARKGREY);
                        }
                        rlutil::locate(x, y);
                        cout << (char)219;
                    }
                }
            }
        }
        break;

    default:
        break;
    }
    
}

void mostrarCartasMenu(int opcion)
{
    string Bienvenido[] = { "B", "I", "E", "N", "V", "E", "N", "I" , "D", "O" , "S"};
    string Cartas[] = { "P", "L", "A", "Y" };
    string Estadisticas[] = {"E", "S", "T", "A", "D", "I", "S", "T", "I", "C", "A", "S"};
    string Creditos[] = { "C","R", "E", "D", "I", "T", "O", "S" };
    string Reglas[] = { "R", "E", "G", "L", "A", "S"};
    string Gracias[] = { "G", "R", "A", "C", "I", "A", "S" };
    string Comenzar[] = { "C", "O", "M", "E", "N", "Z", "A", "M", "O", "S"};
    string Resumen[] = { "R" , "E", "S", "U", "M", "E", "N" };
    int rando_Figura;

    switch (opcion)
    {
    case 1:
        //Bienvenidos
        for (int z = 0; z < 2; z++)
        {
            if (z == 0)
            {
                for (int i = 0; i < 110; i += 10)
                {
                    dibujarCartaDadaVuelta(9 + i, 16);
                }
            }
            else
            {
                for (int i = 0; i < 110; i += 10)
                {
                    for (int x = 0; x < 5; x++)
                    {
                        dibujarCarta(Bienvenido[(rand() % 9)], obtenerPalo(rand() % 4), 9 + i, 16);
                        rlutil::msleep(2);
                    }
                    dibujarCarta(Bienvenido[i / 10], obtenerFiguras(rand() % 4), 9 + i, 16);
                    rlutil::msleep(30);
                }
            }
        }
        rlutil::setBackgroundColor(rlutil::BLACK);
        break;
    case 2:
        //SALIR
        for (int z = 0; z < 2; z++)
        {
            if (z == 0)
            {
                for (int i = 0; i < 70; i += 10)
                {
                    dibujarCartaDadaVuelta(29 + i, 16);
                }
            }
            else
            {
                for (int i = 0; i < 70; i += 10)
                {
                    for (int x = 0; x < 5; x++)
                    {
                        dibujarCarta(Gracias[(rand() % 7)], obtenerPalo(rand() % 4), 29 + i, 16);
                        rlutil::msleep(1);
                    }
                    dibujarCarta(Gracias[i / 10], obtenerFiguras(rand() % 4), 29 + i, 16);
                    rlutil::msleep(30);
                }
            }
        }
        rlutil::setBackgroundColor(rlutil::BLACK);
        break;
    case 3:
        //Menu
        dibujarFiguras(rando_Figura = (rand() % 4 + 1), 16, 15, 0);
        dibujarFiguras(rando_Figura = (rand() % 4 + 1), 94, 15, 0);
        for (int z = 0; z < 2; z++)
        {
            if (z == 0)
            {
                for (int i = 0; i < 40; i += 10)
                {
                    dibujarCartaDadaVuelta(43 + i, 12);
                }
            }
            else
            {
                for (int i = 0; i < 40; i += 10)
                {
                    for (int x = 0; x < 2; x++)
                    {
                        dibujarCarta(Cartas[(rand() % 4)], obtenerPalo(rand() % 4), 43 + i, 12);
                        rlutil::msleep(1);
                    }

                    dibujarCarta(Cartas[i / 10], obtenerFiguras(rand() % 4), 43 + i, 12);
                    rlutil::msleep(30);
                }
            }
        }
        rlutil::setBackgroundColor(rlutil::BLACK);
        break;
    case 4:
        //Creditos
        //dibujarFiguras(rando_Figura = (rand() % 4 + 1), 16, 15);
        //dibujarFiguras(rando_Figura = (rand() % 4 + 1), 94, 15);
        for (int z = 0; z < 2; z++)
        {
            if (z == 0)
            {
                for (int i = 0; i < 80; i += 10)
                {
                    dibujarCartaDadaVuelta(25 + i, 12);
                }
            }
            else
            {
                for (int i = 0; i < 80; i += 10)
                {
                    for (int x = 0; x < 2; x++)
                    {
                        dibujarCarta(Creditos[(rand() % 6)], obtenerPalo(rand() % 4), 25 + i, 12);
                        rlutil::msleep(1);
                    }

                    dibujarCarta(Creditos[i / 10], obtenerFiguras(rand() % 4), 25 + i, 12);
                    rlutil::msleep(30);
                }
            }
        }
        rlutil::setBackgroundColor(rlutil::BLACK);
        break;
    case 5:
        //Reglas
        //dibujarFiguras(rando_Figura = (rand() % 4 + 1), 16, 15);
        //dibujarFiguras(rando_Figura = (rand() % 4 + 1), 94, 15);
        for (int z = 0; z < 2; z++)
        {
            if (z == 0)
            {
                for (int i = 0; i < 60; i += 10)
                {
                    dibujarCartaDadaVuelta(34 + i, 12);
                }
            }
            else
            {
                for (int i = 0; i < 60; i += 10)
                {
                    for (int x = 0; x < 2; x++)
                    {
                        dibujarCarta(Reglas[(rand() % 6)], obtenerPalo(rand() % 4), 34 + i, 12);
                        rlutil::msleep(1);
                    }

                    dibujarCarta(Reglas[i / 10], obtenerFiguras(rand() % 4), 34 + i, 12);
                    rlutil::msleep(30);
                }
            }
        }
        rlutil::setBackgroundColor(rlutil::BLACK);
        break;
    case 6:
        //Estadisticas
        for (int z = 0; z < 2; z++)
        {
            if (z == 0)
            {
                for (int i = 0; i < 108; i += 9)
                {
                    dibujarCartaDadaVuelta(10 + i, 12);
                }
            }
            else
            {
                for (int i = 0; i < 108; i += 9)
                {
                    for (int x = 0; x < 5; x++)
                    {
                        dibujarCarta(Estadisticas[(rand() % 9)], obtenerPalo(rand() % 4), 10 + i, 12);
                        rlutil::msleep(1);
                    }
                    dibujarCarta(Estadisticas[i / 9], obtenerFiguras(rand() % 4), 10 + i, 12);
                    rlutil::msleep(15);
                }
            }
        }
        rlutil::setBackgroundColor(rlutil::BLACK);
        break;
    case 7:
        //Menu Nombres
        dibujarFiguras(1, 6, 12, 1);
        dibujarFiguras(4, 106, 12, 1);
        dibujarFiguras(3, 6, 22, 1);
        dibujarFiguras(2, 106, 22, 1);

        for (int i = 0; i < 110; i += 11)
        {
            dibujarCarta(Comenzar[(rand() % 9)], 3, 10 + i, 5);
            dibujarCarta(Comenzar[i / 11], 3, 10 + i, 5);
        }

        rlutil::setBackgroundColor(rlutil::GREEN);
        rlutil::setColor(rlutil::WHITE);
        break;
    case 8:
        //Resumen
        for (int z = 0; z < 2; z++)
        {
            if (z == 0)
            {
                for (int i = 0; i < 70; i += 10)
                {
                    dibujarCartaDadaVuelta(29 + i, 12);
                }
            }
            else
            {
                for (int i = 0; i < 70; i += 10)
                {
                    for (int x = 0; x < 5; x++)
                    {
                        dibujarCarta(Resumen[(rand() % 7)], obtenerPalo(rand() % 4), 29 + i, 12);
                        rlutil::msleep(1);
                    }
                    dibujarCarta(Resumen[i / 10], obtenerFiguras(rand() % 4), 29 + i, 12);
                    rlutil::msleep(30);
                }
            }
        }
        rlutil::setBackgroundColor(rlutil::BLACK);
        break;

    default:
        break;
    }

}

void dibujarReactanguloCartas(int posx, int posy, int ancho, int alto, char fondo)
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

void dibujarCartaDadaVuelta(int posx, int posy)
{
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::LIGHTRED);
    dibujarReactanguloCartas(posx, posy, 7, 5, 206);
}

void dibujarCarta(string numero, char figura, int posx, int posy)
{
    rlutil::setColor(rlutil::WHITE);
    dibujarReactanguloCartas(posx, posy, 7, 5);


    if (figura == 3 || figura == 4)
    {
        rlutil::setColor(rlutil::RED);
    }
    else
    {
        rlutil::setColor(rlutil::BLACK);
    }

    rlutil::setBackgroundColor(rlutil::WHITE);
    dibujarNumeroCarta(numero, posx, posy);
    rlutil::locate(posx + 3, posy + 2);
    cout << figura;

}

void dibujarNumeroCarta(string numero, int posx, int posy)
{
    rlutil::locate(posx, posy);
    cout << numero;

    rlutil::locate(posx + 7 - numero.size(), posy + 4);
    cout << numero;

}

string obtenerNumerosCartas(int numero)
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

char obtenerFiguras(int numero)
{
    char palos[] = { 3, 4, 5, 6 };

    return palos[numero];
}

void dibujarTextosCentrados(string texto, int posicion_y) 
{

    int posicion_x = rlutil::tcols() / 2 - texto.size() / 2;

    rlutil::locate(posicion_x, posicion_y);
    cout << texto;
}