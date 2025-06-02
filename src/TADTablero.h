/*
 * TADTablero.h
 *
 *  Created on: 25 nov 2024
 *      Author: jorge
 */

#ifndef TADTABLERO_H_
#define TADTABLERO_H_

#include "TADCasilla.h"
#include "TADCasilla.h"
#include "TADTablero.h"

const int COL = 7;
const int FILAS = 7;

typedef Casilla TVector[FILAS][COL];

struct Tablero{
	TVector vector;
	int filas;
	int columnas;

};


//PRE={tablero, 3 <= filas < 7, 3 <= columnas < 7, 0 <= filasIniciales < filas, comoIniciar >= 0}
//POST={crea un tablero de tamaño filas por columnas y las casillas en las filas iniciales tendran un valor de potencias de dos elevadas desde 1 hasta comoIniciar si es distinto de 0 o el valor que viene en el fichero si comoIniciar es 0}
//COMPLEJIDAD: O(n²)
void iniciarTablero (Tablero &t, int filas, int columnas, int filasIniciales, int comoIniciar, int m[FILAS][COL]);


//PRE={tablero, 0 <= fila < 7, 0 <= columna < 7, valor 2 elevado}
//POST={pone el valor en la casilla situada en cierta fila y columna}
//COMPLEJIDAD: O(1)
void ponerValorTablero(Tablero &t, int fila, int columna, int valor);


//PRE={tablero, 0 <= fila < 7, 0 <= columna < 7}
//POST={devuelve el valor en la casilla situada en esa fila y columna en ese tablero}
//COMPLEJIDAD: O(1)
int obtenerValorTablero(Tablero &t, int fila, int columna);


//PRE={tablero, 0 <= fila < 7, 0 <= columna < 7}
//POST={devuelve si la casilla situada en esa fila y columna de ese tablero esta vacia}
//COMPLEJIDAD: O(1)
bool estaVaciaCasillaTablero(Tablero &t, int fila, int columna);


//PRE={tablero, 0 <= fila < 7, 0 <= columna < 7}
//POST={vacia la casilla del tablero situada en esa fila y columna}
//COMPLEJIDAD: O(1)
void vaciarCasillaTablero(Tablero &t, int fila, int columna);


//PRE={tablero, 0 <= columna < 7}
//POST={devuelve si esta llena la columna del tablero}
//COMPLEJIDAD: O(1)
bool estaLlenaColumnaTablero(Tablero &t, int columna);


//PRE={tablero, 3 <= columna < 7}
//POST={devuelve la fila de la primera casilla vacia}
//COMPLEJIDAD: O(n)
int obtenerPosicionVaciaColumnaTablero(Tablero &t, int columna);


//PRE={tablero}
//POST={devuelve si el tablero esta lleno}
//COMPLEJIDAD: O(n)
bool estaLlenoTablero(Tablero &t);


//PRE={tablero}
//POST={devuelve el numero de filas del tablero}
//COMPLEJIDAD: O(1)
int obtenerNumFilas(Tablero &t);


//PRE={tablero}
//POST={devuelve el numero de columnas del tablero}
//COMPLEJIDAD: O(1)
int obtenerNumColumnas(Tablero &t);

//PRE={tablero, exponente cualquier valor}
//POST={devuelve el valor máximo en el tablero y su exponente en forma de potencia de 2}
//COMPLEJIDAD: O(n³)
int obtenerValorMaximoTablero(Tablero t, int &exponente);

//PRE={tablero}
//POST={sube las casillas ocupando los huecos libres del tablero}
//COMPLEJIDAD: O(n²)
void rellenarHuecos(Tablero &t);

//PRE={tablero, 0 <= fila < 7, 0 <= columna < 7, 2 <= valor < 4096, 0 <= puntuacion}
//POST={modifica el contador segun el numero de casillas que se fusionan y las vacia}
//COMPLEJIDAD: O(n²)
void fusionar(Tablero &t, int &fila, int columna, int valor, int &puntuacion);

//PRE={tablero, 0 <= fila < 7, 0 <= columna < 7, 2 <= valor < 4096, derecha, izquierda, debajo, 1 <= cont}
//POST={modifica el contador segun el numero de casillas que se fusionan y las vacia}
//COMPLEJIDAD: O(1)
void fusionar2(Tablero &t, int fila, int columna, int valor, bool derecha, bool izquierda, bool debajo, int &cont);

//PRE={tablero, 0 <= valor < 4096}
//POST={hace una simulacion de fusionar pero sin vaciar las casillas para saber la mejor opcion}
//COMPLEJIDAD: O(n²)
int pista(Tablero t, int valor);

//PRE={tablero, 0 <= fila <= 7, 0 <= columna <= 7, 0 <= valor < 4096, derecha, izquierda, debajo, 1 <= cont}
//POST={hace una simulacion de fusionar2 pero sin vaciar las casillas para saber la mejor opcion}
//COMPLEJIDAD: O(1)
void pista2(Tablero t, int fila, int columna, int valor, bool derecha, bool izquierda, bool debajo, int &cont);

#endif /* TADTABLERO_H_ */
