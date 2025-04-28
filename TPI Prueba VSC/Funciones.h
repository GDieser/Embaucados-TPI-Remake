#pragma once
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

using namespace std;


void registarNombresJugadores(std::string& player1, std::string& player2, std::string nombrePuntajeMaximo[], int TAM_P, int puntajeMaximo[], int TAM_M);

void confirmarNombres(const char* text, int posicion_x, int posicion_y, bool selecion);

void comenzarJuego(std::string& player1, std::string& player2, std::string nombrePuntajeMaximo[], int TAM_P, int puntajeMaximo[], int TAM_M);

void randomizarCartasParaPlayers(int figura_ActualP1[], int TAM_P1, string naipe_ActualP1[], int TAM_N1, int figura_ActualP2[], int TAM_P2, string naipe_ActualP2[], int TAM_N2);

int randomizarCartaEmbaucadora();

int calcularPuntajesPlayers(string player, int& puntosPlayer, string naipe_ActualP[], int TAM_N, int  figura_ActualP[], int TAM_A, int embaucadora);

void mostrarPuntajesPlayers(string player, int& puntosPlayer, string naipe_ActualP[], int TAM_N, int figura_ActualP[], int TAM_A, int embaucadora);

void finalizarJuegoYMostrarEstadisticas(string player1, string player2, int puntosPorRondaP1[], int TAM_R1, int puntosPorRondaP2[], int TAM_R, int puntosPlayer1, int puntosPlayer2, string nombrePuntajeMaximo[], int TAM_P, int puntajeMaximo[], int TAM_M);

void desempatarPlayers(string player1, string player2, int puntosPlayer1, int puntosPlayer2, string nombrePuntajeMaximo[], int TAM_P, int puntajeMaximo[], int TAM_M);

void dibujarTextosCentrados(string texto, int posicion_y);

void pintarLineas(int posicion_x, int posicion_y);


#endif 
