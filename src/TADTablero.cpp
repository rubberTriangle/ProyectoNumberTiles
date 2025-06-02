/*
 * TADTablero.cpp
 *
 *  Created on: 25 nov 2024
 *      Author: jorge
 */

#include "entorno.h"
#include "TADCasilla.h"
#include "TADTablero.h"

#include <fstream>
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

void iniciarTablero (Tablero &t, int filas, int columnas, int filasIniciales, int comoIniciar, int m[FILAS][COL]){

	int valor;
	t.filas = filas;
	t.columnas = columnas;

	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
			if (i < filasIniciales){
				if (comoIniciar==0){
					ponerValorCasilla(t.vector[i][j], m[i][j]);
				}else{
					valor = pow(2, rand()%comoIniciar+1);
					ponerValorCasilla(t.vector[i][j], valor);
				}
			}else{
				crearCasilla(t.vector[i][j]);
			}
		}
	}
}

void ponerValorTablero(Tablero &t, int fila, int columna, int valor){
	ponerValorCasilla(t.vector[fila][columna], valor);

}

int obtenerValorTablero(Tablero &t, int fila, int columna){
	return obtenerValorCasilla(t.vector[fila][columna]);
}

bool estaVaciaCasillaTablero(Tablero &t, int fila, int columna){
	return estaVaciaCasilla(t.vector[fila][columna]);
}

void vaciarCasillaTablero(Tablero &t, int fila, int columna){
	vaciarCasilla(t.vector[fila][columna]);
}

bool estaLlenaColumnaTablero(Tablero &t, int columna){
	return !estaVaciaCasillaTablero(t, t.filas-1, columna);
}

int obtenerPosicionVaciaColumnaTablero(Tablero &t, int columna){

	bool enc = false;
	int i = 0;

	while (!enc && i < obtenerNumFilas(t)){
		if (!estaVaciaCasillaTablero(t, i, columna)){
			i++;
		}else{
			enc = true;
		}
	}

	return i;
}

bool estaLlenoTablero(Tablero &t){

	bool lleno = true;
	int i = 0;

	while(lleno && i < t.columnas){
		if(!estaLlenaColumnaTablero(t, i)){
			lleno = false;
		}

		i++;
	}

	return lleno;
}

int obtenerNumFilas(Tablero &t){
	return t.filas;
}

int obtenerNumColumnas(Tablero &t){
	return t.columnas;
}

int obtenerValorMaximoTablero(Tablero t, int &exponente){

	int valorMaximo = 0;

	for (int i = 0; i < obtenerNumFilas(t); i++){
		for (int j = 0; j < obtenerNumColumnas(t); j++){
			if (obtenerValorTablero(t, i, j) > valorMaximo){
				valorMaximo = obtenerValorTablero(t, i, j);
			}
		}
	}

	int calcExp = valorMaximo;
	int i = 1;

	while (calcExp/2 != 1){
		i++;
		calcExp = calcExp/2;
	}

	exponente = i;

	return valorMaximo;
}

void rellenarHuecos(Tablero &t){

	int pos;

	for(int i = 0; i < obtenerNumColumnas(t); i++){

		pos = obtenerPosicionVaciaColumnaTablero(t, i);

		for (int j = pos; j < obtenerNumFilas(t) - 1; j++){

			if (obtenerValorTablero(t, j + 1, i) != 0){

				ponerValorTablero(t, j, i, obtenerValorTablero(t, j + 1, i));
				vaciarCasillaTablero(t, j + 1, i);
			}
		}
	}
}

