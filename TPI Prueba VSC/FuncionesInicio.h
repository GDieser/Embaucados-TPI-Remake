#pragma once


using namespace std;

void iniciarPresentacion();

void presentarLogo();

void mostrarLogoEmbaucado(int opcion);

void finalizarPresentacion();

void recuadro(int tipo);

void dibujarFiguras(int figura, int posx, int posy, int color);

void mostrarCartasMenu(int opcion);

void dibujarReactanguloCartas(int posx, int posy, int ancho, int alto, char fondo = 217);

void dibujarCartaDadaVuelta(int posx, int posy);

void dibujarCarta(string numero, char figura, int posx, int posy);

void dibujarNumeroCarta(string numero, int posx, int posy);

string obtenerNumerosCartas(int numero);

char obtenerFiguras(int numero);


//Practica de Cartas

void tiradaDeCartas();

void dibujarReactangulo(int posx, int posy, int ancho, int alto, char fondo = 217);

void dibujarReversoCarta(int posx, int posy);

void dibujarCartas(string numero, char figura, int posx, int posy);

void dibujarNumero(string numero, int posx, int posy);

string obtenerNumeroCarta(int numero);

char obtenerPalo(int numero);

