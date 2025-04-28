#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>

#include "rlutil.h"
#include "Funciones.h"
#include "FuncionesInicio.h"
#include "FuncionesMenu.h"

//Para Musica
#pragma comment(lib, "winmm.lib")
//Para tamaño
HANDLE wHnd;

#include <thread>  
#include <chrono>   

using namespace std;


int main()
{
    HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);

    // Tam de ventana
    COORD bufferSize = { 125, 40 };
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    SMALL_RECT windowSize = { 0, 0, 124, 39 };
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);

    // bloquea
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE,
        GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

    // Nombre de la ventana
    SetConsoleTitle(TEXT("Embaucado2: Remake"));
    
    srand(time(0));
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::hidecursor();

    int const TAM = 3;
    int puntajeMaximo[TAM] = {};
    string nombrePuntajeMaximo[TAM] = {}, player1, player2;
    char opcion;

    iniciarPresentacion();
    mostrarMenuEmbaucado(player1, player2, nombrePuntajeMaximo, TAM, puntajeMaximo, TAM);
    finalizarPresentacion();

    return 0;
}

    