void fusionar(Tablero &t, int &fila, int columna, int valor, int &puntuacion){
	int cont = 1;
	bool debajo = false;
	bool fusion = false;

	if (obtenerValorTablero(t, fila, columna - 1) == valor){
		fusionar2(t, fila, columna - 1, valor, false, true, false, cont);
		vaciarCasillaTablero(t, fila, columna - 1);
		fusion = true;
		cont++;
	}

	if (obtenerValorTablero(t, fila, columna + 1) == valor){
		fusionar2(t, fila, columna + 1, valor, true, false, false, cont);
		vaciarCasillaTablero(t, fila, columna + 1);
		fusion = true;
		cont++;
	}

	if (obtenerValorTablero(t, fila - 1, columna) == valor){
		debajo = true;
		fusionar2(t, fila - 1, columna, valor, false, false, true, cont);
		vaciarCasillaTablero(t, fila, columna);
		cont++;
		fusion = true;

		puntuacion = puntuacion + valor * cont - valor/cont;

		if (cont % 2 == 1){
			cont++;
		}

		valor = valor * cont;

		bool enc = false;

		int i = 2;

		while(!enc){
			if(i >= valor){
				enc = true;
			}else{
				i = i * 2;
			}
		}

		valor = i;

		fila--;

		ponerValorTablero(t, fila, columna, valor);
	}

	if (!debajo && cont != 1){

		puntuacion = puntuacion + valor * cont - valor/cont;

		if (cont % 2 == 1){
			cont++;
		}

		valor = valor * cont;

		bool enc = false;

		int i = 2;

		while(!enc){
			if(i >= valor){
				enc = true;
			}else{
				i = i * 2;
			}
		}

		valor = i;


		ponerValorTablero(t, fila, columna, valor);
	}

	rellenarHuecos(t);

	if (fusion){
		fusionar(t, fila, columna, valor, puntuacion);
	}
}

void fusionar2(Tablero &t, int fila, int columna, int valor, bool derecha, bool izquierda, bool debajo, int &cont){

	if (obtenerValorTablero(t, fila, columna - 1) == valor && (izquierda || debajo)){
		vaciarCasillaTablero(t, fila, columna - 1);
		cont++;
	}

	if (obtenerValorTablero(t, fila, columna + 1) == valor && (derecha || debajo)){
		vaciarCasillaTablero(t, fila, columna + 1);
		cont++;
	}

	if (obtenerValorTablero(t, fila - 1, columna) == valor && (fila - 1) >= 0){
		vaciarCasillaTablero(t, fila - 1, columna);
		cont++;
	}

	if (obtenerValorTablero(t, fila + 1, columna) == valor && (derecha || izquierda) && !debajo && (fila + 1) < obtenerNumFilas(t)){
		vaciarCasillaTablero(t, fila + 1, columna);
		cont++;
	}
}

int pista(Tablero t, int valor){
	int mejorOpcion = -1;
	int columnas = obtenerNumColumnas(t);
	int cont = 0;
	int mejorCont = 0;

	for (int i = 0; i < columnas; i++){
		cont = 0;

		int fila = obtenerPosicionVaciaColumnaTablero(t, i);
		if (fila < obtenerNumFilas(t)){

			if (obtenerValorTablero(t, fila, i - 1) == valor){
				pista2(t, fila, i - 1, valor, false, true, false, cont);
				cont++;
			}

			if (obtenerValorTablero(t, fila, i + 1) == valor){
				pista2(t, fila, i + 1, valor, true, false, false, cont);
				cont++;
			}

			if (obtenerValorTablero(t, fila - 1, i) == valor){
				fila--;
				pista2(t, fila - 1, i, valor, false, false, true, cont);
				cont++;
			}

			if (mejorCont <= cont && cont != 0){
				mejorCont = cont;
				mejorOpcion = i;
			}
		}
	}
	return mejorOpcion;
}

void pista2(Tablero t, int fila, int columna, int valor, bool derecha, bool izquierda, bool debajo, int &cont){

	if (obtenerValorTablero(t, fila, columna - 1) == valor && (izquierda || debajo)){
		cont++;
	}

	if (obtenerValorTablero(t, fila, columna + 1) == valor && (derecha || debajo)){
		cont++;
	}

	if (obtenerValorTablero(t, fila - 1, columna) == valor && (fila - 1) > 0){
		cont++;
	}

	if (obtenerValorTablero(t, fila + 1, columna) == valor && !debajo){
		cont++;
	}
}
